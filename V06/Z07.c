/*
 * Zadatak 7.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program: Korisnik unosi brojeve sve dok ne
 * unese 0. Brojeve treba cuvati u nizu za koji treba
 * da se alocira prostor prvo za jedan element a
 * potom se vrsi realokacija za 2 puta veci prostor
 * (1 > 2 > 4 > 8 > 16 itd.). Ispisati sve unesene
 * clanove niza.
 * 
 * Note:
 * Imam osecaj kao da previse komplikujem ovo...
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int broj, *niz = malloc(sizeof(int)), n = 0, k = 0;

	// Unos brojeva dok se ne unese 0
	printf("Unesite neki broj razlicit od 0\n");
	// Unosimo broj
	printf("> ");
	scanf("%d", &broj);
	do
	{
		// Ako broj nije 0
		if (broj != 0)
		{
			// Dupliraj velicinu niza
			n = pow(2, k++);
			// Povecamo prostor za niz sa novom velicinom
			niz = realloc(niz, n * sizeof(int));

			// n / 2 ce biti prvi novi element koji treba da se unese
			// 1/2=0, 2/2=1, 4/2=2, 8/2=4,...
			for (int i = n / 2; i < n; i++)
			{

				// Sacuvamo broj
				niz[i] = broj;

				// Izadji iz petlje ako je broj jednak sa 0
				if (broj == 0)
					break;
				else
				{
					// Unosimo novi broj
					printf("> ");
					scanf("%d", &broj);
				}
			}
		}
	} while (broj != 0);

	// Ispis niza
	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("]");

	free(niz);

	return 0;
}