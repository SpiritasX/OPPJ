/*
 * Zadatak 9.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program:
 * Treba voditi evidenciju koja mesta u pozoristu su
 * zauzeta. Na pocetku se unose broj redova i broj
 * stolica po redu. Treba alocirati short za svako sediste.
 * Ukoliko je slobodno treba da stoji 0 za to sediste, a 1
 * ako je zauzeto. Na pocetku su sva mesta slobodna.
 * Evidencija zauzetih mesta se vrsi tako sto se unosi
 * lokacija sedista kao par vrednosti (broj_reda,
 * broj_mesta_u_redu). Rad se zavrsava kada se za bar
 * jedan broj u paru unese broj manji od 1. Nakon
 * prekida unosa, treba ispisati sva sedista koja su
 * zauzeta i ispisati broj uzastopno zauzetih mesta.
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main()
{
	int n, m,
		brojac = 0,
		x, y,
		**sedista;

	// Unos broja redova i kolona sedista
	printf("Unesite broj redova i kolona mesta\n");
	do
	{
		printf("> ");
		scanf("%d %d", &n, &m);
	} while (n < 1 || m < 1);

	// Alokacija matrice
	// Ovi pokazivaci ne moraju da budu nula
	sedista = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		// Dok ovi moraju biti nula zato sto se tako
		// trazilo u zadatku!
		sedista[i] = calloc(m, sizeof(int));

	// Unos zauzetih sedista
	printf("Unesite sedista koja su zauzeta (x, y)\n");
	do
	{
		printf("> ");
		scanf("%d %d", &x, &y);

		// Ako je x ili y vece od moguce vrednosti, greska
		if (x > n || y > m)
		{
			printf("Pogresan unos...\n");
		}
		// Ako je x ili y manje od 1, izadji iz petlje
		else if (x < 1 || y < 1)
			break;
		// Ako uneta pozicija nije zauzeta, zauzmi je
		else if (sedista[x - 1][y - 1] != 1)
		{
			brojac++;
			sedista[x - 1][y - 1] = 1;
		}
		// Ako jeste zauzeta, greska
		else
			printf("To sediste je vec zauzeto.\n");
	} while (TRUE);

	// Ispis matrice
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%2d", sedista[i][j]);
		}
		printf("\n");

		// Oslobadjanje ispisane vrste
		free(sedista[i]);
	}
	// Oslobadjanje cele matrice
	free(sedista);

	printf("Broj upravo zauzetih sedista je %d.", brojac);

	return 0;
}