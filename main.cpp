#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

int main() {


	// 山手線の駅名を双方向リストに格納
	list<const char*> yamanote = {
		"shinagawa", "osaki", "gotanda", "meguro", "ebisu", "shibuya", "harajuku",
		"yoyogi", "shinjuku", "shin-okubo", "takadanobaba", "mejiro", "ikebukuro",
		"otsuka", "sugamo", "komagome", "tabata", "nippori", "uguisudani",
		"ueno", "okachimachi", "akihabara", "kanda", "tokyo", "yurakucho", "shimbashi",
		"hamamatsucho", "tamachi"
	};


	//双方向リスト
	cout << "1970年" << endl;
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		cout << *itr << ",";
	}

	cout << endl; // ★ここで改行

	// 「nippori」の前に「nishi-nippori」を追加
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		if (string(*itr) == "tabata") {
			yamanote.insert(itr, "nishi-nippori");
			break; // 1回だけでOKなので抜ける
		}
	}



	//双方向リスト
	cout << "2019年" << endl;
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		cout << *itr << ",";
	}

	cout << endl; // ★ここで改行

	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		if (string(*itr) == "tamachi") {
			yamanote.insert(itr, "takanawa-gateway");
			break; // 1回だけでOKなので抜ける
		}
	}

	//双方向リスト
	cout << "令和5年" << endl;
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		cout << *itr << ",";
	}

	cout << endl; // ★ここで改行

	return 0;
}