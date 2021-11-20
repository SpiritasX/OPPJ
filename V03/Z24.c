/*
 * Zadatak 24.
 * 
 * Dat je niz od maksimalno 20 realnih elemenata.
 * Nacrtati dijagram toka algoritma i napisati
 * C program kojim se ucitava n elemenata, a zatim
 * nalazi i prikazuje maksimalna i minimalna
 * vrednost u nizu.
 * 
 * Primer:
 * > 7
 * > 2 6 3 9 0 3 5
 * 0 9
 */

#include <stdio.h>

#define MAX 20

int main()
{
	float niz[MAX], min, max;
	int n;

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
		printf("niz[%d]> ", i);
		scanf("%f", &niz[i]);
	}

	// Min i max stavi da budu jednaki prvom elementu
	min = niz[0];
	max = niz[0];

	// Petlja prolazi od drugog do poslednjeg elementa
	for (int i = 1; i < n; i++)
	{
		// Ako je broj manji od prethodnog najmanjeg, sacuvaj ga
		if (niz[i] < min)
			min = niz[i];
		// Ako je broj veci od prethodnog najveceg, sacuvaj ga
		if (niz[i] > max)
			max = niz[i];
	}

	// Ispis rezultata
	printf("Min = %f\nMax = %f", min, max);

	return 0;
}