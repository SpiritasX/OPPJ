/*
 * Zadatak 2.
 * 
 * Modifikovati Zadatak 1 tako da koristi dinamicku
 * alokaciju memorije.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *niz, n, *pok;

	// Unos velicine niza
	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1);

	// Sva logika je identicna prvom zadatku,
	// samo sto sad umesto staticki alociranog niza
	// sa uglastim zagradama na pocetku, ovde
	// cemo pomeriti pokazivac "niz" da pokazuje
	// na novo alociranih n*4 bajtova memorije.
	niz = (int*)malloc(n * sizeof(int));

	pok = niz;

	printf("Unesite elemente niza\n");
	for (int i = 0; i < n; i++)
	{
		printf("> ");
		scanf("%d", pok + i);
	}

	for (int i = 0; i < n / 2; i++)
	{
		int* adresaSaPocetkaNiza = pok + i;
		int* adresaSaKrajaNiza = pok + n - 1 - i;

		int temp = *adresaSaPocetkaNiza;
		*adresaSaPocetkaNiza = *adresaSaKrajaNiza;
		*adresaSaKrajaNiza = temp;
	}

	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("]");

	// Jako je vazno da oslobodimo memoriju koju smo koristili!
	free(niz);
}