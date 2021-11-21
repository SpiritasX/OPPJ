/*
 * Zadatak 27.
 * 
 * Nacrtati dijagram toka algoritma i napisati
 * C program kojim se pronalazi prvi element niza
 * koji je najblizi srednjoj vrednosti niza celih
 * brojeva. Niz moze imati najvise 20 elemenata.
 * 
 * Primer:
 * > 1 1 1 3 4 9
 * 3 (avg = 3.167)
 */

#include <stdio.h>
#include <math.h>

#define MAX 20

int main()
{
	int niz[MAX], n, i, iMin;
	float avg = 0, min;

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
		scanf("%d", &niz[i]);

		// Saberi sve elemente u jednu promenljivu
		avg += niz[i];
	}

	// Podeli taj zbir sa brojem elemenata da dobijes average
	avg /= n;

	// Pretpostavimo da je prvi najblizi srednjoj vrednosti
	min = fabs(niz[0] - avg);
	iMin = 0;

	// Pronaladji koliko je svaki sledeci element
	// daleko od srednje vrednosti
	for (i = 1; i < n; i++)
	{
		// Ako je ovaj element novi najblizi, sacuvaj ga
		if (fabs(niz[i] - avg) < min)
		{
			min = fabs(niz[i] - avg);
			iMin = i;
		}
	}

	printf("Avg = %.2f\nNiz[%d] = %d", avg, iMin, niz[iMin]);
	
	return 0;
}