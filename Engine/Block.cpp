#include "Block.h"

Block::Block(Rect rect, Color color)
	:
	rect(rect),
	color(color)
{}

void Block::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}

Rect Block::GetRect() const
{
	return rect;
}
