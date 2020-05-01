#pragma once

struct Vec2 {
	float x;
	float y;

	Vec2() = default;
	Vec2(float in_x, float in_y);

	Vec2 operator+(const Vec2 rhs);
	Vec2 operator-(const Vec2 rhs);
	Vec2 operator*(const float rhs);
	Vec2 operator/(const float rhs);
};