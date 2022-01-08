/*
* Zadatak 5.
* 
* Implementirati listu sa tzv. logickim brisanjem. Svaki cvor
* liste osim pokazivaca treba da sadrzi i podatak u vidu
* strukture. Struktura sadrzi sam podatak (jedan broj tipa
* double) i indikator (int) koji je postavljen na 1 ako je
* cvor vazeci, odnosno 0 ako je cvor obrisan. Operaciju
* dodavanje treba realizovati da se izvrsava na kraju liste,
* osim u slucaju ako postoji cvor kojem je indikator=0 kada
* treba novi broj upisati u polje podatak i
* indikator postaviti na jedinicu. Brisanje cvorova treba
* realizovati tako da se za element koji treba biti obrisan
* postavi polje indikator na broj 0. Ispis liste ispisuje samo
* cvorove sa indikator=1.
* 
* Primer:
* 5  2  6  7
* 5  6  7
* 5 10  6  7 11
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double podatak;
	int indikator;
} Podatak;

typedef struct cvor
{
	Podatak podatak;
	struct cvor* sledeci;
} tCvor;

void dodajNaKraj(tCvor**, double);
void obrisi(tCvor**, double);
void printList(tCvor*);
void unisti(tCvor*);

int main()
{
	tCvor* glava = NULL;

	dodajNaKraj(&glava, 5);
	dodajNaKraj(&glava, 2);
	dodajNaKraj(&glava, 6);
	dodajNaKraj(&glava, 7);
	dodajNaKraj(&glava, 2);
	dodajNaKraj(&glava, 2);

	printList(glava);

	obrisi(&glava, 2);
	
	printList(glava);

	dodajNaKraj(&glava, 10);
	dodajNaKraj(&glava, 11);

	printList(glava);

	unisti(glava);

	return 0;
}

void dodajNaKraj(tCvor** glava, double broj)
{
	tCvor* temp;

	if (*glava != NULL)
	{
		// Trazi da li postoji "obrisan" cvor sa zadatim brojem
		temp = *glava;
		while (temp->sledeci != NULL && (temp->podatak.podatak != broj && temp->podatak.indikator == 0))
			temp = temp->sledeci;

		if (temp->podatak.podatak == broj)
		{
			temp->podatak.indikator = 1;
			return;
		}

		// Trazi da li postoji bilo koji "obrisan" cvor da se iskoristi ponovo
		temp = *glava;

		while (temp->sledeci != NULL && temp->podatak.indikator != 0)
			temp = temp->sledeci;

		if (temp->podatak.indikator == 0)
		{
			temp->podatak.indikator = 1;
			temp->podatak.podatak = broj;
			return;
		}
	}

	// U protivnom, napravi novi cvor i dodaj ga na kraj liste
	tCvor* novi = malloc(sizeof(tCvor));

	novi->podatak.podatak = broj;
	novi->podatak.indikator = 1;
	novi->sledeci = NULL;
	
	if (*glava == NULL)
	{
		*glava = novi;
		return;
	}

	temp = *glava;

	while (temp->sledeci != NULL)
		temp = temp->sledeci;

	temp->sledeci = novi;
}

void obrisi(tCvor** glava, double broj)
{
	tCvor* temp = *glava;
	while (temp != NULL)
	{
		if (temp->podatak.podatak == broj)
			temp->podatak.indikator = 0;
		temp = temp->sledeci;
	}
}

void printList(tCvor* glava)
{
	while (glava)
	{
		// Ispisujemo samo cvorove koji nisu "obrisani" tj ciji je indikator == 1
		if (glava->podatak.indikator)
			printf("%.2lf ", glava->podatak.podatak);
		glava = glava->sledeci;
	}
	printf("\n");
}

void unisti(tCvor* glava)
{
	tCvor* temp;

	while (glava)
	{
		temp = glava;
		glava = glava->sledeci;
		free(temp);
	}
}