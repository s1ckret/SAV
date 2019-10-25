#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::high_resolution_clock::now();
	last_clear = std::chrono::high_resolution_clock::now();
}

float FrameTimer::Mark()
{
	const auto old = last;
	last = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float FrameTimer::GetElapsedTime()
{
	const auto now = std::chrono::high_resolution_clock::now();
	const std::chrono::duration<float> elapsedTime = now - last_clear;
	return elapsedTime.count();
}

void FrameTimer::Clear()
{
	last_clear = std::chrono::high_resolution_clock::now();
}