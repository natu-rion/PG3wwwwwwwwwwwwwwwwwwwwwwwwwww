#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>

using namespace std;

int Recursive(int kyuuryou, int hour, int kotei) {
    if (kyuuryou >= kotei) {
        printf("%d時間後に超える\n", hour);
        return hour;
    }

    printf("時給: %d　基準: %d\n", kyuuryou, kotei);

    // 給料を更新
    kyuuryou = kyuuryou * 2 - 50;

    // 固定値増加
    kotei += 1072;

    // 再帰呼び出し
    return Recursive(kyuuryou, hour + 1, kotei);
}

int main() {
    int kyuuryou = 100;
    int hour = 0;
    int kotei = 1226;

    Recursive(kyuuryou, hour, kotei);

    return 0;
}