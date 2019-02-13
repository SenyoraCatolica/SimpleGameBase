#include "SimpleTimer.h"

Uint64 SimpleTimer::frequency = 0;

SimpleTimer::SimpleTimer()
{
	if (frequency == 0)
		frequency = SDL_GetPerformanceFrequency();

	Start();
}

void SimpleTimer::Start()
{
	started_at = SDL_GetPerformanceCounter();
}

double SimpleTimer::ReadMs() const
{
	return 1000.0 * (double(SDL_GetPerformanceCounter() - started_at) / double(frequency));
}

Uint64 SimpleTimer::ReadTicks() const
{
	return SDL_GetPerformanceCounter() - started_at;
}