/*
* Zadatak 4.
* 
* Data je tekstualna datoteka "vlasnici.txt" koja
* je formirana na osnovu informacija o vlasnicima
* kucnih ljubimaca. Svaki red u datoteci sadrzi ime i
* prezime vlasnika, ime ljubimca i identifikator koji se
* sastoji od celog broja i slova za oznaku vrste ('P' za
* pse, 'M' za macke, 'O' za ostale). Napisati C
* program koji na osnovu sadrzaja pomenute datoteke
* formira listu samo onih zapisa koji se odnose na pse.
* Zatim se sa standardnog ulaza cita sifra izgubljenih
* pasa sve dok se ne unese negativan broj. Za svaku
* ucitanu sifru izgubljenog psa, potrebno je ispisati
* informacije o vlasniku ako je pronadjen, u suprotnom
* ispisati "Nema podataka o psu.".
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char ime[20];
	int id;
	char vrsta;
} Zivotinja;

typedef struct
{
	char ime[20];
	char prezime[20];
	Zivotinja ljubimac;
} Vlasnik;

typedef struct cvor
{
	Vlasnik podatak;
	struct cvor* sledeci;
} tCvor;

void push(tCvor**, Vlasnik);
tCvor* find(tCvor*, int);
void unisti(tCvor**);

int main()
{
	tCvor* glava = NULL;
	FILE* fp = fopen("..\\ulazni.txt", "r");
	Vlasnik temp;
	int broj;

	while (fscanf(fp, "%s %s %s %d%c\n", temp.ime, temp.prezime, temp.ljubimac.ime, &temp.ljubimac.id, &temp.ljubimac.vrsta) != EOF)
		if (temp.ljubimac.vrsta == 'P')
			push(&glava, temp);

	do
	{
		scanf("%d", &broj);
		
		tCvor* tmp = find(glava, broj);

		if (tmp != NULL)
			printf("Ime: %s\nPrezime: %s\n", tmp->podatak.ime, tmp->podatak.prezime);
		else
			printf("Nema podataka o psu.\n");
	} while (broj >= 0);

	unisti(&glava);
	fclose(fp);

	return 0;
}

void push(tCvor** glava, Vlasnik podatak)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->podatak = podatak;
	novi->sledeci = *glava;

	*glava = novi;
}

tCvor* find(tCvor* glava, int broj)
{
	while (glava != NULL)
	{
		if (glava->podatak.ljubimac.id == broj)
			return glava;
		glava = glava->sledeci;
	}

	return NULL;
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