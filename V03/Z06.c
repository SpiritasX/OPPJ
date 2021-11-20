#include <stdio.h>

int main()
{
	int ocena;

	printf("Unesite ocenu: ");
	scanf("%d", &ocena);

	if (ocena == 5)
		printf("Odlican!\n\n");
	else if (ocena == 4)
		printf("Vrlo dobar!\n\n");
	else if (ocena == 3)
		printf("Dobar!\n\n");
	else if (ocena == 2)
		printf("Dovoljan!\n\n");
	else if (ocena == 1)
		printf("Nedovoljan!\n\n");
	else
		printf("Ocena mora biti izmedju 1 i 5.");

	return 0;
}