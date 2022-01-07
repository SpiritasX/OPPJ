/*
* Zadatak 3.
* 
* Napisati C program kojim se vrsi evaluacija
* celobrojnog izraza datog u postfiksnoj notaciji.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cvor
{
	char podatak[10];
	struct cvor* sledeci;
} tCvor;

/// ======================IGNORISI======================
/// <summary>
///		Uneti string razdvaja na delove i cuva ga u stek.
/// </summary>
/// 
/// <example>
/// <code>
///		str = "2 3 + 5 * 7 9 - /"
///		{"2", "3", "+", "5", "*", "7", "9", "-", "/"}
/// </code>
/// </example>
/// 
/// <param name="glava">
///		Pokazivac na pocetak steka
/// </param>
/// <param name="str">
///		String koji parsiramo
/// </param>
void parse(tCvor**, char*);
void push(tCvor**, char*);
char* pop(tCvor**);
float calculate(tCvor**);

int main()
{
	tCvor* glava = NULL;

	char str[50];
	float rez;

	do
	{
		// dozvoljeni karakteri su brojevi, razmak, +, -, * i /
		printf("> ");
		scanf("%49[^\n]%*c", str);

		// koristi -1 za izlazak iz programa
		if (!strcmp("-1", str))
			break;

		parse(&glava, str);

		rez = calculate(&glava);

		printf("Rezultat = %.2f\n", rez);
	} while (1);

	return 0;
}

// Dodavanje na pocetak liste
void push(tCvor** glava, char* podatak)
{
	tCvor* novi = malloc(sizeof(tCvor));

	strcpy(novi->podatak, podatak);
	novi->sledeci = *glava;

	*glava = novi;
}

// Citanje sa pocetka liste
char* pop(tCvor** glava)
{
	static char str[50];

	tCvor* temp = *glava;
	*glava = (*glava)->sledeci;
	strcpy(str, temp->podatak);

	free(temp);

	return str;
}

void parse(tCvor** glava, char* str)
{
	char* podatak;
	int size = 0, i = 0;

	podatak = strtok(str, " ");

	while(podatak != NULL)
	{
		push(glava, podatak);
		podatak = strtok(NULL, " ");
	}
}

// Rekurzivna funkcija koja izvrsava racun od zadatog steka
// Svaka operacija se izvrsava nad dva broja pa se tako ova
// funkcija rekurzivno poziva dok ne dodje do broja, a svaki
// put kad naidje na operaciju, poziva se da se nadje svaki
// broj posebno.
// 
// Primer: "2 3 + 5 * 7 9 - /"
// 1. () / () operacija deljenja
// 2. () / (() - ()) operacija oduzimanja u desnom operandu
// 3. () / ((7) - (9)) operacija oduzimanja se vrsi nad brojevima 7 i 9
// 4. (() * ()) / (7 - 9) operacija mnozenja u levom operandu (operacije deljenja)
// 5. ((() + ()) * (5)) / (7 - 9) operacija mnozenja se vrsi nad 5 i zbirom
// 6. (((2) + (3)) * 5) / (7 - 9) operacija sabiranja se vrsi nad 2 i 3
// 7. ((2 + 3) * 5) / (7 - 9)
// 
// Na kraju dobijamo infiks notaciju iz koje se lako vidi resenje ovog primera
float calculate(tCvor** glava)
{
	char str[10];
	strcpy(str, pop(glava));
	int broj;

	if (isdigit(str[0]))
		return atoi(str);
	else
	{
		// Operacije oduzimanja i deljenja nisu komutativne pa moraju da traze
		// prvo desni pa levi operand za razliku od sabiranja i mnozenja.
		switch (str[0])
		{
		case '+':
			return calculate(glava) + calculate(glava);
		case '-':
			return -calculate(glava) + calculate(glava);
		case '*':
			return calculate(glava) * calculate(glava);
		case '/':
			return (1.0 / calculate(glava)) * calculate(glava);
		}
	}
}