#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>

using namespace std;


typedef void(*PFunc)(int);

// サイコロの出目を決定する関数
int roll_dice() {
    return rand() % 6 + 1;
}


// 判定を行うコールバック関数
void judge_result(int result) {

    int input;

    printf("サイコロの出目が奇数(1)か偶数(2)か入力:");
    scanf_s("%d", &input);

    printf("判定中...\n");

    Sleep(3000);

    if ((result % 2 == 1 && input == 1) || (result % 2 == 0 && input == 2)) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }

    printf("サイコロの目は%d\n", result);
}


int main(void) {

    srand((int)time(NULL));

    int dice_result = roll_dice();

    PFunc callback = judge_result;

    callback(dice_result);


    return 0;
}