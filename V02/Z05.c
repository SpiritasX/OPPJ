/*
 * Zadatak 5.
 * 
 * Napisati C program koji za zadatu duzinu
 * poluprecnika kruga smestenu u promenljivoj r
 * izracunava i prikazuje obim i povrsinu tog kruga.
 * 
 * Primer:
 * > 4.8
 * 30.16 72.38
 * > 2
 * 12.57 12.57
 */

#include <stdio.h>

#define PI 3.14159

int main()
{
	float r, O, P;

	printf("Unesite poluprecnik: ");
	scanf("%f", &r);

	O = 2*r*PI;
	P = r*r*PI;

	printf("Krug poluprecnika %.2f ima obim %.2f i povrsinu %.2f.", r, O, P);

	return 0;
}