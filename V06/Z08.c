/*
 * Zadatak 8.
 * 
 * Za uneseni niz iz zadatka 7, naci sve jedinstvene
 * brojeve. Za te brojeve treba alocirati niz struktura
 * Histogram koja imaju polja {broj, broj_pojavljivanja}.
 * Ova polja cuvaju po jedan broj koji se pojavljivao u
 * nizu i broj pojavljivanja tog broja. Treba ispisati sadrzaj
 * novog niza i srednju vrednost kao:
 * SUM(broj*broj_pojavljivanja)/broj_svih_brojeva.
 * 
 * Note:
 * Vraticu se na ovo nmg...
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int broj;
	int broj_pojavljivanja;
} Histogram;

int main()
{
	int broj, * niz = malloc(sizeof(int)), n = 0, k = 0, brojac = 0, j, sum = 0;

	Histogram* histogram;

	printf("Unesite neki broj razlicit od 0\n");
	printf("> ");
	scanf("%d", &broj);

	if (broj != 0)
		histogram = calloc(1, sizeof(Histogram));

	do
	{
		if (broj != 0)
		{
			n = pow(2, k++);
			niz = realloc(niz, n * sizeof(int));

			for (int i = n / 2; i < n; i++)
			{
				niz[i] = broj;

				if (broj == 0)
					break;
				else
				{
					for (j = 0; j < brojac; j++)
					{
						if (histogram[j].broj == broj)
						{
							histogram[j].broj_pojavljivanja++;
							break;
						}
					}

					if (j == brojac)
					{
						histogram[brojac].broj = broj;
						histogram[brojac].broj_pojavljivanja++;
						brojac++;
					}

					printf("> ");
					scanf("%d", &broj);
				}
			}
		}
	} while (broj != 0);

	for (int i = 0; i < brojac; i++)
		sum += histogram[i].broj * histogram[i].broj_pojavljivanja;

	printf("AVG = %.2f", (float)sum / brojac);
}