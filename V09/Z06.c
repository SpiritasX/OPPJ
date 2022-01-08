/*
* Zadatak 6.
* 
* U Sluzbi smestaja SCNS se revidiraju prijave za dom. Sve se odvija
* brzo tako da Mico Jovic kada proveri prijavnicu, stavi je na vrh
* gomile, a Jovana Micic sa iste gomile uzima prvu prijavu sa vrha
* gomile. Napraviti C program koji modeluje njihovo ponasanje.
* Treba da postoji meni koji omogucuje dodavanje prijavnice,
* obradu prijavnice i zavrsetak rada. Treba odabrati odgovarajucu
* strukturu koja modeluje ponasanje gomile prijavnica za dom, a
* podatak koji se cuva je struktura sa poljima: ime, godina studija
* i zbir ocena. Svaka godina studija ima po 3 ispita. Prilikom
* dodavanje prijave, upisuju se ime (do 20 karaktera), godina studija i
* ocene za svaku godinu. Prilikom uklanjanja prijave, proverava se da
* li je (zbir_ocena)/(godina_studija*3) > 8. Ako jeste, na
* standardnom izlazu treba ispisati "<ime> je dobio dom.", u
* suprotnom ne treba da se desi ispis. Kada se zavrsava rad, treba
* ispisati koliko ostaje nerevidiranih prijavnica za naredni dan.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char ime[21];
	char prezime[21];
	int godina;
	int ocene[12];
} Prijavnica;

typedef struct cvor
{
	Prijavnica podatak;
	struct cvor* sledeci;
} tCvor;

int meni();
void push(tCvor**, Prijavnica);
Prijavnica pop(tCvor**);
void dodaj(tCvor**);
void obradi(tCvor**);
int saberiOcene(Prijavnica);
int prihvacen(Prijavnica);
int unisti(tCvor**);

int main()
{
	tCvor* glava = NULL;
	Prijavnica temp;

	do
	{
		switch (meni())
		{
		case 1:
			dodaj(&glava);
			break;
		case 2:
			obradi(&glava);
			break;
		case 3:
			printf("Ostalo je %d nerevidiranih prijavnica.\n", unisti(&glava));
			return 0;
		}

		printf("Pritisnite bilo koji taster da nastavite.\n");
		getchar();
		getchar();
	} while (1);

	return 0;
}

int meni()
{
	int izbor;

	do
	{
		system("cls");
		printf("1. Dodaj prijavnicu\n");
		printf("2. Obradi prijavnicu\n");
		printf("3. Zavrsi rad\n> ");
		scanf("%d", &izbor);
	} while (izbor < 1 || izbor > 3);

	return izbor;
}

void dodaj(tCvor** glava)
{
	Prijavnica temp;

	printf("\tIme: ");
	scanf("%20s", temp.ime);

	printf("\tPrezime: ");
	scanf("%20s", temp.prezime);

	do
	{
		printf("\tGodina: ");
		scanf("%d", &temp.godina);
	} while (temp.godina < 1 || temp.godina > 4);

	printf("\tOcene: ");
	for (int i = 0; i < temp.godina * 3; i++)
		scanf("%d", &temp.ocene[i]);

	push(glava, temp);
}

void push(tCvor** glava, Prijavnica podatak)
{
	tCvor* novi = malloc(sizeof(tCvor));

	novi->podatak = podatak;
	novi->sledeci = *glava;

	*glava = novi;
}

Prijavnica pop(tCvor** glava)
{
	tCvor* temp = *glava;
	Prijavnica ret = temp->podatak;

	*glava = (*glava)->sledeci;
	free(temp);
	
	return ret;
}

void obradi(tCvor** glava)
{
	if (*glava == NULL)
		return;

	Prijavnica temp = pop(glava);

	if (prihvacen(temp))
		printf("%s je dobio/la dom.\n", temp.ime);
	else
		printf("%s nije dobio/la dom.\n", temp.ime);
}

int saberiOcene(Prijavnica x)
{
	int sum = 0;
	for (int i = 0; i < x.godina * 3; i++)
		sum += x.ocene[i];
	return sum;
}

int prihvacen(Prijavnica x)
{
	return (saberiOcene(x) / (x.godina * 3.0)) > 8.0;
}

int unisti(tCvor** glava)
{
	int i = 0;
	while (*glava)
	{
		i++;
		pop(glava);
	}

	return i;
}