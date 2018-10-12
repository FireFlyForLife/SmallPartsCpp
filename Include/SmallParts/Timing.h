#pragma once

namespace Timing
{
	extern float dtScale;

	void InitTime();
	float TickTimer();

	float DeltaTime();
	double TotalTime();
}
