#include "Circle.h"

void CIRCLE::Size() {
	answer = radius * radius * 3.14f;
}

void CIRCLE::Draw() {
	printf("円の面積：%0.2f\n", answer);
}