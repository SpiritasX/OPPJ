/*
 * Zadatak 15.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se za dato n izracunava faktorijel
 * prirodnog broja n. Koristeci do-while napraviti
 * zastitu za unos broja n.
 * 
 * Formula:
 * https://en.wikipedia.org/wiki/Factorial
 * 
 * Primer:
 * > 5
 * 120
 * > 12
 * 479001600
 */

#include <stdio.h>

int main()
{
	int n, f = 1;

	printf("Unesite ceo broj [0-12]\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 0 || n > 12);

	for (int i = 1; i <= n; i++)
		f *= i;

	printf("%d! = %d", n, f);

	return 0;
}