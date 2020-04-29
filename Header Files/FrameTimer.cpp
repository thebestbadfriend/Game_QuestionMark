#include "FrameTimer.h"
#include <iostream>

using namespace std::chrono;

FrameTimer::FrameTimer()
	:last(steady_clock::now())
{
}

float FrameTimer::Mark()
{
	auto old = last;
	last = steady_clock::now();
	const duration<float> duration = last - old;
	return duration.count();
}
