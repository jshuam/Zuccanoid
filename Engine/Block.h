#pragma once

#include "Rect.h"
#include "Graphics.h"

class Block
{
public:
	Block() = default;
	Block(Rect rect, Color color);
	void Draw(Graphics& gfx) const;

	Rect GetRect() const;

private:
	Rect rect;
	Color color;
	bool destroyed = false;
};