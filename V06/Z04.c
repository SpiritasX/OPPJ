/*
 * Zadatak 4.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se unose dimenzije matrice A, a
 * potom i njeni elementi. U unesenoj matrici
 * odrediti i ispisati najveci element koji se nalazi na
 * obodu matrice.
 * 
 * Primer:
 * > 3 4
 * >  1  9  8  5
 * >  0  1  3  4
 * > 12 52  0 42
 * 52
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** matrica, n, m, max;

	// Unos velicina matrice
	printf("Unesite velicine matrice\n");
	do
	{
		printf("> ");
		scanf("%d %d", &n, &m);
	} while (n < 1 || m < 1);

	// Alokacija matrice
	// Prvo alociramo niz pokazivaca koji pokazuju na pokazivace
	matrica = (int**)malloc(n * sizeof(int*));

	// Zatim prolazimo kroz svaki element tog niza
	// i alociramo novi niz elemenata, sve vrste prakticno
	for (int i = 0; i < n; i++)
	{
		// i-ti element matrice je i-ta vrsta, u nju
		// stavljamo m elemenata sada
		matrica[i] = (int*)malloc(m * sizeof(int));
		// Sa sledecom petljom onda prolazimo kroz svaki od
		// tih elemenata i unosimo ih
		for (int j = 0; j < m; j++)
		{
			printf("> ");
			scanf("%d", &matrica[i][j]);

			// Sacuvaj prvi element da bude najveci
			if (i == 0 && j == 0)
				max = matrica[i][j];

			// Ako je element na obodu matrice, proveri da li je najveci
			// Obodi matrice su nulta vrsta, nulta kolona, n-1va vrsta i n-1va kolona.
			if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && matrica[i][j] > max)
				max = matrica[i][j];
		}
	}

	// Ispis matrice
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", matrica[i][j]);
		printf("\n");
	}

	printf("Najveci element je %d.", max);

	// OSLOBADJANJE MEMORIJE MATRICEEEEE
	// Prvo moramo da oslobodimo svaku vrstu kako smo je i alocirali
	for (int i = 0; i < n; i++)
		free(matrica[i]);
	// i na kraju moramo da oslobodimo taj niz vrsta
	free(matrica);

	return 0;
}