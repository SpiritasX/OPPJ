/*
 * Zadatak 4.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program za uredivanje kolona pravougaone matrice sa
 * realnim elementima po neopadajucem redosledu
 * zbirova elemenata po kolonama. Prikazati matricu
 * nakon transformacije (Zadatak 3.13 iz zbirke L. K.)
 * 
 * Note:
 * U ovom trenutku jos nisu uradjena sortiranja nizova.
 * Nisam siguran kako bi moglo da se uradi bez toga?
 * Ako sam uopste razumeo dobro tekst zadatka...
 * 
 * Primer:
 * > 3 5
 * >  2 -3  6  2  5
 * > -2  3 -3 -3 -4
 * >  4 -6  9  5  9
 * 
 *   -3  2  2  5  6
 *    3 -2 -3 -4 -3
 *   -6  4  5  9  9
 */

#include <stdio.h>

#define MAX 20

int main()
{
	float matrica[MAX][MAX],
		  sumNiz[MAX] = {0};
	int n, m, i, j, k;

	// Unos velicina matrice
	printf("Unesite velicine matrice\n");
	do
	{
		printf("> ");
		scanf("%d %d", &n, &m);
	} while (n < 2 || n > MAX || m < 2 || m > MAX);

	// Unos matrice
	printf("Unesite elemente matrice\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Unos elementa
			printf("matrica[%d][%d]> ", i, j);
			scanf("%f", &matrica[i][j]);

			// Odmah mozemo i da dodajemo vrednosti u odgovarajuce kolone.
			sumNiz[j] += matrica[i][j];
		}
	}

	// Ispisi matricu
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("[ ");
		for (j = 0; j < m; j++)
			printf("%5.2f ", matrica[i][j]);
		printf("]\n");
	}

	// Bubble sort:
	// Prva petlja uzima element j
	for (j = 0; j < m - 1; j++)
	{
		// Druga petlja uzima sve elemente k POSLE elementa odabranog sa prvom petljom iz tog niza
		for (int k = j + 1; k < m; k++)
		{
			// Ako je element j veci od elementa k
			if (sumNiz[j] > sumNiz[k])
			{
				// zameni ta dva elementa
				float temp = sumNiz[j];
				sumNiz[j] = sumNiz[k];
				sumNiz[k] = temp;

				// ali takodje prodji i kroz te dve kolone i zameni njihove elemente
				for (i = 0; i < n; i++)
				{
					float temp = matrica[i][j];
					matrica[i][j] = matrica[i][k];
					matrica[i][k] = temp;
				}
			}
		}
	}

	// Ispisi matricu
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("[ ");
		for (j = 0; j < m; j++)
			printf("%5.2f ", matrica[i][j]);
		printf("]\n");
	}

	return 0;
}