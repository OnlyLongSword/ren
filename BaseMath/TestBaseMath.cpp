#include "TestBaseMath.h"
#include <iostream>
#include <cassert>

void TestBaseMath::test() const
{
	std::cout << "[Test] Running BaseMath tests...\n";

	double a = 1.5, b = 2.5;
	double expected = 4.0;
	double result = a + b;

	assert(result == expected);
	std::cout << "[PASS] Add(" << a << ", " << b << ") = " << result << "\n";
}
