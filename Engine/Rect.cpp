#include "Rect.h"

Rect::Rect(float left, float top, float right, float bottom)
	:
	left(left),
	top(top),
	right(right),
	bottom(bottom)
{
}

Rect::Rect(const Vec2& topLeft, const Vec2& topRight)
	:
	Rect(topLeft.x, topLeft.y, topRight.x, topRight.y)
{}

Rect::Rect(const Vec2& topLeft, float width, float height)
	:
	Rect(topLeft.x, topLeft.y, topLeft.x + width, topLeft.y + height)
{}

bool Rect::Collided(const Rect& rect) const
{
	return left <= rect.right && top <= rect.bottom && right >= rect.left && bottom >= rect.top;
}

Rect& Rect::operator-(const int& scalar)
{
	left += scalar;
	top += scalar;
	right -= scalar;
	bottom -= scalar;
	return *this;
}

