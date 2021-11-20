/*
 * Zadatak 5.
 * 
 * Napisati C program koji za broj unesen sa
 * standardnog ulaza odreduje i ispisuje na
 * standardni izlaz:
 *   - Broj uvecan za 3 ako je paran
 *   - "Neparan broj" ako je neparan
 * 
 * Primer:
 * > 6
 * 9
 * > 11
 * Neparan broj
 */

#include <stdio.h>

int main()
{
	int a;

	printf("Unesite ceo broj: ");
	scanf("%d", &a);

	if (a % 2)
		printf("Neparan broj...");
	else
		printf("%d", a + 3);

	return 0;
}