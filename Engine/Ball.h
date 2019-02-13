#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Sound.h"

class Ball
{
public:
	Ball() = default;
	Ball(Vec2 pos, Vec2 velocity, Color color, int radius);
	Vec2& GetPos();
	Rect GetRect();
	Vec2 GetVelocity();
	void Draw(Graphics& gfx) const;
	void Move(float deltaTime, const Rect &bounds);
	void InvertY();
	void InvertX();

private:
	Vec2 pos;
	Vec2 velocity;
	Color color;
	int radius;
	Sound sound;

private:
	void CheckCollisionWall(const Rect& bounds);
};