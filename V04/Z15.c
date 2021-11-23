/*
 * Zadatak 15.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji od korisnika prihvata niz stringova i
 * ispisuje ih na ekran. Program treba od korisnika
 * najpre da ucita duzinu niza (odnosno broj
 * stringova), a zatim svaki pojedinacni string.
 * 
 * Primer:
 * > 4
 * > abc
 * > bca
 * > cab
 * > abc
 * [ abc bca cab abc ]
 */

#include <stdio.h>

#define MAX 20

int main()
{
	char niz[MAX][100];
	int n;

	// Unos velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// Cita poslednji enter pritisnut......
	getchar();

	// Unos stringova
	printf("Unesite stringove\n");
	for (int i = 0; i < n; i++)
	{
		printf("> ");
		gets(niz[i]);
	}

	// Ispis stringova
	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%s ", niz[i]);
	printf("]");

	return 0;
}