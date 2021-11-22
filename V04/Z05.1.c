/*
 * Zadatak 5.1.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji na sahovsku tablu (8x8) postavlja
 * kraljice tako da se ne napadaju medusobno, ali
 * da zajednicki napadaju sva ostala polja na tabli.
 * Polja na kojima je postavljena kraljica treba
 * obeleziti brojem 2, napadnuta polja brojem 1.
 * Ispisati dobijenu matricu na standardni izlaz.
 * 
 * Primer:
 * 2  1  1  1  1  1  1  1
 * 1  1  2  1  1  1  1  1
 * 1  1  1  1  1  1  1  2
 * 1  1  1  1  1  1  1  1
 * 1  1  1  1  1  1  2  1
 * 1  1  1  2  1  1  1  1
 * 1  2  1  1  1  1  1  1
 * 1  1  1  1  2  1  1  1
 */

#include <stdio.h>
#include <time.h>

#define VELICINA 8

int main()
{
	int tabla[VELICINA][VELICINA] = { 0 };
	int x, y, kraj = 1;

	srand(time(NULL));

	// Beskonacna petlja dok se ne popuni cela tabla
	do
	{
		kraj = 1;
		// Petlja koja trazi x i y takvo da nijedna kraljica
		// ne stoji tu ili ne napada to polje
		do
		{
			x = rand() % VELICINA;
			y = rand() % VELICINA;
		} while (tabla[x][y] != 0);

		// Logika iz zadatak 5
		for (int i = 0; i < VELICINA; i++)
			for (int j = 0; j < VELICINA; j++)
				if (i == x || j == y || i == x - y + j || i + j == x + y)
					tabla[i][j] = 1;
		tabla[x][y] = 2;

		// Proverava da li je popunjena cela tabla tako sto ne sme da naidje
		// ni na jedno polje koje je idalje jednako sa 0
		for (int i = 0; i < VELICINA; i++)
			for (int j = 0; j < VELICINA; j++)
				if (tabla[i][j] == 0)
					kraj = 0;
	} while (!kraj);

	// Ispis table
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
			printf(" %d ", tabla[i][j]);
		printf("\n");
	}

	return 0;
}