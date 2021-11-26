/*
 * Zadatak 3.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji ucitava niz od n elemenata niza
 * strukture licnost, koja sadrzi sledeca polja: ime,
 * adresa, dan rodjenja, mesec rodjenja i godina rodjenja.
 * Prikazati osobe koje su rodjene u prolece (izmedju 20.
 * marta i 21. juna).
 */

#include <stdio.h>
#include <string.h>

#define MAXL 50
#define MAXS 10

typedef struct
{
	int dan;
	int mesec;
	int godina;
} Datum;

typedef struct
{
	char ime[MAXL];
	char adresa[MAXL];
	Datum datum;
} Osoba;

int main()
{
	Osoba ljudi[MAXS];
	int n;
	char datum[MAXL], *ptr;

	// Unos broja ljudi
	printf("Koliko ljudi zelite?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAXS);

	// Unos ljudi
	printf("Unesite ljude\n");
	for (int i = 0; i < n; i++)
	{
		printf("Osoba %d:\n", i + 1);

		printf("\tIme: ");
		scanf(" %50[^\n]", ljudi[i].ime);
		printf("\tAdresa: ");
		scanf(" %50[^\n]", ljudi[i].adresa);
		// Datum ce se unositi kao string, pa ga
		// pretvaramo u odgovarajuci oblik posle
		printf("\tDatum (dd.mm.yyyy.): ");
		scanf(" %50[^\n]", datum);

		// Postoje mnogo drugih nacina za radjenje
		// ovoga, al koga zanima, drugi nacin je korisno za znati :)
		sscanf(datum, "%d.%d.%d.", &ljudi[i].datum.dan, &ljudi[i].datum.mesec, &ljudi[i].datum.godina);
		
		/*    Drugi nacin
		Razdvajam string na delove svaki put kad naidje na tacku.
		Svaki deo konvertuje u broj i cuva ga u njegovu promenljivu.

		ptr = strtok(datum, ".");
		ljudi[i].datum.dan = atoi(ptr);
		ptr = strtok(NULL, ".");
		ljudi[i].datum.mesec = atoi(ptr);
		ptr = strtok(NULL, ".");
		ljudi[i].datum.godina = atoi(ptr);
		*/
	}

	// Ispis ljudi koji su rodjeni u prolece
	printf("%4s | %20s | %20s | %12s\n", "ID", "IME", "ADRESA", "DATUM");
	printf("-----------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		// Ispisuje se osoba samo ako je mesec mart, maj ili jun.
		// Medjutim, ako je pre 20. marta, preskocice ispis, takodje
		// i za posle 21 juna.
		switch (ljudi[i].datum.mesec)
		{
			case 3:
				if (ljudi[i].datum.dan < 20)
					break;
			case 6:
				if (ljudi[i].datum.dan > 21)
					break;
			case 4:
			case 5:
				// Sad moramo ponovo da spojimo 3 broja iz datum strukture u string
				sprintf(datum, "%02d.%02d.%d", ljudi[i].datum.dan, ljudi[i].datum.mesec, ljudi[i].datum.godina);

				printf("%4d | %20s | %20s | %12s\n", i, ljudi[i].ime, ljudi[i].adresa, datum);
			default:
				break;
		}
	}

	return 0;
}