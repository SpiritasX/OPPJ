/*
 * Zadatak 30.
 * 
 * Nacrtati dijagram tok algoritma i napisati C
 * program koji u zadatom nizu celobrojnih
 * vrednosti A (maksimalne duzine 100) zamenjuje
 * mesta prvom parnom i poslednjem neparnom
 * broju.
 * 
 * Primer:
 * > 5
 * > 1 3 2 8 9
 *   1 3 9 8 2
 * > 9
 * > 1 7 8 9 2 3 4 4 0
 *   1 7 3 9 2 8 4 4 0
 */

#include <stdio.h>

#define MAX 100

int main()
{
	int niz[MAX], n, idxParnog = -1, idxNeparnog = -1, i;

	// Provera unosa velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// Unos elemenata niza
	printf("Unesite elemente niza\n");
	for (i = 0; i < n; i++)
	{
		// Unesi element
		printf("niz[%d]> ", i);
		scanf("%d", &niz[i]);
	}

	// Pronadji prvi parni broj
	for (i = 0; i < n; i++)
		// Ako je broj paran, izadji iz petlje
		if (niz[i] % 2 == 0)
			break;
	// Sacuvaj poslednji koriscen indeks kao indeks prvog parnog broja
	idxParnog = i;

	// Pronadji poslednji neparni broj
	for (i = n - 1; i >= 0; i--)
		// Ako je broj neparan, izadji iz petlje
		if (niz[i] % 2 != 0)
			break;
	// Sacuvaj poslednji koriscen indeks kao indeks poslednjeg neparnog broja
	idxNeparnog = i;

	// Ispis niza
	printf("[ ");
	for (i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("]\n");

	if (idxParnog == -1 || idxNeparnog == -1)
		printf("Ne postoji paran/neparan broj u ovom nizu...");
	else
	{
		int temp = niz[idxParnog];
		niz[idxParnog] = niz[idxNeparnog];
		niz[idxNeparnog] = temp;

		// Ispis niza
		printf("[ ");
		for (i = 0; i < n; i++)
			printf("%d ", niz[i]);
		printf("]\n");
	}

	return 0;
}