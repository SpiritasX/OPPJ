/*
* Zadatak 2.
* 
* U ulaznoj datoteci pod nazivom "filmovi.txt"
* dati su zapisi o filmovima: naziv filma, prosecna ocena,
* ukupan budzet i ukupna zarada. Napisati C program
* koji cita ulaznu datoteku i u izlaznu datoteku
* "najpopularniji.txt" ispisuje sve filmove sa
* ocenom vecom od 7, sortirane po opadajucoj
* vrednosti razlike budzeta i zarade.
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
	
	Film* filmovi = NULL;
	int n = 0;
	
	while (!feof(fp))
	{
		Film temp = { 0 };
		fscanf(fp, "%s %f %lld %lld", temp.naziv, &temp.ocena, &temp.budzet, &temp.zarada);
		
		// Ovde ne moramo da proveravamo da li je scanf dobro procitao.
		// Nece uci u if zato sto ce temp.ocena ostati 0 svakako ako ne
		// procita dobro (linija 33, nastavak na prosli zadatak).
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
