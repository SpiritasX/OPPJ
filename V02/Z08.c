/*
 * Zadatak 8.
 * 
 * Napisati C program kojim se izracunava i ispisuje
 * vrednost kamate za zadatu vrednost glavnice G,
 * kamatne stope p (u procentima) i broja godina
 * stednje god. Vrednosti G, p i god se unose sa
 * tastature.
 * 
 * Formula:
 * https://ekonomskaalibunar.files.wordpress.com/2013/03/prost-kamatni-rac48dun.pdf
 * 
 * Primer:
 * > 12000 6 3
 * 2160
 */

#include <stdio.h>

int main()
{
	float G, p, god;

	printf("Unesite glavicu, kamatnu stopu i broj godina stednje: ");
	scanf("%f %f %f", &G, &p, &god);

	printf("Kamata = %.2f", G*p*god/100.0);

	return 0;
}