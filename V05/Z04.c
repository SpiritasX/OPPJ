/*
 * Zadatak 4.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se ucitava niz od n elemenata niza
 * strukture automobil, koja sadrzi sledeca polja:
 *     - marka automobila (jedna rec, do 20 karaktera)
 *     - kubikaza (prirodan broj)
 *     - godiste (prirodan broj)
 * Na osnovu zadate kubikaze pronaci najnoviji auto sa
 * kubikazom ne vecom od zadate i ispisati njegove
 * podatke na standardni izlaz.
 */

#include <stdio.h>

#define MAXS 10
#define MAXL 20

typedef struct
{
	char marka[MAXL];
	unsigned kubikaza;
	unsigned godiste;
} Automobil;

int main()
{
	Automobil auta[MAXS];
	int n, kubikaza, idx = 0;

	// Unos broja auta
	printf("Koliko automobila zelite?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAXS);

	// Unos auta
	printf("Unesite auta\n");
	for (int i = 0; i < n; i++)
	{
		printf("Auto %d:\n", i + 1);
		printf("\tMarka: ");
		scanf(" %50[^\n]", auta[i].marka);
		printf("\tKubikaza: ");
		scanf(" %d", &auta[i].kubikaza);
		printf("\tGodiste (yyyy): ");
		scanf(" %d", &auta[i].godiste);
	}

	// Unos maksimalne kubikaze
	printf("Unesite maksimalnu kubikazu\n> ");
	scanf("%i", &kubikaza);

	// Trazenje auta koji odgovara zahtevima
	for (int i = 0; i < n; i++)
	{
		// Sacuvaj prvi odgovarajuci auto
		if (idx == 0 && auta[i].kubikaza <= kubikaza)
			idx = i;
		// Svaki sledeci koji ima odgovarajucu kubikazu,
		// proveri da li je noviji od prethodnog
		if (auta[i].kubikaza <= kubikaza && auta[i].godiste > auta[idx].godiste)
			idx = i;
	}

	printf("%s %u %u", auta[idx].marka, auta[idx].kubikaza, auta[idx].godiste);

	return 0;
}