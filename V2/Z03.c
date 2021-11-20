#include <stdio.h>

int main()
{
	float metar, jarda, stopa;

	printf("Unesite duzinu u metrima: ");
	scanf("%f", &metar);

	jarda = 1.09 * metar;
	stopa = 3.28 * metar;

	printf("%.3f jardi ili %.3f stopa.", jarda, stopa);

	return 0;
}