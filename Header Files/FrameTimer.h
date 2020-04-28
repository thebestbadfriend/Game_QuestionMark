#pragma once
#include <chrono>

class FrameTimer {
public:
	FrameTimer();
	~FrameTimer();

	void Mark(); //adds the time since the last call to Mark() to the timer
	bool Step(); //returns true if it is time to go to the next frame and subtracts the threshold from the timer

private:
	std::chrono::steady_clock::time_point last;
	int framerate = 64;
	float threshold = 1/float(framerate);
	float accumulated = 0;
};