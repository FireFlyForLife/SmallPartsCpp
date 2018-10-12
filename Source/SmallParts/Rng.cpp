#include <SmallParts/Rng.h>
#include <ctime>
#include <random>

static std::mt19937_64 g_mersenneTwister;

void Rng::Initialize()
{
	// ReSharper disable once CppZeroConstantCanBeReplacedWithNullptr
	g_mersenneTwister.seed(time(0));
}

void Rng::Initialize(int seed)
{
	g_mersenneTwister.seed(seed);
}


int Rng::NextInt(int max)
{
	std::uniform_int_distribution<int> distribution{ 0, max };
	return distribution(g_mersenneTwister);
}

int Rng::NextInt(int min, int max)
{
	std::uniform_int_distribution<int> distribution{ min, max };
	return distribution(g_mersenneTwister);
}

bool Rng::NextBool()
{
	std::uniform_int_distribution<int> distribution{ false, true };
	return !!distribution(g_mersenneTwister);
}

float Rng::NextFloat(float max)
{
	std::uniform_real_distribution<float> distribution{ 0, max };
	return distribution(g_mersenneTwister);
}

float Rng::NextFloat(float min, float max)
{
	std::uniform_real_distribution<float> distribution{ min, max };
	return distribution(g_mersenneTwister);
}

double Rng::NextDouble(double max)
{
	std::uniform_real_distribution<double> distribution{ 0, max };
	return distribution(g_mersenneTwister);
}

double Rng::NextDouble(double min, double max)
{
	std::uniform_real_distribution<double> distribution{ min, max };
	return distribution(g_mersenneTwister);
}