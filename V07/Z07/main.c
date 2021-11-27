/*
* Zadatak 7.
* 
* Nacrtati dijagram toka algoritma i napisati C program
* kojim se iz ulazne datoteke ucitava niz studenata koji
* su polozili ispit (indeks, ime, ocena).
*	- U izlaznu datoteku "najbolji.txt" ispisati
*	  podatke o studentu sa najvecom ocenom
*	- U izlaznu datoteku "najlosiji.txt" ispisati
*	  podatke o studentu sa najnižom ocenom
*	- Na standardnom izlazu ispisati prosecnu ocenu
*	  svih studenata
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int indeks;
	char ime[50];
	char prezime[50];
	int ocena;
} Student;

int main()
{
	FILE* fp = fopen("..\\ulazna.txt", "r");
	Student* studenti = malloc(sizeof(Student));
	int n = 0, idxMin, idxMax;
	float prosek = 0;

	while (!feof(fp))
	{
		Student temp;
		fscanf(fp, "%d %s %s %d",
			&temp.indeks,
			temp.ime,
			temp.prezime,
			&temp.ocena);

		if (temp.ocena >= 6)
		{
			studenti = realloc(studenti, (n + 1) * sizeof(Student));
			studenti[n] = temp;

			if (n == 0)
			{
				idxMin = 0;
				idxMax = idxMin;
			}
			else if (studenti[n].ocena > studenti[idxMax].ocena)
				idxMax = n;
			else if (studenti[n].ocena < studenti[idxMin].ocena)
				idxMin = n;

			prosek += studenti[n].ocena;

			n++;
		}
	}

	fp = fopen("..\\najbolji.txt", "w");
	fprintf(fp, "%d %s %s %d",
		studenti[idxMax].indeks,
		studenti[idxMax].ime,
		studenti[idxMax].prezime,
		studenti[idxMax].ocena);

	fp = fopen("..\\najlosiji.txt", "w");
	fprintf(fp, "%d %s %s %d",
		studenti[idxMin].indeks,
		studenti[idxMin].ime,
		studenti[idxMin].prezime,
		studenti[idxMin].ocena);

	fp = fopen("..\\izlaz.txt", "w");
	for (int i = 0; i < n; i++)

	fclose(fp);
	free(studenti);

	printf("Prosek: %.2f", prosek / n);

	return 0;
}