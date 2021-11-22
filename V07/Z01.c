/*
 * Zadatak 1.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se ucitavaju duzine kateta i racuna
 * duzinu hipotenuze. Za racunanje hipotenuze napisati
 * funkciju hipotenuza.
 * 
 * Primer:
 * > 3 4
 * 5.00
 * > 1 2
 * 2.24
 */

#include <stdio.h>
#include <math.h>

// Funkcija kao ulazne parametre uzima katete
// a vraca koren od zbira njihovih kvadrata, tj.
// hipotenuzu po pitagorinoj teoremi
float hipotenuza(float a, float b)
{
	return sqrt(a * a + b * b);
}

int main()
{
	float a, b, c;

	printf("Unesite katete trougla\n> ");
	scanf("%f %f", &a, &b);

	c = hipotenuza(a, b);

	printf("%.2f", c);

	return 0;
}