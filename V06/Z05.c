/*
 * Zadatak 5.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se unosi niz struktura tipa
 * Student sa poljima: ime, prezime, broj polozenih
 * ispita i niz ocena sa tih ispita. Potom se racuna i
 * ispisuje za svakog studenta: ime, prezime i
 * prosecna ocena. Za niz struktura i niz ocena
 * unutar strukture koristiti dinamicku alokaciju
 * memorije.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char ime[50];
	char prezime[50];
	int polozeniIspiti;
	int* ocene;
} Student;

int main()
{
	Student* studenti;
	int n;
	float *prosek;

	// Unos broja studenata
	printf("Koliko studenata zelite?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1);

	// Alociranje niza struktura
	studenti = (Student*)malloc(n * sizeof(Student));
	// Alociranje niza za prosek
	// Koristim calloc ovde zato sto mi treba da sve
	// vrednosti niza budu jednake sa 0
	prosek = (float*)calloc(n, sizeof(float));

	// Unos studenata
	printf("Unesite studente\n");
	for (int i = 0; i < n; i++)
	{
		printf("Student %d:\n", i + 1);
		printf("\tIme: ");
		scanf(" %50[^\n]", studenti[i].ime);
		printf("\tPrezime: ");
		scanf(" %50[^\n]", studenti[i].prezime);
		printf("\tBroj polozenih ispita: ");
		scanf(" %d", &studenti[i].polozeniIspiti);

		// Alociramo niz u odnosu na broj polozenih ispita
		studenti[i].ocene = (int*)malloc(studenti[i].polozeniIspiti * sizeof(int));

		// Unosimo ocene studenta
		// Ocene su niz pa kroz njih prolazimo sa ocene[j]
		// a taj niz se nalazi u strukturi studenti[i] zato
		// sto to predstavlja jednog studenta (i-tog studenta)
		printf("\tOcene: ");
		for (int j = 0; j < studenti[i].polozeniIspiti; j++)
		{
			scanf("%d", &studenti[i].ocene[j]);
			prosek[i] += studenti[i].ocene[j];
		}
	}

	// Ispis studenata
	printf("%20s | %20s | %10s\n", "IME", "PREZIME", "PROSEK");
	printf("-----------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("%20s | %20s | %10.2f\n", studenti[i].ime, studenti[i].prezime, prosek[i] / studenti[i].polozeniIspiti);

		// Mozemo da iskoristimo ovaj loop da se oslobadjamo ispisane memorije
		free(studenti[i].ocene);
	}

	// Na kraju se oslobodimo nizova koje smo zauzeli
	free(studenti);
	free(prosek);
	return 0;
}