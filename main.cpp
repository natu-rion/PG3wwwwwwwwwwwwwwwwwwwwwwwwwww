#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"


int main(void) {

	IShape* shape[2];

	shape[0] = new CIRCLE;
	shape[1] = new SQUARE;

	printf("円の半径:4\n短形の底辺:2\n短形の高さ:3\n");

	//面積を計算
	for (int i = 0; i < 2; i++)
		shape[i]->Size();

	printf("\n");

	//面積を画面に表示
	for (int i = 0; i < 2; i++)
		shape[i]->Draw();

	return 0;
}