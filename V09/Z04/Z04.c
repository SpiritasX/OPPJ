/*
* Zadatak 4.
* 
* Napisati C program kojim se simulira cekanje ljudi u
* posti. Posta ima zadat broj saltera. Svi klijenti cekaju u
* jednom redu i idu na prvi salter koji je slobodan. Spisak
* klijenata dat je u ulaznom fajlu red.txt tako sto su za
* svakog klijenta dati ime, prezime i broj minuta koje ce
* provesti na salteru. Napraviti onoliko izlaznih datoteka
* koliko ima saltera sa sledecim nacinom nazivanja:
* "salter1.txt", "salter2.txt", ..., "salterN.txt" , gde
* N predstavlja zadati broj saltera. U te datoteke upisati
* sve klijente koji su opsluzeni na tom salteru, podvuci
* crtu i ispod nje ukupno vreme rada konkretnog saltera.
* Realizovati red koriscenjem spregnute linearne liste.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SALTERI 5

typedef struct
{
	char ime[50];
	char prezime[50];
	int minuti;
} Klijent;

typedef struct cvor
{
	Klijent klijent;
	struct cvor* sledeci;
} tCvor;

void enqueue(tCvor**, Klijent);
Klijent dequeue(tCvor**);

int main()
{
	tCvor* red = NULL;
	FILE* fp = fopen("..\\red.txt", "r");
	char str[50];

	assert(fp);

	Klijent temp;

	// Citanje fajla
	while (fscanf(fp, "%s %s %d\n", temp.ime, temp.prezime, &temp.minuti) != EOF)
		enqueue(&red, temp);

	tCvor* salteri[SALTERI] = { 0 };
	int ukupnoMinuta[SALTERI] = { 0 };
	int min = 0;

	// Sortiranje reda po salterima
	do
	{
		temp = dequeue(&red);
		enqueue(&salteri[min], temp);
		ukupnoMinuta[min] += temp.minuti;

		for (int i = 0; i < SALTERI; i++)
			if (ukupnoMinuta[i] < ukupnoMinuta[min])
				min = i;
	} while (red != NULL);

	// Upisivanje u fajlove
	for (int i = 0; i < SALTERI; i++)
	{
		sprintf(str, "..\\salteri\\salter%d.txt", i + 1);
		fp = freopen(str, "w", fp);

		while (salteri[i])
		{
			temp = dequeue(&salteri[i]);
			fprintf(fp, "%10s%10s%3d\n", temp.ime, temp.prezime, temp.minuti);
		}
		fprintf(fp, "------------------------\n%23d", ukupnoMinuta[i]);
	}

	return 0;
}

void enqueue(tCvor** glava, Klijent klijent)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->klijent = klijent;
	novi->sledeci = NULL;

	if (*glava == NULL)
	{
		*glava = novi;
		return;
	}

	tCvor* temp = *glava;

	while (temp->sledeci != NULL)
		temp = temp->sledeci;

	temp->sledeci = novi;
}

Klijent dequeue(tCvor** glava)
{
	Klijent ret = { 0 };

	if (*glava != NULL)
	{
		ret = (*glava)->klijent;

		tCvor* temp = *glava;
		*glava = (*glava)->sledeci;
		free(temp);
	}

	return ret;
}