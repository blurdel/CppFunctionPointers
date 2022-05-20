#include <functional>
#include <vector>
#include <stdio.h>
#include "Client.h"


typedef std::function<void(int)> cbt;
std::vector<cbt> callbacks;


float add(float a, int b) {
	return a + b;
}

float subtract(float a, int b) {
	return a - b;
}

void goodbye(int x) {
	printf("f() goodbye %d\n", x);
}

void registerCallback(const cbt& cb) {
	callbacks.push_back(cb);
}

int main()
{
	const float x{ 100 };
	const int   y{ 20 };


	// Old style function pointer
	float (*func)(float, int) {};
	printf("func initialized to 0x%p \n\n", func);

	func = &add;
	printf("&add = %p \n", func);
	printf("%g + %d = %g \n\n", x, y, func(x, y));

	func = subtract;
	printf("&sub = %p \n", func);
	printf("%g - %d = %g \n\n", x, y, func(x, y));


	// STL style function pointer
	std::function<float(float, float)> fadd = add;
	printf("%g + %d = %g \n\n", x, y, fadd(x, y));


	Client client;
	registerCallback(&Client::statfunc);

	registerCallback(std::bind(&Client::func, &client, std::placeholders::_1));

	registerCallback(
			[](int val) { printf("lambda callback %d\n", val); }
	);

	registerCallback(
			[&client](int val) { client.func(val); }
	);

	registerCallback(&goodbye);

	for (const auto& cb : callbacks) {
		cb(42);
	}

	return 0;
}
