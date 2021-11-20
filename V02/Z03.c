/*
 * Zadatak 3.
 *
 * Napisati C program koji za ulaznu vrednost
 * duzine u metrima ispisuje tu duzinu
 * konvertovanu u jarde i stope.
 *
 * 1m = 1.094 jardi = 3.281 stopa.
 *
 * Primer:
 * > 12.30
 * 13.45 40.35
 * > 22.51
 * 24.62 73.85
*/

#include <stdio.h>

int main()
{
	float metar, jarda, stopa;

	printf("Unesite duzinu u metrima: ");
	scanf("%f", &metar);

	jarda = 1.094 * metar;
	stopa = 3.281 * metar;

	printf("%.2f jardi ili %.2f stopa.", jarda, stopa);

	return 0;
}