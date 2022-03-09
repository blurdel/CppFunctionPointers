#include <stdio.h>


float add(float a, int b) {
	return a + b;
}

float subtract(float a, int b) {
	return a - b;
}


int main()
{
	const float x{ 100 };
	const int   y{ 20 };

	float (*func)(float, int) {};
	printf("func initialized to 0x%p \n", func);

	func = &add;
	printf("&add = %p \n", func);
	printf("%g + %d = %g \n", x, y, func(x, y));

	func = subtract;
	printf("&sub = %p \n", func);
	printf("%g - %d = %g \n", x, y, func(x, y));

	return 0;
}
