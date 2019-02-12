#pragma once

#include "Colors.h"
#include "Keyboard.h"
#include "Rect.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(Rect rect, Color mainColor, Color sideColor);
	void Move(Keyboard& keyboard);

private:
	static constexpr int offset = 5;

	Rect rect;
	Color mainColor;
	Color sideColor;
};