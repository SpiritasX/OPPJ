#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char sifra[6];
	float povrsina;
	float cena;
} Parcela;

int main()
{
	FILE* fp = fopen("parcele.txt", "r");
	
	if (fp == NULL)
	{
		printf("Ulazna datoteka se nije otvorila.\n");
		return 0;
	}
	
	Parcela *parcele = malloc(sizeof(Parcela));
	
	int n = 0;
	
	while (!feof(fp))
	{
		parcele = realloc(parcele, (n + 1) * sizeof(Parcela));
		fscanf(fp, "%s %f %f", parcele[n].sifra, &parcele[n].povrsina, &parcele[n].cena);
		n++;
	}
	
	fp = fopen("najskuplje.txt", "w");
	
	if (fp == NULL)
	{
		printf("Izlazna datoteka se nije otvorila.\n");
		return 0;
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (parcele[i].cena / parcele[i].povrsina < parcele[j].cena / parcele[j].povrsina)
			{
				Parcela temp = parcele[i];
				parcele[i] = parcele[j];
				parcele[j] = temp;
			}
		}
		
		if (i < 3)
			fprintf(fp, "%s %.2f %.2f %.2f\n", 
				parcele[i].sifra,
				parcele[i].povrsina,
				parcele[i].cena,
				parcele[i].cena / parcele[i].povrsina);
	}
	
	fclose(fp);
	free(parcele);
	
	return 0;
}
