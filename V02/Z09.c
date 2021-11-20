/*
 * Zadatak 9.
 * 
 * Napisati C program kojim se za zadatu vrednost
 * poluprecnika lopte r izracunava i ispisuje povrsina
 * i zapremina lopte.
 * 
 * S = 4 * r^2 * PI
 * V = (4/3) * r^3 * PI
 * 
 * Primer:
 * > 3.3
 * 136.85 150.53
 * > 5.7
 * 408.28 775.73
 */

#include <stdio.h>

#define PI 3.14159

int main()
{
	float r, S, V;

	printf("Unesite poluprecnik lopte: ");
	scanf("%f", &r);
	
	S = 4*PI*r*r;
	V = 4.0/3*PI*r*r*r;

	printf("Povrsina lopte je %.3f, a zapremin %.3f", S, V);

	return 0;
}