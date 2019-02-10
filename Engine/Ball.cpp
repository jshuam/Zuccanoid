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

	CheckCollisionWall(deltaTime, bounds);
}

void Ball::CheckCollisionWall(float deltaTime, const Rect &bounds)
{
	if(GetRect().left <= bounds.left)
	{
		velocity.x = fabs(velocity.x);
		pos.x += velocity.x * deltaTime;
	}
	if(GetRect().top <= bounds.top)
	{
		velocity.y = fabs(velocity.y);
		pos.y += velocity.y * deltaTime;
	}
	if(GetRect().right >= bounds.right)
	{
		velocity.x = -velocity.x;
		pos.x += velocity.x * deltaTime;
	}
	if(GetRect().bottom >= bounds.bottom)
	{
		velocity.y = -velocity.y;
		pos.y += velocity.y * deltaTime;
	}
}
