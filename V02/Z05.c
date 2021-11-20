#include <stdio.h>

#define PI 3.14159

int main()
{
	float r, o, p;

	printf("Unesite poluprecnik: ");
	scanf("%f", &r);

	o = 2*r*PI;
	p = r*r*PI;

	printf("Krug poluprecnika %.2f ima obim %.2f i povrsinu %.2f.", r, o, p);

	return 0;
}