/*
* Note:
* Nesto ne radiiiii
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char naziv[50];
	float ocena;
	long long budzet;
	long long zarada;
} Film;

int main()
{
	FILE* fp = fopen("filmovi.txt", "r");
	
	Film* filmovi = malloc(sizeof(Film));
	int n = 0;
	
	while (!feof(fp))
	{
		Film temp;
		fscanf(fp, "%s %f %lld %lld", temp.naziv, &temp.ocena, &temp.budzet, &temp.zarada);
		
		if (temp.ocena > 7)
		{
			filmovi = realloc(filmovi, (n + 1) * sizeof(Film));
			filmovi[n++] = temp;
		}
	}
	
	fp = fopen("najpopularniji.txt", "w");
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (filmovi[i].budzet - filmovi[i].zarada > filmovi[j].budzet - filmovi[j].zarada)
			{
				Film temp = filmovi[i];
				filmovi[i] = filmovi[j];
				filmovi[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		fprintf(fp, "%s %.2f %lld %lld\n", filmovi[i].naziv, filmovi[i].ocena, filmovi[i].budzet, filmovi[i].zarada);
	
	fclose(fp);
	free(filmovi);
	
	return 0;
}
