/*
 * Zadatak 2.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program kojim se ucitava niz od n elemenata, a
 * zatim omoguciti korisniku da bira neku od
 * sledecih radnji:
 *     1. Izracunavanje sume elemenata niza
 *     2. Racunanje srednje vrednosti elemenata
 *     3. Nalazenje minimuma
 *     4. Nalazenje maksimuma
 */

#include <stdio.h>
#define MAX 20

int meni();
int sum(int*, int);
float avg(int*, int);
int min(int*, int);
int max(int*, int);
void ispisNiza(int*, int);

int main()
{
	int izbor, niz[MAX], n;

	printf("Unesite velicinu niza\n");
	do
	{
		printf("> ");
		scanf("%d", &n);
	} while (n < 1 || n > MAX);

	printf("Unesite elemente niza\n");
	for (int i = 0; i < n; i++)
	{
		printf("niz[%d]> ", i);
		scanf("%d", &niz[i]);
	}

	do
	{
		izbor = meni();

		switch (izbor)
		{
			case 1:
				printf("Zbir svih clanova niza je %d\n", sum(niz, n));
				break;
			case 2:
				printf("Srednja vrednost svih clanova niza je %.2f\n", avg(niz, n));
				break;
			case 3:
				printf("Najmanji clan niza je %d\n", min(niz, n));
				break;
			case 4:
				printf("Najveci clan niza je %d\n", max(niz, n));
				break;
			// Ovde umesto break moze i samo return 0 odma da se stavi
			// i zavrsi program umesto da ide do kraja petlje.
			case 5:
				break;
			default:
				printf("Uneli ste pogresan izbor.\n");
		}

		ispisNiza(niz, n);

	} while (izbor != 5);

	return 0;
}

/*
* Ispisuje sve opcije za korisnika i cita njihov izbor.
*/
int meni()
{
	int izbor = 0;

	printf("Opcije:\n\n");
	printf("\t1. Izracunavanje sume.\n");
	printf("\t2. Izracunavanje srednje vrednosti.\n");
	printf("\t3. Najmanji element niza.\n");
	printf("\t4. Najveci element niza.\n");
	printf("\t5. Izlaz iz programa.\n");
	printf("> ");
	scanf("%d", &izbor);

	return izbor;
}

/*
* Sabira n elemenata celobrojnog niza.
*/
int sum(int* niz, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += niz[i];

	return sum;
}

/*
* Racuna srednju vrednost n elemenata
* prosledjenog celobrojnog niza.
*/
float avg(int* niz, int n)
{
	return (float)sum(niz, n) / n;
}

/*
* Pronalazi najmanji element od prvih n
* elemenata celobrojnog niza.
*/
int min(int* niz, int n)
{
	int min = niz[0];
	for (int i = 1; i < n; i++)
		if (niz[i] < min)
			min = niz[i];

	return min;
}

/*
* Pronalazi najveci element od prvih n
* elemenata celobrojnog niza.
*/
int max(int* niz, int n)
{
	int max = niz[0];
	for (int i = 1; i < n; i++)
		if (niz[i] > max)
			max = niz[i];

	return max;
}

/*
* Ispisuje prvih n clanova celobrojnog niza.
*/
void ispisNiza(int* niz, int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("]\n");
}