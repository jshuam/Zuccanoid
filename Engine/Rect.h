#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(float left, float top, float right, float bottom);
	Rect(const Vec2& topLeft, const Vec2& topRight);
	Rect(const Vec2& topLeft, float width, float height);
	bool Collided(const Rect& rect) const;
	Rect& operator-(const int& scalar);

public:
	float left;
	float top;
	float right;
	float bottom;
};