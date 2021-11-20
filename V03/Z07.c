/*
 * Zadatak 7.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se za zadato x izracunava f(x) po
 * formuli:
 * 
 * f(x) = 
 * -7			,      x < 0
 * x^(1/4) + 4	, 0 <= x < 1
 * 2sqrt(x) - 5	, 1 <= x < 13
 * x^2 / 9		,      x >= 13
 * 
 * Primer:
 * > -2
 * -7
 * > 0.13
 * 4.600
 * > 2
 * -2.172
 * > 13
 * 18.778
 */

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