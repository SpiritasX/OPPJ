/*
 * Zadatak 3.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program za transponovanje kvadratne matrice sa
 * realnim elementima. Na pocetku programa potrebno
 * je ucitati dimenziju i elemente matrice. Prikazati
 * matricu nakon transformacije (Zadatak 3.12 iz zbirke
 * L. K.)
 * 
 * Primer:
 * > 3 2
 * > 1 2
 * > 4 5
 * > 3 0
 * 1 4 3
 * 2 5 0
 */

#include <stdio.h>

#define MAX 20

int main()
{
	float matrica[MAX][MAX], temp[MAX][MAX];
	int n, m;

	// Unos dimenzija matrice
	printf("Unesite velicine matrice (2-%d)\n", MAX);
	do
	{
		printf("> ");
		scanf("%d %d", &n, &m);
	} while (n < 2 || n > MAX || m < 2 || m > MAX);

	// Unos elemenata matrice
	// Brojac za vrste
	for (int i = 0; i < n; i++)
	{
		// Brojac za kolone
		for (int j = 0; j < m; j++)
		{
			// Unos elementa
			printf("matrica[%d][%d]> ", i, j);
			scanf("%f", &matrica[i][j]);
		}
	}

	// Ispis matrice
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < m; j++)
			printf("%2.2f ", matrica[i][j]);
		printf("]\n");
	}

	// Transponovanje
	// Brojac za vrste nove, tj kolone stare matrice
	for (int i = 0; i < m; i++)
		// Brojac za kolone nove, tj vrste stare matrice
		for (int j = 0; j < n; j++)
			temp[i][j] = matrica[j][i];

	// Kopiranje nove matrice na mesto stare
	memcpy(matrica, temp, sizeof(temp));

	// Ispis posle transponovanja
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		printf("[ ");
		for (int j = 0; j < n; j++)
			printf("%2.2f ", matrica[i][j]);
		printf("]\n");
	}
}