/*
 * Zadatak 2.
 * 
 * Napisati C program koji za dve ulazne celobrojne
 * promenljive, odreduje i ispisuje vrednost manje
 * na standardni izlaz.
 * 
 * Primer:
 * > 2 5
 * 2
 * > 12 9
 * 9
 */

#include <stdio.h>

int main()
{
	int a, b;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	printf("Manji broj je %d", (a < b) ? a : b);
}