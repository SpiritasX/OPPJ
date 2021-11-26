/*
 * Zadatak 3.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se unosi niz struktura
 * (proizvoljne duzine) tipa Tacka sa poljima:
 * x koordinata i y koordinata. Na standardni izlaz
 * ispisati koordinate centroida (tezista) unesenog
 * niza tacaka.
 * 
 * Primer:
 * > 5
 * > 1 1
 * > 2 3
 * > 5 2
 * > 9 9
 * > 1 0
 * 3.60 3.00
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float x;
	float y;
} Tacka;

int main()
{
	Tacka *tacke;
	int n;
	Tacka centroid = { 0.0, 0.0 };

	// Unos broja tacaka
	printf("Koliko tacaka zelite da unesete?\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1);

	// Sad treba da alociramo n polja u memoriji koja su
	// velicine same strukture a to ce biti prakticno
	// sizeof(float) * 2 i jos * n u ovom slucaju.
	tacke = (Tacka*)malloc(n * sizeof(Tacka));

	// Unos tacaka
	printf("Unesite tacke\n");
	for (int i = 0; i < n; i++)
	{
		printf("> ");
		scanf("%f %f", &tacke[i].x, &tacke[i].y);

		// Da bi nasli centroid, treba da saberemo sve X koordinate
		// i podelimo sa brojem koordinata, i takodje i sve Y za sebe
		centroid.x += tacke[i].x;
		centroid.y += tacke[i].y;
	}

	// Podeli zbir sa brojem tacaka
	centroid.x /= n;
	centroid.y /= n;

	printf("%.2f %.2f", centroid.x, centroid.y);

	// OSLOBODI MEMORIJUUUU
	free(tacke);

	return 0;
}