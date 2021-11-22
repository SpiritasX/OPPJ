/*
 * Zadatak 1.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se ucitava kvadratna matrica A,
 * dimenzija nxn (n vece ili jednako od 2), i ispisuje
 * suma elemenata koji se nalaze:
 *     a) u 2. vrsti,
 *     b) u 1. koloni,
 *     c) na glavnoj dijagonali,
 *     d) na sporednoj dijagonali,
 *     e) ispod glavne dijagonale,
 *     f) iznad sporedne dijagonale.
 * 
 * Primer:
 * > 5
 * > -2  7  0  6 -2
 * >  1 -1  3  2  2
 * >  3  4  0  5  3
 * >  2  5 -4 -2  2
 * >  0  3 -1  1 -4
 * 7 4 -9 5 14 23
 */

#include <stdio.h>

#define MAX 20

int main()
{
	int matrica[MAX][MAX], n;
	int sumA = 0, sumB = 0, sumC = 0, sumD = 0, sumE = 0, sumF = 0;

	// Provera unosa velicine matrice (2-20)
	printf("Unesite velicinu kvadratne matrice (2-%d)\n", MAX);
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 2 || n > MAX);

	//            Unos matrice
	// Potrebna nam je takozvana ugnjezdena
	// petlja gde jedan brojac broji kolone,
	// a drugi vrste i tako pristupamo svakom
	// elementu matrice.

	printf("Unesite elemente matrice\n");
	// Brojac za vrste
	for (int i = 0; i < n; i++)
	{
		// Brojac za kolone
		for (int j = 0; j < n; j++)
		{
			// Unos elementa
			printf("matrica[%d][%d]> ", i, j);
			scanf("%d", &matrica[i][j]);

			// a) druga vrsta
			if (i == 1)
				sumA += matrica[i][j];
			// b) prva kolona
			if (j == 0)
				sumB += matrica[i][j];
			// c) glavna dijagonala (\)
			if (i == j)
				sumC += matrica[i][j];
			// d) sporedna dijagonala (/)
			if (i == n - 1 - j)
				sumD += matrica[i][j];
			// e)
			if (i > j)
				sumE += matrica[i][j];
			// f)
			if (i + j < n - 1)
				sumF += matrica[i][j];
		}
	}

	// Prikaz unete matrice
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < n; j++)
			printf("%2d ", matrica[i][j]);
		printf("]\n");
	}

	// Ispis rezultata
	printf("\n%d %d %d %d %d %d\n", sumA, sumB, sumC, sumD, sumE, sumF);
}