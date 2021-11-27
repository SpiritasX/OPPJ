/*
* Zadatak 8.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void kodiraj(char* ul_dat, char* izl_dat);
void dekodiraj(char* ul_dat, char* izl_dat);

int main()
{
	kodiraj("..\\ulazna.txt", "..\\izlazna.txt");
	dekodiraj("..\\izlazna.txt", "..\\ulazna_dekodirana.txt");
	return 0;
}

void kodiraj(char* ul_dat, char* izl_dat)
{
	char str[4000];
	int i = 0;

	FILE* fp;
	fp = fopen(ul_dat, "r");

	while (!feof(fp))
	{
		char c = fgetc(fp);

		if (c >= 'A' && c <= 'Z')
			str[i] = (c - 'A' + 1) % 26 + 'A';
		else if (c >= 'a' && c <= 'z')
			str[i] = (c - 'a' + 1) % 26 + 'a';
		else
			str[i] = c;

		i++;
	}

	fp = fopen(izl_dat, "w");
	fprintf(fp, "%s", str);

	fclose(fp);
}

void dekodiraj(char* ul_dat, char* izl_dat)
{
	char str[4000];
	int i = 0;

	FILE* fp;
	fp = fopen(ul_dat, "r");

	while (!feof(fp))
	{
		char c = fgetc(fp);

		if (c >= 'A' && c <= 'Z')
			str[i] = (c - 'A' + 25) % 26 + 'A';
		else if (c >= 'a' && c <= 'z')
			str[i] = (c - 'a' + 25) % 26 + 'a';
		else
			str[i] = c;

		i++;
	}

	fp = fopen(izl_dat, "w");
	fprintf(fp, "%s", str);

	fclose(fp);
}