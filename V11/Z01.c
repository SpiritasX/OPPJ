/*
* Zadak 1.
* 
* Napisati C program koji implementira rad sa hes
* tabelom (recnikom) sa celobrojnim kljucevima.
* Kao hes funkciju uzeti ostatak pri deljenju sa
* nekim prostim brojem (npr. 73). Kolizije kljuceva
* resavati otvorenim adresiranjem, odnosno
* trazenjem sledeceg slobodnog mesta u nizu.
*/

#include <stdio.h>
#define SIZE 5 // prost broj

// key:value par
typedef struct
{
	int kljuc;
	int podatak;
} Element;

// hes funkcija
int h(int x)
{
	return x % SIZE;
}

// Oznaka da li je neki element iskoriscen
// je samo po tome da li je kljuc nula ili ne.
// Nula oznacava da nije koriscen a u isto vreme
// i false u c-u.
int used(Element x)
{
	return x.kljuc;
}

int main()
{
	Element* niz;
	niz = (Element*)calloc(SIZE, sizeof(Element));

	do
	{
		// U svakoj iteraciji, unosimo kljuc i podatak
		int broj, kljuc;
		getchar();
		printf("Unesite kljuc (razlicit od 0) i ceo broj (-1 ako zelite da zavrsite program).\n> ");
		scanf("%d %d", &kljuc, &broj);

		// S obzirom da kljuc = 0 ima svoju upotrebu,
		// ne smemo da dopustimo da korisnik to unese
		// kao svoj kljuc
		if (kljuc == 0)
			continue;

		// broj = -1 se koristi da se zavrsi program
		if (broj == -1)
			return 0;

		int brojac = 0; // sluzi da prati koliko elemenata niza je popunjeno
		int indeks = h(kljuc); // pretvaramo uneti kljuc u njemu odgovarajuci indeks
		do
		{
			// Ako je element pod tim indeksom prazan, stavicemo novi broj na to mesto i zavrsiti petlju
			if (!used(niz[indeks]))
			{
				printf("%d\n", indeks);
				niz[indeks].kljuc = kljuc;
				niz[indeks].podatak = broj;
				break;
			}
			else // U suprotnom, pomeramo se na sledece mesto i vrsimo istu proveru
				indeks = h(indeks + 1);

			brojac++;
		} while(brojac != SIZE);

		if (brojac == SIZE)
		{
			printf("Popunjen je niz");
			return 0;
		}
	} while (1);
}