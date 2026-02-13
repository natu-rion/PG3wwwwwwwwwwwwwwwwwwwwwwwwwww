#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>


using namespace std;

int calc(int a, int b) {
	return a + b;
}

float calc(float d, float e) {
	return d + e + 10;
}

template <typename Type>

Type add(Type a, Type b) {
	return static_cast<Type>(a + b);
}

template <typename Type>

Type Min(Type a, Type b) {
	if (a > b) {
		return static_cast<Type>(b);
	} else {
		return static_cast<Type>(a);
	}
}

int main() {

	//計算と結果出力
	printf("%d\n", Min<int>(128, 256));
	printf("%f\n", Min<float>(52.5f, 55.0f));
	printf("%lf\n", Min<double>(3.14159265, 2.7182818281));

	return 0;
}