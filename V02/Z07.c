/*
 * Zadatak 7.
 * 
 * Napisati C program kojim se sa tastature unosi
 * dvocifren broj i ispisuje broj sa obrnutim ciframa.
 * 
 * Primer:
 * > 46
 * 64
 * > 15
 * 51
 */

#include <stdio.h>

int main()
{
	int a, b;

	printf("Unesite dvocifren broj: ");
	scanf("%d", &a);

	b = a % 10;		// Sacuvaj prvu deseticu iz a u b.
	b = b * 10;		// Pomeri prvu deseticu na drugo mesto
	b = b + a/10;	// Pomeri drugu deseticu iz a na prvo mesto i dodaj na b.

	printf("%d", b);

	return 0;
}