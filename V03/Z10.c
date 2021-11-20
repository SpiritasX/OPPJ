/*
 * Zadatak 10.
 *
 * Napisati C program koji za tri ulazne pozitivne
 * celobrojne vrednosti odreduju i na ekran ispisuju
 * srednju vrednost po velicini.
 *
 * Note:
 * Nisam siguran sta znaci "po velicini".
 */

#include <stdio.h>

int main()
{
	unsigned a, b, c;

	printf("Unesite tri cela broja: ");
	scanf("%u %u %u", &a, &b, &c);

	printf("Srednja vrednost = %f", (a + b + c)/3.0);

	return 0;
}