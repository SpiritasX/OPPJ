/*
* Zadatak 6.
* 
* Nacrtati dijagram toka algoritma i napisati C program
* za prebrojavanje reci iz ulazne datoteke. U izlaznoj
* datoteci ispisati broj reci i najduzu pronadjenu rec.
*/

#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp;
	int brojReci = 0;
	char najduzaRec[50] = { 0 }, temp[50] = { 0 };

	// U opstem slucaju, moze samo ime datoteke da se koristi
	// "ulazna_06.txt"
	fp = fopen("..\\files\\ulazna_06.txt", "r");

	if (fp == NULL)
	{
		printf("Doslo je do greske prilikom otvaranja ulazne.");
		return 0;
	}

	while (fscanf(fp, "%s", temp) != EOF)
	{
		brojReci++;

		if (strlen(temp) > strlen(najduzaRec))
			strcpy(najduzaRec, temp);
	}

	fp = fopen("..\\files\\izlazna_06.txt", "w");

	if (fp == NULL)
	{
		printf("Doslo je do greske prilikom otvaranja izlazne.");
		return 0;
	}

	fprintf(fp, "%d %s", brojReci, najduzaRec);

	fclose(fp);
	return 0;
}