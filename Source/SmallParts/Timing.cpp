#include <SmallParts/Timing.h>
#include <chrono>

namespace Timing
{
	static double startTime = 0;
	static double lastTotalTime = 0;
	static float deltaTime;
	float dtScale = 1.f;//0.2f;

	static double getCurrentRuntime()
	{
		auto current_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::ratio<1, 1>> delta_duration = current_time.time_since_epoch();
		return delta_duration.count() - startTime;
	}

	void InitTime()
	{
		//startTime is 0 here
		startTime = getCurrentRuntime();
		//startTime is now set to the current time
		lastTotalTime = getCurrentRuntime();
	}

	float TickTimer()
	{
		double now = getCurrentRuntime();
		deltaTime = static_cast<float>(now - lastTotalTime);
		lastTotalTime = now;

		return deltaTime * dtScale;
	}

	float DeltaTime()
	{
		return deltaTime * dtScale;
	}

	double TotalTime()
	{
		return lastTotalTime;
	}
}
