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
	gfx.DrawRect(rect, color);
}

Rect Block::GetRect() const
{
	return rect;
}
