#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 velocity, Color color, int radius)
	:
	pos(pos),
	velocity(velocity),
	color(color),
	radius(radius),
	sound(L"Sounds//arkpad.wav")
{}

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
	bool collided = false;
	Rect rect = GetRect();

	if(rect.left <= bounds.left)
	{
		velocity.x = -velocity.x;
		pos.x -= rect.left;
		collided = true;
	}
	if(rect.top <= bounds.top)
	{
		velocity.y = -velocity.y;
		pos.y -= rect.top;
		collided = true;
	}
	if(rect.right >= bounds.right)
	{
		velocity.x = -velocity.x;
		pos.x += bounds.right - rect.right;
		collided = true;
	}
	if(rect.bottom >= bounds.bottom)
	{
		velocity.y = -velocity.y;
		pos.y += bounds.bottom - rect.bottom;
		collided = true;
	}

	if(collided) sound.Play();
}
