#include "Paddle.h"

Paddle::Paddle(Color mainColor, Color sideColor)
	:
	rect((Graphics::ScreenWidth / 2) - (width / 2),
		 (Graphics::ScreenHeight / 2) - (height/2) + (height * 7),
		 (Graphics::ScreenWidth / 2) - (width / 2) + width,
		 (Graphics::ScreenHeight / 2) - (height / 2) + (height * 8)),
	mainColor(mainColor),
	sideColor(sideColor)
{}

void Paddle::Move(const Keyboard& keyboard, float deltaTime)
{
	if(keyboard.KeyIsPressed(VK_LEFT))
	{
		rect.left -= speed * deltaTime;
		rect.right -= speed * deltaTime;

		if(rect.left <= 0)
		{
			rect.left += speed * deltaTime;
			rect.right += speed * deltaTime;
		}
	}
	else if(keyboard.KeyIsPressed(VK_RIGHT))
	{
		rect.left += speed * deltaTime;
		rect.right += speed * deltaTime;

		if(rect.right >= Graphics::ScreenWidth)
		{
			rect.left -= speed * deltaTime;
			rect.right -= speed * deltaTime;
		}
	}
}

void Paddle::Draw(Graphics& gfx) const
{
	Rect tmpRect = rect;
	gfx.DrawRect(tmpRect, sideColor);
	tmpRect.left += offset;
	tmpRect.right -= offset;
	gfx.DrawRect(tmpRect, mainColor);
}

bool Paddle::CheckBallCollision(Ball & ball) const
{
	bool collided = false;
	if(ball.GetVelocity().y > 0.0f && rect.Collided(ball.GetRect()))
	{
		ball.InvertY();
		collided = true;
	}

	return collided;
}
