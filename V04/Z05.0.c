/*
 * Zadatak 5.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji na sahovsku tablu (8x8) postavlja
 * kraljicu na poziciju koju korisnik unosi (unosi x i
 * y koordinate). Na polju na kom je kraljica treba
 * da se smesti broj 2, na poljima koje kraljica
 * napada treba da se smesti broj 1 a na svim
 * ostalim mestima treba da se smesti broj 0.
 * 
 * Primer:
 * > 4 3
 * 0  0  0  1  0  0  0  1
 * 1  0  0  1  0  0  1  0
 * 0  1  0  1  0  1  0  0
 * 0  0  1  1  1  0  0  0
 * 1  1  1  2  1  1  1  1
 * 0  0  1  1  1  0  0  0
 * 0  1  0  1  0  1  0  0
 * 1  0  0  1  0  0  1  0
 */

#include <stdio.h>

#define VELICINA 8

int main()
{
	int tabla[VELICINA][VELICINA] = {0};
	int x, y;

	// Unos koordinata kraljice
	printf("Unesite koordinate kraljice\n");
	do
	{
		printf("> ");
		scanf("%d %d", &x, &y);
	} while (x < 0 || x > VELICINA || y < 0 || y > VELICINA);

	// Gde sve kraljica moze da se pomeri
	// Brojac za vrste [i]
	for (int i = 0; i < VELICINA; i++)
	{
		// Brojac za kolone [j]
		for (int j = 0; j < VELICINA; j++)
		{
			// Kolona u kojoj se kraljica nalazi
			if (i == x)
				tabla[i][j] = 1;

			// Vrsta u kojoj se kraljica nalazi
			if (j == y)
				tabla[i][j] = 1;

			// Glavna dijagonala pomerena tako da prolazi
			// kroz poziciju kraljice
			// Za y = x, pomereno za neku tacku (i, j)
			// y - j = x - i, kada izvucemo i, dobrijamo
			// bas i = x - y + j.
			if (i == j + x - y)
				tabla[i][j] = 1;

			// Sporedna dijagonala isto pomerena
			// Ako predstavimo svaki element u matrici kao
			// zbir njegovih indeksa
			// 0 1 2 3
			// 1 2 3 4
			// 2 3 4 5
			// 3 4 5 6
			// Primeticemo da su brojevi poredjani paralelno
			// sa sporednom dijagonalom sto znaci da neki broj
			// x + y moze da se nalazi samo u jednoj od tih linija
			// brojeva i to bas u tom koji je jednak sa i + j.
			if (i + j == x + y)
				tabla[i][j] = 1;
		}
	}

	// Na mestu kraljice treba da bude broj 2
	tabla[x][y] = 2;

	// Ispis table
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
			printf(" %d ", tabla[i][j]);
		printf("\n");
	}
}