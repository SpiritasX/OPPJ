/*
 * Zadatak 3.
 * 
 * Napisati C program koji za tri ulazne celobrojne
 * promenljive, odreduje i ispisuje vrednost
 * najmanje na standardni izlaz.
 * 
 * Primer:
 * > 1 2 3
 * 1
 * > 19 52 10
 * 10
 * > 42 29 529
 * 29
 */

#include <stdio.h>

int main()
{
	int a, b, c, min;

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &a, &b, &c);

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;

	printf("Najmanji broj je %d", min);

	return 0;
}