/*
* Zadatak 3.
* 
* U ulaznoj datoteci "piloti.txt" dati su podaci o
* pilotima: ime, prezime, broj godina iskustva i broj
* letova. Napisati C program koji cita opisanu ulaznu
* datoteku i u izlaznu datoteku "piloti_out.txt"
* za svakog pilota ispisuje ime, prezime i prosecan broj
* letova po godini. Za pilote koji imaju prosecan
* godisnji broj letova veci od 7, ime i prezime ispisati
* svim velikim slovima.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void toUpperString(char*);

typedef struct
{
	char ime[50];
	char prezime[50];
	unsigned iskustvo;
	unsigned broj_letova;
} Pilot;

int main()
{
	FILE* fp = fopen("piloti.txt", "r");
	
	if (fp == NULL)
	{
		printf("Ulazna datoteka nije uspesno otvorena.\n");
		return 0;
	}
	
	Pilot* piloti = NULL;
	int n = 0;
	
	while (!feof(fp))
	{
		Pilot temp;
		int res = fscanf(fp, "%s %s %u %u", temp.ime, temp.prezime, &temp.iskustvo, &temp.broj_letova);
		
		if (res == 4)
		{
			piloti = realloc(piloti, (n + 1) * sizeof(Pilot));
			piloti[n++] = temp;
		}
	}
	
	fp = fopen("piloti_out.txt", "w");
	
	if (fp == NULL)
	{
		printf("Izlazna datoteka nije uspesno otvorena.\n");
		return 0;
	}
	
	for (unsigned i = 0; i < n; i++)
	{
		float prosecni_letovi = (float) piloti[i].broj_letova / piloti[i].iskustvo;
		
		if (prosecni_letovi > 7)
		{
			toUpperString(piloti[i].ime);
			toUpperString(piloti[i].prezime);
		}
		
		fprintf(fp, "%s %s %.2f\n", piloti[i].ime, piloti[i].prezime, prosecni_letovi);
	}
	
	fclose(fp);
	free(piloti);
	
	return 0;
}

/*
* Pretvara sva slova stringa u velika slova.
*/

void toUpperString(char* s)
{
	for (int i = 0; s[i]; i++)
		s[i] = toupper(s[i]);
}
