/*
 * Zadatak 4.
 * 
 * Napisati C program koji za ulaznu vredost
 * promenjive a izrazenu u evrima izracunava i
 * prikazuje ekvivaletnu vrednost u dolarima.
 * 
 * 1 EUR = 1.13 USD
 * 
 * Primer:
 * > 2.5
 * 2.8
 * > 12
 * 13.54
 */

#include <stdio.h>

int main()
{
	float euro, dolar;

	printf("Unesite evre: ");
	scanf("%f", &euro);

	dolar = 1.13 * euro;

	printf("Vrednost u dolarima je: %.1f", dolar);

	return 0;
}