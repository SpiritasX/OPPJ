/*
 * Zadatak 8.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * kojim se ispisuje:
 *     a) prvih k znakova string promenljive s;
 *     b) poslednjih k znakova string promenljive s;
 *     c) deo stringa s od pozicije p na duzini k.
 * 
 * Primer:
 * > Hello, World!
 * > 6
 * > 3
 * Hello,
 * World!
 * lo, Wo
 */

#include <stdio.h>

int main()
{
	int k, p, n = 0;
	char s[100];

	// Unos stringa
	printf("Unesite string\n> ");
	scanf("%99[^\n]", s);

	// Velicina stringa
	while (s[++n]);

	// Unos k
	printf("Unesite neko k\n");
	do
	{
		printf("> ");
		scanf("%d", &k);
	} while (k < 0 || k > n - 1);

	// Unos p
	printf("Unesite neko p\n");
	do
	{
		printf("> ");
		scanf("%d", &p);
	} while (p < 0 || p > n - 1 - k);

	// a) petlja od 0 do k
	for (int i = 0; i < k; i++)
		printf("%c", s[i]);
	printf("\n");

	// b) petlja od n - k do n
	for (int i = n - k; i < n; i++)
		printf("%c", s[i]);
	printf("\n");

	// c) petlja od p do p + k
	for (int i = p; i < p + k; i++)
		printf("%c", s[i]);
	printf("\n");

	return 0;
}