/*
 * Zadatak 6.
 * 
 * Napisati C program koji za tri ulazne pozitivne
 * celobrojne vrednosti izracunava, a zatim ispisuje njihovu
 * aritmeticku, harmonijsku i geometrijsku sredinu.
 * 
 * Formule:
 * https://en.wikipedia.org/wiki/Mean#:~:text=References-,Types%20of%20means,-%5Bedit%5D
 * 
 * Primer:
 * > 1 5 6
 * 4.000 3.107 2.195
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, z;
	float a, // Aritmeticka sredina
		  g, // Geometrijska sredina
		  h; // Harmonijska sredina

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &x, &y, &z);

	a = (x + y + z) / 3.0;
	g = pow(x * y * z, 1/3.0);
	h = 3.0 / (1.0/x + 1.0/y + 1.0/z);

	printf("Aritmeticka sredina: %.3f\n" 
		   "Geometrijska sredina : % .3f\n"
		   "Harmonijska sredina : % .3f", a, g, h);

	return 0;
}