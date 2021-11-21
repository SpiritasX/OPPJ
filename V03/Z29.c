/*
 * Zadatak 29.
 * 
 * Nacrtati dijagram tok algoritma i napisati C
 * program koji za zadati niz brojeva A (maksimalne
 * duzine 100) odreduje duzinu najduzeg
 * neopadajuceg podniza uzastopnih clanova.
 * 
 * Primer:
 * > 9
 * > 1 5 2 4 4 8 2 6 1
 * 4
 */

#include <stdio.h>

#define MAX 100

int main()
{
	int niz[MAX], n, brojac = 0, max = 0;

	// Provera unosa velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// Unos elemenata niza
	printf("Unesite elemente niza\n");
	for (int i = 0; i < n; i++)
	{
		// Unesi element
		printf("niz[%d]> ", i);
		scanf("%d", &niz[i]);
		// Ako je prethodni element veci od novog
		if (i > 0 && niz[i] < niz[i - 1])
		{
			// Ako je brojac trenutno veci od max, sacuvaj u max novi broj
			if (brojac > max)
				max = brojac;
			// Resetuj brojac
			brojac = 1;
		}
		// Ako nije, povecaj brojac
		else
			brojac++;
	}

	// Ako je poslednji brojac veci od max, nikad ne bi uslo u if gde max
	// zapravo uzima tu vrednost pa mora odvojeno da se proveri...
	if (brojac > max)
		max = brojac;

	printf("Najduzi neopadajuci podniz ima %d elemenata.", max);

	return 0;
}