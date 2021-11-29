/*
* Zadatak 1.
* 
* U ulaznoj datoteci pod nazivom "parcele.txt"
* dati su podaci o parcelama zemljista: sifra parcele (5
* znakova), povrsina parcele i cena. Napisati C program
* koji ucitava podatke o parcelama i u izlaznu datoteku
* "najskuplje.txt" ispisuje sifre 3 parcele sa
* najvecom cenom po metru kvadratom.
*/

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
	
	// Mora da se postavi na NULL da bi realloc radio!
	Parcela *parcele = NULL;
	
	int n = 0;
	
	while (!feof(fp))
	{
		// Citamo prvo u pomocnu promenljivu a to posle cuvamo tek ako
		// je sve uredu sa citanjem.
		Parcela temp = { 0 };
		int res = fscanf(fp, "%s %f %f", temp.sifra, &temp.povrsina, &temp.cena);

		// scanf funkcije vracaju broj uspesno procitanih parametara
		// U ovom slucaju, citamo 3 parametra i ako rezultat nije 3,
		// nesto nije uredu sa citanjem.
		if (res == 3)
		{
			parcele = realloc(parcele, (n + 1) * sizeof(Parcela));
			parcele[n++] = temp;
		}
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
			fprintf(fp, "%s %.2f %.2f\n", 
				parcele[i].sifra,
				parcele[i].povrsina,
				parcele[i].cena);
	}
	
	fclose(fp);
	free(parcele);
	
	return 0;
}
