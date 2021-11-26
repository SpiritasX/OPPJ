/*
 * Zadatak 2.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se citaju broj fudbalskih ekipa, za svaku
 * ekipu: naziv, broj osvojenih bodova i gol razlika, a
 * zatim se ispisuje tabela. Ako dve ekipe imaju isti broj
 * bodova, bolja je ona koja ima vecu gol razliku.
 * 
 * Primer:
 * 
 */

#include <stdio.h>

#define MAXT 10
#define MAXL 50

// Drugaciji nacin da se definise struktura
typedef struct
{
	char naziv[MAXL];
	int bodovi;
	int razlika;
} Tim;

int main()
{
	Tim timovi[MAXT];
	int n;

	// Unos broja timova
	printf("Koliko timova cete uneti?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAXT);

	// Unos timova
	printf("Unesite timove\n");
	for (int i = 0; i < n; i++)
	{
		printf("Tim %d:\n", i + 1);

		// tim.naziv je string
		printf("\tNaziv: ");
		scanf(" %50[^\n]", timovi[i].naziv);

		// tim.bodovi je int
		printf("\tBodovi: ");
		scanf("%d", &timovi[i].bodovi);

		// tim.razlika je int
		printf("\tRazlika: ");
		scanf("%d", &timovi[i].razlika);
	}

	// Koristim bubble sort da sortiram unete timove
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// Ako su bodovi levog tima (u memoriji) manji,
			// zameni levog i desnog
			if (timovi[i].bodovi < timovi[j].bodovi)
			{
				Tim temp = timovi[i];
				timovi[i] = timovi[j];
				timovi[j] = temp;
			}

			// Ako su im bodovi jednaki, onda ih redjaj po razlici
			if (timovi[i].bodovi == timovi[j].bodovi && timovi[i].razlika < timovi[j].razlika)
			{
				Tim temp = timovi[i];
				timovi[i] = timovi[j];
				timovi[j] = temp;
			}
		}
	}

	// Ispis poredjanih timova
	printf("%4s | %20s | %8s | %8s\n", "ID", "NAZIV", "BODOVI", "RAZLIKA");
	printf("-----------------------------------------------------\n");
	for (int i = 0; i < n; i++)
		printf("%4d | %20s | %8d | %8d\n", i, timovi[i].naziv, timovi[i].bodovi, timovi[i].razlika);

	return 0;
}