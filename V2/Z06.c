#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, z;
	float a, g, h;

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &x, &y, &z);

	a = (x + y + z) / 3.0;
	g = pow(x * y * z, 1/3.0);
	h = 3.0 / (1.0/x + 1.0/y + 1.0/z);

	printf("Aritmeticka sredina: %.3f\nGeometrijska sredina: %.3f\nHarmonijska sredina: %.3f", a, g, h);

	return 0;
}