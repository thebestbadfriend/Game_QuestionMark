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

int count = 0;
bool FrameTimer::Step()
{
	if (accumulated >= threshold) {
		count++;
		if (count >= framerate) {
			printf("second\n");
			count = 0;
		}
		accumulated -= threshold;
		return true;
	}
	else {
		return false;
	}
}
