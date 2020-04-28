#include "FrameTimer.h"
#include <iostream>

using namespace std::chrono;

FrameTimer::FrameTimer()
	:last(steady_clock::now())
{
}

FrameTimer::~FrameTimer()
{
}

void FrameTimer::Mark()
{
	auto newTime = steady_clock::now();
	std::chrono::duration<float> duration = newTime - last;
	
	accumulated += duration.count();
	last = newTime;
}

bool FrameTimer::Step()
{
	if (accumulated >= threshold) {
		accumulated -= threshold;
		return true;
	}
	else {
		return false;
	}
}
