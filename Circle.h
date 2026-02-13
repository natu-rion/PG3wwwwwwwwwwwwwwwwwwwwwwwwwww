#pragma once
#include "IShape.h"

#pragma once

#include "IShape.h"

class CIRCLE : public IShape {
public:
	void Size()override;
	void Draw()override;
private:
	float answer = 0;
};