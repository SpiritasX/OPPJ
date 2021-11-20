/*
 * Zadatak 4.
 * 
 * Napisati C program koji za godinu unesenu sa
 * standardnog ulaza odreduje i ispisuje na
 * standardni izlaz da li je godina prestupna. Godina
 * se racuna prestupnom ako je:
 *	 - Deljiva sa 400
 *   - Deljiva sa 4, ali ne i sa 100
 * 
 * Formula:
 * https://en.wikipedia.org/wiki/Leap_year#:~:text=the%20tropical%20year.-,Algorithm,-%5Bedit%5D
 * 
 * Primer:
 * > 1800
 * Nije
 * > 2004
 * Jeste
 * > 1056
 * Jeste
 */

#include <stdio.h>

int main()
{
	int godina;

	printf("Unesite godinu (YYYY): ");
	scanf("%d", &godina);

	if (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0))
		printf("Prestupna!!");
	else
		printf("Nije prestupna...");

	return 0;
}