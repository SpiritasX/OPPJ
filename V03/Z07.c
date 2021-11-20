#include <stdio.h>
#include <math.h>

int main()
{
	float x, f;

	printf("Unesite broj: ");
	scanf("%f", &x);

	if (x < 0)
		f = -7;
	else if (x < 1)
		f = pow(x, 1/4.0) + 4;
	else if (x < 13)
		f = 2 * sqrt(x) - 5;
	else
		f = x * x / 9.0;

	printf("f(%.2f) = %.3f", x, f);

	return 0;
}