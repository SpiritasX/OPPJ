/*
 * Zadatak 16.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se sa standardnog ulaza ucitavaju
 * vrednosti prirodnih brojeva n i q. Potom,
 * koristeci iteraciju while ispisati sve brojeve od 2
 * do n koji su deljivi sa q.
 * 
 * Primer:
 * > 20 4
 * 4 8 12 16 20
 * > 10 7
 * 7
 */

#include <stdio.h>

int main()
{
	int n, q, i = 2;

	printf("Unesite dva prirodna brojeva\n");
	do
	{
		printf("> ");
		scanf("%d %d", &n, &q);
	} while (n < 1 || q < 1);

	while (i <= n)
	{
		if (i % q == 0)
			printf("%d ", i);
		i++;
	}

	return 0;
}