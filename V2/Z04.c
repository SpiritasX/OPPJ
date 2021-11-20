#include <stdio.h>

int main()
{
	float euro, dolar;

	printf("Unesite evre: ");
	scanf("%f", &euro);

	dolar = 1.16 * euro;

	printf("Vrednost u dolarima je: %.1f", dolar);

	return 0;
}