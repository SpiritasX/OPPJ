/*
* Zadatak 5.
*
* Abecedni spisak vrsta biljaka u botanickoj basti je
* podeljen na vise datoteka radi lakseg cuvanja.
* Prvobitni redosled datoteka je vremenom
* promenjen tako da je sadrzaj svake pojedinacne
* datoteke ostao isti (sortiran), ali se ne znaju
* mesta datoteka u ukupnom poretku. Napisati
* program koji ucitava N datoteka naziva
* "vrsteX.txt",sadrzaj svake datoteke smesta u
* zasebu listu, potom spaja liste kako bi se dobio
* sortiran spisak svih vrsta koji treba ispisati u
* izlaznu datoteku "sve_vrste.txt".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define N 3

typedef struct cvor
{
	char naziv[60];
	struct cvor* sledeci;
} tCvor;

void enqueue(tCvor**, char*);
void spoj(tCvor**, tCvor**);
void unisti(tCvor**);

int main()
{
	tCvor* glave[N] = { NULL };
	FILE* fp = fopen("..\\files\\ulazni.txt", "r");
	char str[11], temp[50];

	// Ucitavanje N fajlova
	for (int i = 0; i < N; i++)
	{
		sprintf(str, "..\\files\\vrste%d.txt", i + 1);
		fp = freopen(str, "r", fp);

		assert(fp);

		while (fscanf(fp, "%s\n", temp) != EOF) enqueue(&glave[i], temp);
	}

	// Sortiranje pokazivaca na glave listi
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (glave[i]->naziv[0] > glave[j]->naziv[0])
			{
				tCvor* tmp = glave[i];
				glave[i] = glave[j];
				glave[j] = tmp;
			}
		}
	}

	// Spajanje svih listi u jednu
	for (int i = 0; i < N - 1; i++)
		spoj(&glave[i], &glave[i + 1]);

	// Upisivanje u fajl
	fp = freopen("..\\files\\izlaz.txt", "w", fp);

	tCvor* tmp = glave[0];
	while (tmp != NULL)
	{
		printf("%s\n", tmp->naziv);
		fprintf(fp, "%s\n", tmp->naziv);
		tmp = tmp->sledeci;
	}

	unisti(tmp);
	fclose(fp);

	return 0;
}

void enqueue(tCvor** glava, char* str)
{
	tCvor* novi = malloc(sizeof(tCvor));

	strcpy(novi->naziv, str);
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

// Spaja dve liste tako sto poslednji element prve pokazuje na drugu
void spoj(tCvor** prvi, tCvor** drugi)
{
	tCvor* temp = *prvi;

	while (temp->sledeci != NULL)
		temp = temp->sledeci;

	temp->sledeci = *drugi;
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