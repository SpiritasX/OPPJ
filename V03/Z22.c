/*
 * Zadatak 22.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji za dati prirodan broj n izracunava:
 * 1*2 + 2*3*4 + ... + (n + 0)*(n + 1)*...*(n + n)
 * 
 * Primer:
 * > 1
 * 2
 * > 3
 * 386
 * > 5
 * 158306
 */

#include <stdio.h>

int main()
{
	int n, s = 0, p;

	printf("Unesite ceo broj\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1);

	for (int i = 1; i <= n; i++)
	{
		p = 1;
		for (int j = 0; j <= i; j++)
			p *= i + j;
		s += p;
	}

	printf("%d", s);

	return 0;
}