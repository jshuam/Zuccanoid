#include "Block.h"

Block::Block(Rect rect, Color color)
{
	this->rect = rect;
	this->color = color;
}

void Block::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, Colors::Blue);
}

Rect Block::GetRect() const
{
	return rect;
}
