#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <fstream>
#include <sstream>
#include <cassert>

#include <unordered_map>

using namespace std;

vector<vector<int>> LoadMapChipCsv(const std::string& filePath) {

	const uint32_t kNumBlockVirtical = 10;
	const uint32_t kNumBlockHorizontal = 50;


	std::unordered_map<std::string, int> mapChipTable = {
		{"0", 0},
		{"1", 1},
	};

	vector<vector<int>> mapChipData(kNumBlockVirtical, vector<int>(kNumBlockHorizontal, 0));

	// ファイルを開く
	std::ifstream file;
	file.open(filePath);
	assert(file.is_open());

	// マップチップCSV
	std::stringstream mapChipCsv;
	// ファイルの内容を文字列ストリームにコピー
	mapChipCsv << file.rdbuf();
	// ファイルを閉じる
	file.close();

	std::string line;

	// CSVからマップチップデータを読み込む
	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {

		getline(mapChipCsv, line);

		// １行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);

		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			std::string word;
			getline(line_stream, word, ',');

			if (mapChipTable.find(word) != mapChipTable.end()) {
				mapChipData[i][j] = mapChipTable[word];
			}
		}
	}

	return mapChipData;
}

void DrawMap(const vector<vector<int>>& map) {

	for (auto& row : map) {
		for (auto v : row) {

			switch (v) {
			case 0: cout << "  "; break;  // 空
			case 1: cout << " #"; break;  // 壁
			}
		}
		cout << endl;
	}
}


int main() {
	std::mutex mutex;
	std::condition_variable condition;
	std::queue<int> q;
	bool exit = false;


	//バックグラウンドループ
	std::thread th([&]() {
		while (true) {


			std::unique_lock<std::mutex> uniqueLock(mutex);

			// 仕事が来るまで待つ
			condition.wait(uniqueLock, [&]() {return !q.empty() || exit; });

			if (exit && q.empty()) break;

			q.pop(); // 仕事を取り出す
			uniqueLock.unlock();

			auto map = LoadMapChipCsv("mapChip.csv");
			DrawMap(map);
		}
		});

	//メインループ


	{
		std::lock_guard<std::mutex> lock(mutex);
		q.push(1);          // 仕事を投げる
		condition.notify_one();  // ワーカーを起こす
	}

	while (true) {
		std::lock_guard<std::mutex> lock(mutex);
		if (q.empty()) break;  // キューが空になったら終了
		// キューが空になるまで小休止
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}





	exit = true;
	th.join();
	return 0;
}