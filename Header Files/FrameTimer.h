#pragma once
#include <chrono>

class FrameTimer {
public:
	FrameTimer();

	float Mark(); //returns the time in seconds since the last call to mark

private:
	std::chrono::steady_clock::time_point last;
};