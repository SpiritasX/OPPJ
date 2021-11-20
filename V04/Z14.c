#include <stdio.h>
#include <math.h>
#define MAX 30

int main()
{
	char string[MAX + 1];
	float broj = 0;
	int n = 0, brojTacaka = 0, indeksTacke = 0;

	// Unos stringa
	printf("Unesite realan broj (formata xx.xxx): ");
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
		// Da li je posmatrani karakter broj i treba da se stavljao u ceo deo?
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

	printf("String %s je pretvoren u broj %f.\n", string, broj);
	return 0;
}