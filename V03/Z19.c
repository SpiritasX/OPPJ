/*
 * Zadatak 19.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se stampaju svi trocifreni
 * Armstrongovi brojevi. Broj je Armstrongov ako je
 * jednak zbiru kubova svojih cifara.
 * 
 * Formula:
 * https://en.wikipedia.org/wiki/Narcissistic_number
 */

#include <stdio.h>

int main()
{
	int c1, c2, c3, sum;

	for (int i = 100; i < 1000; i++)
	{
		sum = 0;

		c1 = i / 100;
		c2 = (i / 10) % 10;
		c3 = i % 10;

		sum += c1 * c1 * c1;
		sum += c2 * c2 * c2;
		sum += c3 * c3 * c3;

		if (sum == i)
			printf("%d ", i);
	}

	return 0;
}