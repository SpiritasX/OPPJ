#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp;
	int brojReci = 0;
	char najduzaRec[50] = { 0 }, temp[50] = { 0 };

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