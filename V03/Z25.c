/*
 * Zadatak 25.
 * 
 * Dat je niz nizC od maksimalno 25 celobrojnih
 * elemenata. Nacrtati dijagram toka algoritma i
 * napisati C program kojim se ucitava n elemenata
 * u nizC i formiraju nizovi nizA i nizB, pri cemu su
 * elementi nizA parni elementi nizC, a elementi nizB
 * su negativni elementi nizC. Ispisati nizove nizC,
 * nizA i nizB.
 * 
 * Note:
 * Who da hail knows if negative numbers are even- Anyways.
 * 
 * Primer:
 * > 7
 * > 1 0 2 5 6 -3 8
 * [ 1 0 2 5 6 -3 8 ]
 * [ 0 2 6 8 ]
 * [ -3 ]
 */

#include <stdio.h>

#define MAX 25

int main()
{
	int nizC[MAX], n, i;
	int nizA[MAX], nizB[MAX], a = 0, b = 0;

	// Provera unosa velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	printf("Unesite elemente niza\n");
	for (i = 0; i < n; i++)
	{
		// Unos elemenata niza
		printf("nizC[%d]> ", i);
		scanf("%d", &nizC[i]);

		// Radi skracivanja programa, necu praviti
		// novu petlju nego cu odmah izvrsiti potrebne provere
		
		// Ako je broj paran, sacuvaj u nizA
		if (nizC[i] % 2 == 0)
			nizA[a++] = nizC[i];
		// Ako je element negativan, sacuvaj u nizB
		if (nizC[i] < 0)
			nizB[b++] = nizC[i];
	}

	// Ispis rezultata
	printf("[ ");
	for (i = 0; i < n; i++)
		printf("%d ", nizC[i]);
	printf("]\n");

	printf("[ ");
	for (i = 0; i < a; i++)
		printf("%d ", nizA[i]);
	printf("]\n");

	printf("[ ");
	for (i = 0; i < b; i++)
		printf("%d ", nizB[i]);
	printf("]\n");
	return 0;
}