/*
 * Zadatak 1.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * kojim se ucitava niz celobrojnih elemenata
 * (maksimalno 30) i zatim obrce redosled elemenata
 * (zamena prvog sa poslednjim, drugog sa
 * pretposlednjim, itd.) unesenog niza. Za pristup
 * elementima niza koristiti pokazivace.
 * 
 * Primer:
 * > 5
 * > 1 2 3 4 5
 *   5 4 3 2 1
 */

#include <stdio.h>

#define MAX 30

int main()
{
	int niz[MAX], n, *pok;

	// Unos velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// Pokazivac namestiti da pokazuje na prvi element niza
	// rec "niz" se kod nizova u C-u ponasa kao pokazivac na prvi
	// element niza, drugi nacin kako smo to mogli da uradimo je:
	// pok = &niz[0];
	// U bukvalnom prevodu, to znaci "adresa od nultog elementa niza"
	pok = niz;

	// Unos elemenata niza
	printf("Unesite elemente niza\n");
	for (int i = 0; i < n; i++)
	{
		// Korisnik unosi elemente redom
		printf("> ");
		// Odredjeni i-ti element se unosi na adresu prvog elementa,
		// pomerenu za i pozicija u napred (pok + i)
		scanf("%d", pok + i);
	}

	// Zamena elemenata se vrsi tako sto prvih pola clanova menjamo
	// sa drugih pola
	for (int i = 0; i < n / 2; i++)
	{
		// Treba nam broj koji se nalazi na odredjenoj adresi.
		// Zato koristimo dereferenciranje, stavimo zvezdicu pored adrese.
		// A sama adresa je opet pocetna adresa, pomerena za odredjen broj
		// pozicija u napred ili nazad. U ovom slucaju, pomeramo adresu na kraj
		// niza i onda je vracam i mesta u nazad.
		int *adresaSaPocetkaNiza = pok + i; // Element sa pocetka niza
		int *adresaSaKrajaNiza = pok + n - 1 - i; // Element sa zadnjeg kraja niza

		// Menjamo element sa pocetka sa elementom sa kraja niza.
		int temp = *adresaSaPocetkaNiza;
		*adresaSaPocetkaNiza = *adresaSaKrajaNiza;
		*adresaSaKrajaNiza = temp;
	}

	// Prikazujemo niz od prvog do poslednjeg elementa
	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("]");
}