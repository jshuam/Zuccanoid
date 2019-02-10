#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 velocity, Color color, int radius);
	Vec2& GetPos();
	Rect& GetRect();
	void Draw(Graphics& gfx) const;
	void Move(float deltaTime, const Rect &bounds);

private:
	Vec2 pos;
	Vec2 velocity;
	Color color;
	int radius;

private:
	void CheckCollisionWall(const Rect &bounds);
};