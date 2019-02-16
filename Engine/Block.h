#pragma once

#include "Ball.h"
#include "Rect.h"
#include "Graphics.h"
#include <assert.h>

class Block
{
public:
	Block() = default;
	Block(Rect rect, Color color);
	Block(Rect rect, Color color, const int& offset);

	void Draw(Graphics& gfx) const;

	bool CheckBallCollision(Ball& ball);

	Rect GetRect() const;
	Vec2 GetCenter() const;
	void CollideWithBall(Ball& ball);

private:
	Rect rect;
	Color color;
	bool destroyed = false;
};