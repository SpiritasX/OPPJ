/*
 * Zadatak 1.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * kojim se ucitava niz tacaka u ravni (maksimalno 30
 * tacaka). Potom je potrebno:
 *     - pronaci tacku koja je najbliza koordinatnom pocetku
 *     - pronaci tacku koja je najudaljenija od koordinatnog pocetka
 *     - pronaci par medusobno najudaljenijih tacaka
 * 
 * Primer:
 * > 5
 * > 1 1
 * > 3 2
 * > 9 8
 * > -4 2
 * > 1 0
 * (1, 0) -> 1.00
 * (9, 8) -> 12.04
 * (9, 8), (-4, 2) -> 14.32
 */

#include <stdio.h>
#include <math.h>

#define MAX 30

struct Tacka
{
	float x;
	float y;
};

int main()
{
	struct Tacka tacke[MAX];
	int n, t1, t2, idxMin, idxMax;
	float dx, dy, dist, minDist, maxDist, max;

	// Unos broja tacaka
	printf("Unesite koliko tacaka zelite\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	// Unos tacaka
	printf("Unesite tacke\n");
	for (int i = 0; i < n; i++)
	{
		// Unos tacke
		printf("(x, y)> ");
		scanf("%f %f", &tacke[i].x, &tacke[i].y);

		// Formula za blizinu tacke je pitagorina teorema
		// Koren od zbira kvadrata X i Y, pojednostavljeno
		dist = sqrt(pow(tacke[i].x, 2) + pow(tacke[i].y, 2));

		// Pretpostavi da je prva tacka najbliza i najdalja od KP
		if (i == 0)
		{
			minDist = dist;
			maxDist = dist;
			idxMin = 0;
			idxMax = 0;
		}
		// Za svaku drugu tacku, trazi najmanju razdaljinu
		else if (dist < minDist)
		{
			minDist = dist;
			idxMin = i;
		}
		// Takodje trazi najdalju
		else if (dist > maxDist)
		{
			maxDist = dist;
			idxMax = i;
		}
	}

	// Da bi pronasli dve medjusobno najudaljenije tacke,
	// moramo da imam ugnjezdenu petlju i poredimo svake dve
	// tacke. Samu distancu cuvamo u max, i moramo da sacuvamo
	// i indekse tacaka koje su toliko udaljene.
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// Sada moramo da koristimo pun oblik formule za distancu
			// izmedju dve tacke. Prvo cemo izracunati X i Y razliku
			// izmedju njih
			dx = tacke[i].x - tacke[j].x;
			dy = tacke[i].y - tacke[j].y;
			// Takodje nam treba samo apsolutna vrednost toga
			dx = fabs(dx);
			dy = fabs(dy);

			// I sad mozemo da izracunamo distancu pitagorom.
			dist = sqrt(pow(dx, 2) + pow(dy, 2));

			// Pretpostavicemo da je razmak izmedju prve dve tacke najveci
			if (i == 0)
			{
				max = dist;
				t1 = 0;
				t2 = 1;
			}
			// Uporedimo sa prethodnom najvecom distancom
			if (dist > max)
			{
				max = dist;
				t1 = i;
				t2 = j;
			}
		}
	}

	// Ispis rezultata
	printf("Tacka najbliza KP je (%.1f, %.1f) sa distancom od %.2f.\n", tacke[idxMin].x, tacke[idxMin].y, minDist);
	printf("Tacka najdalje od KP je (%.1f, %.1f) sa distancom od %.2f.\n", tacke[idxMax].x, tacke[idxMax].y, maxDist);
	printf("Dve tacke medjusobno najudaljenije su (%.1f, %.1f) i (%.1f, %.1f) sa distancom od %.2f.\n",
		tacke[t1].x, tacke[t1].y, tacke[t2].x, tacke[t2].y, max);

	return 0;
}