/*
* Zadatak 2.
* 
* Napisati C program koji implementira rad sa hes
* tabelom (recnik) sa kljucevima tipa string. Kao
* hes funkciju koristiti djb2. Kolizije kljuceva
* resavati otvorenim adresiranjem i ponovnim
* hesiranjem pomocu sdbm.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 13

typedef struct
{
	char kljuc[50];
	int podatak;
} Element;

// Rekurzivne funkcije za pretvaranje teksta u jedan broj
long djb2(char* x)
{
	if (*x == 0)
		return 5381;
	else
		return (djb2(x + 1) * 33 + *x) % SIZE;
}

long sdbm(char* x)
{
	if (*x == 0)
		return 1;
	else
		return (sdbm(x + 1) * 65599 + *x) % SIZE;
}

int main()
{
	Element* niz;
	niz = (Element*)calloc(SIZE, sizeof(Element));

	do
	{
		// Postupak je isti kao u proslom zadatku
		char kljuc[50];
		int broj;

		scanf("%49[^\n]", kljuc);
		scanf("%d", &broj);

		if (broj == -1)
			break;

		int indeks = djb2(kljuc);
		int brojac = 0;
		do
		{
			if (niz[indeks].kljuc[0] == 0)
			{
				strcpy(niz[indeks].kljuc, kljuc);
				niz[indeks].podatak = broj;
				break;
			}
			// Sad samo po zahtevu zadatka, ukoliko prvi indeks ne uspe,
			// sledeci put probamo sa drugim algoritmom, a za svaki posle toga
			// idemo otvorenim adresiranjem dok ne naidjemo na prvo slobodno mesto
			else if (brojac == 0)
				indeks = sdbm(kljuc);
			else
				indeks = (indeks + 1) % SIZE;

			brojac++;
		} while (brojac != SIZE);

		if (brojac == SIZE)
		{
			printf("Popunjen je niz");
			break;
		}

		getchar();
	} while (1);

	for (int i = 0; i < SIZE; i++)
		printf("%s %d\n", niz[i].kljuc, niz[i].podatak);

	return 0;
}