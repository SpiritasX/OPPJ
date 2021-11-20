/*
 * Zadatak 9.
 * 
 * Tri tacke su zadate koordinatama u ravni.
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se izracunava povrsina
 * paralelograma ciji su vrhovi date tacke.
 * 
 * Note:
 * Nisam siguran sta su vrhovi paralelograma pa sam
 * ja gledao da se unose tacke A, B i C sa slike ispod.
 * 
 *   D----C
 *  /    /
 * A----B
 * 
 * Takodje sam povrsinu izracunao preko determinante.
 * 
 * Primer:
 * > 0 0
 * > 5 0
 * > 8 3
 * 18.49
 */

#include <stdio.h>

int main()
{
	float x1, y1,
	      x2, y2,
	      x3, y3,
	      x4, y4;
	float p = 0;

	printf("Unesite tri tacke (x, y) jednu po jednu: \n");
	scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	scanf("%f %f", &x3, &y3);

	x4 = x3 + x1 - x2;
	y4 = y3 + y1 - y2;

	p += x1*y2 + x2*y3 + x3*y4 + x4*y1;
	p -= x2*y1 + x3*y2 + x4*y3 + x1*y4;
	p *= 0.5;

	printf("Povrsina = %.3f", p);

	return 0;
}