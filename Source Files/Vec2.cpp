#include "..\Header Files\Vec2.h"

Vec2::Vec2(float in_x, float in_y)
	:
	x(in_x),
	y(in_y)
{
}

Vec2 Vec2::operator+(const Vec2 rhs)
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2 rhs)
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator*(const float rhs)
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator/(const float rhs)
{
	return Vec2(x / rhs, y / rhs);
}
