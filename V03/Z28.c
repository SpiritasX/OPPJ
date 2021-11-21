/*
 * Zadatak 28.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji za (sa standardnog ulaza) zadati
 * prirodni broj N (ne veci od 4 milijarde) nalazi i
 * ispisuje sumu prve i poslednje cifre.
 * 
 * Primer:
 * > 12568296
 * 1 6
 * > 906782725
 * 9 5
 */

#include <stdio.h>

int main()
{
	// int nema dovoljno bitova da sacuva toliko velik broj!
	unsigned long N;
	int prva, poslednja;

	// Provera unosa broja
	printf("Unesite prirodan broj (do 4 milijarde)\n");
	do
	{
		printf("> ");
		scanf("%ul", &N);
	} while (N < 1 || N > 4000000000);

	poslednja = N % 10;
	// Samo za jednocifrene brojeve...
	prva = poslednja;

	// Pomera cifre za jedan u desno dok ne dodje do poslednje cifre.
	while (N > 10)
	{
		prva = N / 10;
		N /= 10;
	}

	printf("%d %d", prva, poslednja);
}