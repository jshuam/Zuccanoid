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
	if(!destroyed && rect.Collided(ball.GetRect()))
	{
		return true;
	}
	return false;
}

void Block::CollideWithBall(Ball& ball)
{
	destroyed = true;
	Vec2 ballPos = ball.GetPos();
	if(ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.InvertY();
	}
	else
	{
		ball.InvertX();
	}
}

Rect Block::GetRect() const
{
	return rect;
}
