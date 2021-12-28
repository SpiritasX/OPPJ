/*
* Zadatak 1.
* 
* Napisati C program kojim se pomocu menija bira
* jedna od sledecih akcija u radu sa spregnutom listom
* celobrojnih vrednosti:
*	- dodavanje na pocetak,
*	- dodavanje na kraj,
*	- brisanje cvora sa zadatom vrednoscu podatka,
*	- prikaz liste.
* Omoguciti da se svaka od akcija moze izvrsiti
* proizvoljan broj puta sve dok korisnik ne zatrazi izlaz
* iz programa.
*/

#include <stdio.h>
#include <stdlib.h>
// ignorisi.
#define clear getchar(); printf("Pritisni Enter da nastavis."); getchar(); system("cls")

typedef struct cvor
{
	int podatak;
	struct cvor* sledeci;
} tCvor;

int meni();
void dodajNaPocetak(tCvor**, int);
void dodajNaKraj(tCvor**, int);
void obrisiCvor(tCvor**, int);
void printList(tCvor*);
void unisti(tCvor**);
tCvor* pronadji(tCvor*, int);

int main()
{
	tCvor* glava = NULL;
	int broj;

	while (1)
	{
		switch (meni())
		{
		case 1:
			printf("Unesite broj koji zelite da dodate\n> ");
			scanf("%d", &broj);
			dodajNaPocetak(&glava, broj);
			clear;
			break;
		case 2:
			printf("Unesite broj koji zelite da dodate\n> ");
			scanf("%d", &broj);
			dodajNaKraj(&glava, broj);
			clear;
			break;
		case 3:
			printf("Koju vrednost sadrzi cvor koji zelite da obrisete?\n> ");
			scanf("%d", &broj);
			obrisiCvor(&glava, broj);
			clear;
			break;
		case 4:
			printList(glava);
			clear;
			break;
		case 5:
			unisti(&glava);
			system("cls");
			return 0;
		default:
			printf("Uneli ste pogresnu vrednost.\n");
			clear;
		}
	}

	return 0;
}

int meni()
{
	int izbor;

	printf("Odaberite nesto od ponudjenog:\n");
	printf("\t1. Dodavanje na pocetak.\n");
	printf("\t2. Dodavanje na kraj.\n");
	printf("\t3. Brisanje cvora sa zadatom vrednoscu podatka.\n");
	printf("\t4. Prikaz liste.\n");
	printf("\t5. Kraj programa.\n");
	printf("> ");

	scanf("%d", &izbor);

	return izbor;
}

void printList(tCvor* cvor)
{
	while (cvor)
	{
		printf("%d ", cvor->podatak);
		cvor = cvor->sledeci;
	}
	printf("\n");
}

void dodajNaPocetak(tCvor** glava, int broj)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->podatak = broj;
	novi->sledeci = *glava;
	
	*glava = novi;
}

void dodajNaKraj(tCvor** glava, int broj)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->podatak = broj;
	novi->sledeci = NULL;

	if (*glava == NULL)
		*glava = novi;
	else
	{
		tCvor* prosli = *glava;

		while (prosli->sledeci != NULL)
			prosli = prosli->sledeci;

		prosli->sledeci = novi;
	}
}

void obrisiCvor(tCvor** glava, int broj)
{
	tCvor* temp = *glava, *cvor = pronadji(*glava, broj);

	if (cvor == NULL)
		return;

	if (*glava == cvor)
	{
		*glava = cvor->sledeci;
		free(cvor);
	}
	else
	{
		while (temp->sledeci != cvor)
			temp = temp->sledeci;

		temp->sledeci = cvor->sledeci;
		free(cvor);
	}
}

void unisti(tCvor** glava)
{
	tCvor* temp;

	while (*glava != NULL)
	{
		temp = *glava;
		*glava = temp->sledeci;
		free(temp);
	}
}

tCvor* pronadji(tCvor* cvor, int broj)
{
	while (cvor)
		if (cvor->podatak == broj)
			return cvor;
		else
			cvor = cvor->sledeci;

	return NULL;
}