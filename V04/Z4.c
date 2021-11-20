#include <stdio.h>

#define MAX 30

int main()
{
	float matrica[MAX][MAX],
		  sumNiz[MAX] = { 0 };	// Niz za cuvanje zbira svih kolona po indeksima, sve vrednosti pocinju od 0.
	int n, m, i, j, k;

	// Velicine matrice
	printf("Unesite velicine matrice: ");
	scanf("%d %d", &n, &m);

	// Unos matrice
	for (i = 0; i < n; i++)
	{
		printf("Unesite %d. red matrice:\n", i + 1);
		for (j = 0; j < m; j++)
		{
			printf("\t%d. element: ", j + 1);
			scanf("%f", &matrica[i][j]);
			// Odmah mozemo i da dodajemo vrednosti u odgovarajuce kolone.
			sumNiz[j] += matrica[i][j];
		}
	}

	// Ispisu matricu
	printf("\nUneta matrica:\n");
	for (i = 0; i < n; i++)
	{
		printf("[ ");
		for (j = 0; j < m; j++)
		{
			printf("%.2f ", matrica[i][j]);
		}
		printf("]\n");
	}

	// Bubble sort:
	for (j = 0; j < m - 1; j++) // Prva petlja uzima element j.
	{
		for (int k = j + 1; k < m; k++) // Druga petlja uzima sve elemente k POSLE elementa odabranog sa prvom petljom iz tog niza.
		{
			if (sumNiz[j] > sumNiz[k]) // Ako je element j veci od elementa k,
			{
				// zameni ta dva elementa,
				float temp = sumNiz[j];
				sumNiz[j] = sumNiz[k];
				sumNiz[k] = temp;

				// ali takodje prodji i kroz te dve kolone i zameni njihove elemente.
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
	printf("\nTransformisana matrica:\n");
	for (i = 0; i < n; i++)
	{
		printf("[ ");
		for (j = 0; j < m; j++)
		{
			printf("%.2f ", matrica[i][j]);
		}
		printf("]\n");
	}

	return 0;
}