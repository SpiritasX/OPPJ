/*
 * Zadatak 2.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se ucitava matrica A i razmenjuje:
 *     a) k-ta vrsta sa l-tom vrstom (celobrojne
 *        parametre k i l zadaje korisnik)
 *     b) vrsta koja sadrzi element najvece vrednosti
 *        sa vrstom koja sadrzi element najmanje vrednosti.
 * 
 * Prikazati matricu nakon transformacija.
 * 
 * Primer:
 * > 5 5
 * > -2  7  0  6 -2
 * >  1 -1  3  2  2
 * >  3  4  0  5  3
 * >  2  5 -4 -2  2
 * >  0  3 -1  1 -4
 * a)
 * > 3 5
 * -2  7  0  6 -2
 *  1 -1  3  2  2
 *  0  3 -1  1 -4
 *  2  5 -4 -2  2
 *  3  4  0  5  3
 * b)
 *  2  5 -4 -2  2
 *  1 -1  3  2  2
 *  0  3 -1  1 -4
 * -2  7  0  6 -2
 *  3  4  0  5  3
 */

#include <stdio.h>
#include <string.h> // memcpy funkcija

#define MAX 20

int main()
{
	int matrica[MAX][MAX], n, m, k, l, min, max, min_idx, max_idx, temp[MAX];

	// Provera unosa velicina matrice
	printf("Unesite velicine matrice (2-%d)\n", MAX);
	do
	{
		printf("> ");
		scanf("%d %d", &n, &m);
	} while (n < 2 || n > MAX || m < 2 || m > MAX);

	// Unos matrice
	// Brojac za vrste
	for (int i = 0; i < n; i++)
	{
		// Brojac za kolone
		for (int j = 0; j < m; j++)
		{
			// Unos elementa
			printf("matrica[%d][%d]> ", i, j);
			scanf("%d", &matrica[i][j]);

			// Sacuvaj prvi element kao najmanji i najveci
			// da bi mogao da ga poredis sa svakim sledecim
			if (i == 0 && j == 0)
			{
				min = matrica[i][j];
				max = matrica[i][j];
				// Dovoljno nam je da znamo samo indeks vrste
				// zato sto na kraju koristimo min i max da zamenimo
				// vrste.
				min_idx = 0;
				max_idx = 0;
			}

			// Pronalazenje najmanjeg elementa i njegovog indeksa
			if (matrica[i][j] < min)
			{
				min = matrica[i][j];
				min_idx = i;
			}
			// Isto za najveci-
			if (matrica[i][j] > max)
			{
				max = matrica[i][j];
				max_idx = i;
			}
		}
	}

	// Provera unosa k i l
	printf("Unesite vrste koje zelite da zamenite (1-%d, 1-%d)\n", n, m);
	do
	{
		printf("> ");
		scanf("%d %d", &k, &l);
	} while (k < 1 || k > n || l < 1 || l > m);
	
	// Prikaz unete matrice
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < m; j++)
			printf("%2d ", matrica[i][j]);
		printf("]\n");
	}

	// Zamena te dve vrste
	// Posto je matrica zapravo niz nizova, matrica[k] je niz tj k-ta vrsta!
	// A da ne bi morali da menjamo element po element, mozemo da zamenimo
	// samo ceo blok memorije
	memcpy(temp, matrica[k - 1], sizeof(temp));
	memcpy(matrica[k - 1], matrica[l - 1], sizeof(temp));
	memcpy(matrica[l - 1], temp, sizeof(temp));

	// Prikaz matrice nakon zamene k i l vrste
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < m; j++)
			printf("%2d ", matrica[i][j]);
		printf("]\n");
	}

	// Zamena vrsta po min i max
	memcpy(temp, matrica[min_idx], sizeof(temp));
	memcpy(matrica[min_idx], matrica[max_idx], sizeof(temp));
	memcpy(matrica[max_idx], temp, sizeof(temp));

	// Prikaz matrice nakon zamene min i max vrste
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("[ ");
		for (int j = 0; j < m; j++)
			printf("%2d ", matrica[i][j]);
		printf("]\n");
	}
}