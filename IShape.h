#pragma once
#include <stdio.h>

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
protected:
	const char* name;
	float radius = 4;//半径
	int width = 2;//横幅
	int height = 3;//縦幅
};