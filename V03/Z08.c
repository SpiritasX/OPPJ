/*
 * Zadatak 8.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji ucitava vrednosti promenljivih a i b,
 * a zatim resava jednacinu ax + b = 0.
 * Pokriti sve slucajeve za razlicite kombinacije
 * vrednosti a i b.
 * 
 * x = -b / a
 * a != 0
 * 
 * Primer:
 * > 1 2
 * -2.000
 * > 12.3 5.15
 * -0.419
 * > 0 0
 * X pripada R.
 * > 0 5
 * Deljenje sa nulom nije dozvoljeno.
 */

#include <stdio.h>

int main()
{
	float a, b, x;

	printf("Unesite brojeve a i b: ");
	scanf("%f %f", &a, &b);

	if (a == 0 && b == 0)
		printf("X pripada R.");
	else if(a == 0)
		printf("Deljenje sa nulom nije dozvoljeno!");
	else
	{
		x = -b/a;
		printf("x = %.3f", x);
	}

	return 0;
}