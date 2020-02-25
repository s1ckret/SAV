#pragma once

#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	float Mark();
	float GetElapsedTime();
	void Clear();
private:
	std::chrono::high_resolution_clock::time_point last;
	std::chrono::high_resolution_clock::time_point last_clear;
};