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
		destroyed = true;
		ball.InvertY();
		return true;
	}

	return false;
}

Rect Block::GetRect() const
{
	return rect;
}
