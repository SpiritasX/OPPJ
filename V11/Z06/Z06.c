/*
* Zadatak 6.
*
* Svaki red ulazne datoteke "gradovi.txt"
* sadrzi ime grada i broj stanovnika. Napisati C
* program koji iz ulazne datoteke ucitava podatke
* o gradovima i dodaje ih u jednostruko spregnutu
* listu sortiranu po opadajucoj vrednosti broja
* stanovnika. U slucaju da se isti grad pojavljuje vise
* puta, u elementu liste za taj grad upisati najveci
* broj stanovnika. Na kraju, na standarni izlaz
* ispisati 5 najnaseljenijih gradova.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct
{
	char naziv[50];
	int populacija;
} Grad;

typedef struct cvor
{
	Grad podatak;
	struct cvor* sledeci;
} tCvor;

void push(tCvor**, Grad);
void parseCity(Grad*);
void sort(tCvor**);
void printList(tCvor*);
void unisti(tCvor**);

int main()
{
	tCvor* glava = NULL;
	FILE* fp = fopen("..\\ulazni.txt", "r");
	Grad temp;

	assert(fp);

	while (fscanf(fp, "%s %d\n", temp.naziv, &temp.populacija) != EOF)
		push(&glava, temp);

	sort(&glava);

	// Ispisuje prvih 5 gradova. Zato sto su sortirani, to ce ujedno biti i 5 sa najvecom populacijom.
	for (int i = 0; i < 5; i++)
	{
		printf("%s %d\n", glava->podatak.naziv, glava->podatak.populacija);
		glava = glava->sledeci;
	}

	return 0;
}

void push(tCvor** glava, Grad podatak)
{
	// Ako vec postoji grad sa istim nazivom, promeni mu populaciju ukoliko je nova veca
	tCvor* temp = *glava;

	while (temp != NULL)
	{
		if (!strcmp(temp->podatak.naziv, podatak.naziv))
		{
			if (temp->podatak.populacija < podatak.populacija)
				temp->podatak.populacija = podatak.populacija;
			return;
		}
		temp = temp->sledeci;
	}

	// U protivnom samo dodaj novi grad na pocetak liste
	tCvor* novi = malloc(sizeof(tCvor));

	parseCity(&podatak);

	novi->podatak = podatak;
	novi->sledeci = *glava;

	*glava = novi;
}

// Nazivi gradova umesto razmaka sadrze _ u sebi radi lakseg citanja
// Nakon citanja, mozemo samo da zamenimo svaku crtu sa razmakom opet
void parseCity(Grad* grad)
{
	for (int i = 0; grad->naziv[i]; i++)
		if (grad->naziv[i] == '_')
			grad->naziv[i] = ' ';
}

void sort(tCvor** glava)
{
	// Bubble sort
	tCvor* prev = *glava, * next;
	while (prev->sledeci != NULL)
	{
		next = prev->sledeci;
		while (next != NULL)
		{
			if (prev->podatak.populacija < next->podatak.populacija)
			{
				Grad temp = prev->podatak;
				prev->podatak = next->podatak;
				next->podatak = temp;
			}
			next = next->sledeci;
		}
		prev = prev->sledeci;
	}
}

void printList(tCvor* glava)
{
	while (glava != NULL)
	{
		printf("%s %d\n", glava->podatak.naziv, glava->podatak.populacija);
		glava = glava->sledeci;
	}
}

void unisti(tCvor** glava)
{
	tCvor* temp;

	while (*glava != NULL);
	{
		temp = *glava;
		*glava = temp->sledeci;
		free(temp);
	}
}