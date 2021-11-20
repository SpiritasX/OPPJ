#include <stdio.h>

int main()
{
	int godina;

	printf("Unesite godinu (YYYY): ");
	scanf("%d", &godina);

	if (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0))
		printf("Prestupna!!");
	else
		printf("Nije prestupna...");

	return 0;
}