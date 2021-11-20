/*
 * Zadatak 23.
 * 
 * Dat je niz nizA od maksimalno 30 celobrojnih
 * elemenata. Nacrtati dijagram toka algoritma i napisati
 * C program kojim se ucitava n elemenata i ceo broj b.
 * Na izlazu ispisati ceo niz i broj pojavljivanja broja b u
 * nizu.
 * 
 * Primer:
 * > 7
 * > 2 3 3 3 0 9 1
 * > 0
 * 1
 * > 4
 * > 9 9 9 2
 * > 9
 * 3
 */

#include <stdio.h>

#define MAX 30

int main()
{
	int nizA[MAX];
	int n, b, brojac = 0;

	// Provera unosa
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
		printf("nizA[%d]> ", i);
		scanf("%d", &nizA[i]);
	}

	// Unos broja b
	printf("Unesite broj koji trazite u nizu\n> ");
	scanf("%d", &b);

	// Petlja za prolazak kroz niz
	for (int i = 0; i < n; i++)
	{
		// Ako je element niza jednak sa b, povecaj brojac
		if (nizA[i] == b)
			brojac++;
	}

	// Ispis resenja
	printf("Broj %d se pojavljuje %d puta u nizu.", b, brojac);

	return 0;
}