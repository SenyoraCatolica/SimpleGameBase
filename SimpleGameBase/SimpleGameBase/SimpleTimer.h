#pragma once

#include "SDL2-2.0.9/include/SDL_timer.h"

class SimpleTimer
{
public:

	SimpleTimer();

	void Start();

	double ReadMs() const;
	Uint64 ReadTicks() const;

private:

	Uint64 started_at;
	static Uint64 frequency;
};
