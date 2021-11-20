/*
 * Zadatak 6.
 * 
 * Sledeci primer, ali pomocu if selekcije.
 * 
 * switch (ocena) {
 *     case 5:
 *         printf("Odlican!\n\n");
 *         break;
 *     case 4:
 *         printf("Vrlo dobar!\n\n");
 *         break;
 *     case 3:
 *         printf("Dobar!\n\n");
 *         break;
 *     case 2:
 *         printf("Dovoljan!\n\n");
 *         break;
 *     case 1:
 *         printf("Nedovoljan!\n\n");
 *         break;
 *     default:
 *         printf("Ocena mora biti izmedju 1 i 5.");
 * }
 */

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