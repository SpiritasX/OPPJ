/*
 * Zadatak 11.
 * Napisati C program kojim se unosi brojevi a, b i c
 * i ispituje da li je moguce formirati trougao sa
 * duzinama stranica koje su a, b i c.
 *
 * Note:
 * Trougao ima osobine da zbir bilo koje dve stranice
 * mora biti veci od trece stranice.
 */

#include <stdio.h>

int main()
{
	float a, b, c;

	printf("Unesite stranice trougla: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a + b < c || a + c < b || b + c < a)
		printf("Nije moguce...");
	else
		printf("Moguce je!");

	return 0;
}