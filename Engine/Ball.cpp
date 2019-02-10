#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 velocity, Color color, int radius)
{
	this->pos = pos;
	this->velocity = velocity;
	this->color = color;
	this->radius = radius;
}

Vec2& Ball::GetPos()
{
	return pos;
}

Rect& Ball::GetRect()
{
	return Rect(pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawCircle(pos.x, pos.y, radius, color);
}

void Ball::Move(float deltaTime, const Rect &bounds)
{
	pos += velocity * deltaTime;

	CheckCollisionWall(bounds);
}

void Ball::CheckCollisionWall(const Rect &bounds)
{
	Rect rect = GetRect();

	if(rect.left <= bounds.left)
	{
		velocity.x = -velocity.x;
		pos.x -= rect.left;
	}
	if(rect.top <= bounds.top)
	{
		velocity.y = -velocity.y;
		pos.y -= rect.top;
	}
	if(rect.right >= bounds.right)
	{
		velocity.x = -velocity.x;
		pos.x += bounds.right - rect.right;
	}
	if(rect.bottom >= bounds.bottom)
	{
		velocity.y = -velocity.y;
		pos.y += bounds.bottom - rect.bottom;
	}
}
