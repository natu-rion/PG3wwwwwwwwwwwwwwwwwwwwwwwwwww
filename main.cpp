#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<uint32_t> turn = 1;

void PrintThread(uint32_t num) {

    while (turn.load() != num) {
    }

    cout << "thread " << num << endl;
    turn++;
}

int main() {

    // マルチスレッドではある
    thread t1(PrintThread, 1);
    /*スレッドt1開始*/;

    thread t2(PrintThread, 2);
    /*スレッドt2開始*/;

    thread t3(PrintThread, 3);
    /*スレッドt3開始*/;

    t1.join();
    t2.join();
    t3.join();

    return 0;
}