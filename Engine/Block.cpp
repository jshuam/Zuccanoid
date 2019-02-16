#include "Block.h"

Block::Block(Rect rect, Color color)
	:
	rect(rect),
	color(color)
{}

Block::Block(Rect rect, Color color, const int& offset)
	:
	Block(rect - offset, color)
{}

void Block::Draw(Graphics& gfx) const
{
	if (!destroyed) gfx.DrawRect(rect, color);
}

bool Block::CheckBallCollision(Ball& ball)
{
	return !destroyed && rect.Collided(ball.GetRect());
}

void Block::CollideWithBall(Ball& ball)
{
	assert(CheckBallCollision(ball));

	const Vec2 ballPos = ball.GetPos();

	if(std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.InvertY();
	}
	else if(ballPos.x >= rect.left && ballPos.x <= rect.right )
	{
		ball.InvertY();
	}
	else
	{
		ball.InvertX();
	}

	destroyed = true;
}

Rect Block::GetRect() const
{
	return rect;
}

Vec2 Block::GetCenter() const
{
	return rect.GetCenter();
}
