/*
 * Zadatak 26.
 * 
 * Dat je niz nizC od maksimalno 80
 * karaktera. Nacrtati dijagram toka algoritma i
 * napisati C program kojim se ucitava n karaktera
 * u nizC i formira nizA, pri cemu su elementi nizA
 * samo slova iz nizC
 * 
 * Note:
 * STA NIJE UREDU SA OVIM??????? POMOC LINIJA 36 ALO
 * odustajem.
 * 
 * Primer:
 * > 6
 * > 1 a X " - 4
 * [ a, X ]
 */

#include <stdio.h>

#define MAX 80

int main()
{
	char nizC[MAX], nizA[MAX];
	int n, a = 0, i;

	// Provera unosa velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	printf("Unesite elemente niza\n");
	for (i = 0; i < n; i++)
	{
		// Unos elemenata niza
		printf("nizC[%d]> ", i);
		scanf("%c", &nizC[i]);

		// Ako je element slovo, sacuvaj u nizA
		if ((nizC[i] >= 65 && nizC[i] <= 90) || (nizC[i] >= 97 && nizC[i] <= 122))
			nizA[a++] = nizC[i];
	}

	// Ispis rezultata
	printf("[ ");
	for (i = 0; i < n; i++)
		printf("%c ", nizC[i]);
	printf("]\n");

	printf("[ ");
	for (i = 0; i < a; i++)
		printf("%c ", nizA[i]);
	printf("]\n");
}