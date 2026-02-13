#include "Rectangle.h"
#include <iostream>

void SQUARE::Size() {
	answer = width * height;
}

void SQUARE::Draw() {
	printf("短形の面積：%d\n", answer);
}