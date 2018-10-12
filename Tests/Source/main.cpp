#include <Smallparts/Timing.h>
#include <iostream>
#include "SmallParts/Assertion.h"

int main()
{
	Timing::InitTime();

	std::cout << Timing::DeltaTime() << '\n';

	ASSERT(5 == 5);
	ASSERT_M(5 == 2, "My own message!");

	std::cout << "Press enter to exit...";
	std::cin.get();
}
