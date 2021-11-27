/*
* Zadatak 5.
* 
* Nacrtati dijagram toka algoritma i napisati C
* program koji ucitava prirodan broj n, a zatim koristeci
* funkciju prost stampa sve proste brojeve manje od
* datog broja n.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prost(int);

int main()
{
	int n;

	printf("Unesite prirodan broj\n> ");
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
		if (prost(i))
			printf("%d ", i);

	return 0;
}

/*
* Cim naidje na prvi broj koji deli x, znaci
* da x nije prost broj i vraca false. Ako ne
* naidje ni na jedan delioc, na kraju vrati true.
*/
bool prost(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}