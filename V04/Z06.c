/*
 * Zadatak 6.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * koji modeluje celijski automat poznat kao Langtonov
 * mrav. Zamislite neogranicen prostor podeljen na 2D
 * mrezu ravnomernih kvadrata koji mogu biti beli ili crni.
 * Za potrebe zadatatka neka taj prostor bude matrica
 * 1001x1001 u cijem je centru koordinatni pocetak. Na
 * pocetku su svi crni. U centru ovog polja je Lengtonov
 * mrav usmeren nagore. U svakom koraku mrav skrene
 * 90 stepeni ulevo ako je polje (na kojem stoji) crno i 90
 * stepeni udesno ako je polje belo. Zatim obrne boju
 * polja (na kojem stoji) i pomeri se napred za jedan
 * kvadrat. Za zadati broj koraka n ispisati poziciju
 * na kojoj ce se mrav naci nakon n koraka, a ako napusti
 * tablu 1001x1001 ispisati da je izasao van prostora.
 */

#include <stdio.h>

#define VELICINA 1001
#define BELA 0
#define CRNA 1

enum 
{
	DOLE,
	LEVO,
	GORE,
	DESNO
};

int main()
{
	char matrica[VELICINA][VELICINA] = { BELA };
	int dir = GORE, n, i;
	int x = (VELICINA - 1) / 2,
		y = (VELICINA - 1) / 2;

	// Unos broja koraka
	printf("Unesite broj koraka\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 0);

	// Prolazi kroz n koraka
	for (i = 0; i < n; i++)
	{
		// Ako stoji na belom
		if (matrica[x][y] == BELA)
		{
			// Obrni boju polja na kom stojis
			matrica[x][y] = CRNA;
			// Okreni se za 90 stepeni u desno
			dir = (dir + 1) % 4;
		}
		// Ako stoji na crnom
		else
		{
			// Obrni boju polja na kom stojis
			matrica[x][y] = BELA;
			// Okreni se za 90 stepeni u levo
			dir = (dir + 3) % 4;
		}

		// Pomeri se za jedno polje u napred zavisno od smera
		switch (dir)
		{
			case GORE:
				y--;
				break;
			case DOLE:
				y++;
				break;
			case LEVO:
				x--;
				break;
			case DESNO:
				x++;
				break;
		}

		// Proveri da li je mrav izasao izvan granica
		if (!(x >= 0 && x < VELICINA) || !(y >= 0 && y < VELICINA))
		{
			printf("Izasao si sa table.");
			return 0;
		}
	}

	printf("Mrav se pomerio %d puta i stao na poziciji (%d, %d) u pravcu %d", i, x, y, dir);

	return 0;
}