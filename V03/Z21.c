/*
 * Zadatak 21.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji ispisuje sve proste brojeve manje
 * od n.
 * 
 * Primer:
 * > 5
 * 1 2 3
 * > 30
 * 1 2 3 5 7 11 13 17 19 23 29
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int n, prost;

	printf("Unesite ceo broj (n > 2)\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 2);

	for (int i = 1; i < n; i++)
	{
		prost = 1;
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0)
				prost = 0;

		if (prost)
			printf("%d ", i);
	}

	return 0;
}