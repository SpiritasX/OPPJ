/*
 * Zadatak 6.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * kojim se unosi niz struktura tipa Zaposleni sa
 * poljima: ime, prezime, JMBG, koeficijent strucne
 * spreme i varijabilni koeficijent. Plata zaposlenog se
 * racuna po formuli:
 * 
 * plata = (koef. strucne spreme + var. koef) * cena rada
 * 
 * Cenu rada unosi korisnik. Potom se racuna i ispisuje
 * za svakog zaposlenog ime, prezime i plata za tekuci
 * mesec. Za niz struktura koristiti dinamicku alokaciju
 * memorije.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char ime[50];
	char prezime[50];
	char JMBG[14];
	float kss;
	float vk;
} Zaposleni;

int main()
{
	Zaposleni* radnici;
	int n;
	float* plata, cenaRada;

	// Unos broja radnika
	printf("Koliko radnika zelite da unesete?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1);

	// Alokacija memorije za radnike i za niz plata
	radnici = (Zaposleni*)malloc(n * sizeof(Zaposleni));
	plata = (float*)malloc(n * sizeof(float));

	// Unos cene rada
	printf("Unesite cenu rada\n> ");
	scanf("%f", &cenaRada);

	// Unos radnika
	for (int i = 0; i < n; i++)
	{
		// Unos podataka radnika
		printf("Radnik %d:\n", i + 1);
		printf("\tIme: ");
		scanf(" %50[^\n]", radnici[i].ime);
		printf("\tPrezime: ");
		scanf(" %50[^\n]", radnici[i].prezime);
		printf("\tJMBG: ");
		scanf(" %14[^\n]", radnici[i].JMBG);
		printf("\tKoeficijent strucne spreme: ");
		scanf(" %f", &radnici[i].kss);
		printf("\tVarijabilni koeficijent: ");
		scanf(" %f", &radnici[i].vk);

		plata[i] = (radnici[i].kss + radnici[i].vk) * cenaRada;
	}

	// Ispis svih radnika
	printf("%20s | %20s | %10s\n", "IME", "PREZIME", "PLATA");
	for (int i = 0; i < n; i++)
		printf("%20s | %20s | %10.2f\n", radnici[i].ime, radnici[i].prezime, plata[i]);

	free(radnici);
	free(plata);
	return 0;
}