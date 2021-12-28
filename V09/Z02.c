/*
* Zadatak 2.
* 
* Napisati C program kojim se realizuju sledece
* operacije sa spregnutom listom znakova:
*	- sortirani unos karaktera u listu,
*	- modifikacija karaktera (uz odrzavanje osobine sortiranosti),
*	- trazenje karaktera u listi.
* Interakciju korisnika sa navedenim akcijama realizovati
* putem menija.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cvor
{
	char karakter;
	struct cvor* sledeci;
} tCvor;

int meni();
void dodaj(tCvor**, char);
void modifikuj(tCvor*, char, char);
tCvor* pronadji(tCvor*, char);
void sort(tCvor*);
void printList(tCvor*);
void unisti(tCvor*);

int main()
{
	char slovo1, slovo2;
	int i;

	tCvor* glava = NULL;
	tCvor* temp;

	while (1)
	{
		switch (meni())
		{
		case 1:
			printf("Unesite slovo\n> ");
			getchar();
			slovo1 = getc(stdin);
			dodaj(&glava, slovo1);
			break;
		case 2:
			printf("Unesite slovo koje zelite da modifikujete i u koje slovo\n> ");
			getchar();
			slovo1 = getc(stdin);
			getchar();
			slovo2 = getc(stdin);

			modifikuj(glava, slovo1, slovo2);
			break;
		case 3:
			i = 0;
			printf("Unesite slovo koje zelite da pronadjete\n> ");
			getchar();
			slovo1 = getc(stdin);

			temp = glava;
			while (temp)
			{
				if (temp->karakter == slovo1)
					i++;
				temp = temp->sledeci;
			}

			// Sa funkcijom pronadji();
			/*do
			{
				temp = pronadji(&temp, slovo1);
				if (temp != NULL)
				{
					i++;
					temp = temp->sledeci;
				}
			} while (temp != NULL);*/

			printf("Karaktera %c ima %d\n", slovo1, i);
			break;
		case 4:
			printList(glava);
			sort(glava);
			printList(glava);
			break;
		case 5:
			unisti(glava);
			return 0;
		}
	}

	return 0;
}

int meni()
{
	int izbor;

	printf("Odaberite nesto od ponudjenog:\n");
	printf("\t1. Sortirani unos karaktera.\n");
	printf("\t2. Modifikacija karaktera.\n");
	printf("\t3. Trazenje karaktera.\n");
	printf("\t4. Prikaz liste.\n");
	printf("\t5. Kraj programa.\n");
	printf("> ");

	scanf("%d", &izbor);

	return izbor;
}

void dodaj(tCvor** glava, char slovo)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->karakter = slovo;
	novi->sledeci = NULL;

	if (*glava == NULL)
		*glava = novi;
	else
	{
		tCvor* temp = *glava;

		while (temp->sledeci != NULL)
			temp = temp->sledeci;

		temp->sledeci = novi;
	}
}

void printList(tCvor* glava)
{
	while (glava)
	{
		printf("%c ", glava->karakter);
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

tCvor* pronadji(tCvor* glava, char slovo)
{
	if (glava == NULL)
		return NULL;

	tCvor* temp = glava;
	while (temp->karakter != slovo)
	{
		temp = temp->sledeci;
		if (temp == NULL)
			break;
	}
	return temp;
}

void modifikuj(tCvor* glava, char a, char b)
{
	tCvor* temp = glava;
	while (temp)
	{
		if (temp->karakter == a)
			temp->karakter = b;
		temp = temp->sledeci;
	}
}

void sort(tCvor* glava)
{
	tCvor* prvi = glava;
	while (prvi->sledeci)
	{
		tCvor* drugi = prvi->sledeci;
		while (drugi)
		{
			if (prvi->karakter > drugi->karakter)
			{
				char temp = prvi->karakter;
				prvi->karakter = drugi->karakter;
				drugi->karakter = temp;
			}
			drugi = drugi->sledeci;
		}
		prvi = prvi->sledeci;
	}
}