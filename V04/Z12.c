/*
 * Zadatak 12.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * koji za string koji korisnik unese sa standardnog ulaza
 * prebroji i prikaze broj:
 *     a) Svih slova
 *     b) Samoglasnika
 *     c) Suglasnika
 * 
 * Primer:
 * > Zdravo
 * 6 2 4
 * > Dobro dosli
 * 10 4 6
 */

#include <stdio.h>

int main()
{
	char str[100];
	int n = 0, slova = 0, samo = 0, sug = 0;

	// Unos stringa
	printf("Unesite string\n> ");
	gets(str);

	// Velicina stringa
	while (str[++n]);

	// Prolazi kroz string
	for (int i = 0; i < n; i++)
	{
		// Ako je slovo, povecaj brojac
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			slova++;
			// Ako je samoglasnik, povecaj brojac
			if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
				str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				samo++;
		}
	}

	// Broj suglasnika je (broj slova - broj samoglasnika)
	sug = slova - samo;

	// Ispis rezultata
	printf("%d %d %d", slova, samo, sug);

	return 0;
}