#include <stdio.h>

int main()
{
	float celzijus, farenhajt;

	printf("Unesite temperaturu u farenhajtima: ");
	scanf("%f", &farenhajt);

	celzijus = 5.0/9 * (farenhajt - 32);

	printf("%.2fC", celzijus);

	return 0;
}