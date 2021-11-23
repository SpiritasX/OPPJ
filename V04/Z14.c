/*
 * Zadatak 14.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji uneseni string s pretvara u realan
 * broj. Realan broj se definise kao niz od jedne ili
 * vise cifara, nakon koje moze biti tacka, nakon
 * koje moze biti jos nula ili vise cifara. Ukoliko je
 * prilikom konverzije doslo do greske (tj. ako string
 * sadrzi nedozvoljeni karakter), ispisati odgovarajucu
 * poruku.
 * 
 * Primer:
 * > cao
 * Vas string sadrzi nedozvoljene karaktere.
 * > 12
 * 12.000000
 * > 95.214
 * 95.214000
 * > 3.0052030
 * 3.005203
 */

#include <stdio.h>
#include <math.h>

#define MAX 30

int main()
{
	char string[MAX + 1];
	float broj = 0;
	int n = 0, brojTacaka = 0, indeksTacke = 0;

	// Unos stringa
	printf("Unesite realan broj (formata xx.xxx)\n> ");
	scanf("%s", string);

	// Prvi prolazak kroz string za uklanjanje gresaka.
	while (string[n])
	{
		// Ako string sadrzi nedozvoljene karaktere, zavrsi program.
		if ((string[n] < 48 || string[n] > 57) && string[n] != '.' && string[n] != '\0' || brojTacaka > 1)
		{
			printf("Vas string sadrzi nedozvoljene karaktere.");
			return 0;
		}
		if (string[n] == '.')
		{
			indeksTacke = n;
			// String ne sme da ima vise od jedne tacke.
			brojTacaka++;
		}
		n++;
	}

	// Ako broj ne sadrzi tacku, indeks tacke je na kraju broja.
	if (indeksTacke == 0)
		indeksTacke = n - 1;

	// Drugi prolazak kroz string za konvertovanje stringa u ceo broj.
	for (int i = 0; i < n; i++)
	{
		// Da li je posmatrani karakter broj?
		if (string[i] >= 48 && string[i] <= 57)
		{
			// Pomeri sve cifre za jedno mesto u levo.
			broj *= 10;
			// Pretvara karakter u cifru koju predstavlja i dodaje na poslednje mesto broja.
			broj += string[i] - 48;
		}
	}

	// Delimo dobijeni ceo broj sa odgovarajucim stepenom desetke da dobijemo realan broj.
	broj /= pow(10, n - 1 - indeksTacke);

	printf("%f", broj);

	return 0;
}