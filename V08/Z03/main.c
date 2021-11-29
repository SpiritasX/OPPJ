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
	
	Pilot* piloti = malloc(sizeof(Pilot));
	int n = 0;
	
	while (!feof(fp))
	{
		piloti = realloc(piloti, (n + 1) * sizeof(Pilot));
		fscanf(fp, "%s %s %u %u", piloti[n].ime, piloti[n].prezime, &piloti[n].iskustvo, &piloti[n].broj_letova);
		n = n + 1;
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

void toUpperString(char* s)
{
	for (int i = 0; s[i]; i++)
		s[i] = toupper(s[i]);
}
