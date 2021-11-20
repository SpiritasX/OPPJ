/*
 * Zadatak 14.1.
 * 
 * Napisati C program koji proverava da li korisnik
 * zna da sabira. Nasumicno se generisu 2 cela broja
 * iz [0, 100] i potom se od korisnika trazi da unese
 * tacan zbir brojeva. Svaki put kada ne unese tacan
 * zbir, program ispisuje "Smotan si... Budi
 * vise kao FTN moto!". Ako korisnik iz prvog
 * pokusaja upise rezultat kako treba, ispisuje se
 * poruka "Odlicno!", ako pogresi 1-2 "Nije strasno."
 * a u suprotnom "Krajnje vreme je bilo...".
 */

#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int a = rand() % 101;
	int b = rand() % 101;
	int zbir, brojGresaka = 0;

	do
	{
		printf("%d + %d = ", a, b);
		scanf("%d", &zbir);

		if (a + b != zbir)
		{
			printf("Smotan si... Budi vise kao FTN moto!\n");
			brojGresaka++;
		}
	} while (a + b != zbir);

	if (brojGresaka == 0)
		printf("Odlicno!");
	else if (brojGresaka <= 2)
		printf("Nije strasno.");
	else
		printf("Krajnje vreme je bilo...");
	return 0;
}