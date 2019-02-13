#pragma once

#include "Colors.h"
#include "Keyboard.h"
#include "Rect.h"
#include "Graphics.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(Color mainColor, Color sideColor);
	void Move(const Keyboard& keyboard, float deltaTime);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(Ball& ball) const;

private:
	static constexpr int offset = 5;
	static constexpr int width = 100;
	static constexpr int height = 30;
	static constexpr float speed = 500.0f;

	Rect rect;
	Color mainColor;
	Color sideColor;
};