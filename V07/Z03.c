/*
* Dati su prirodni brojevi n, m (n <= m). Nacrtati
* dijagram toka algoritma i napisati C program kojim se
* odredjuje koji od brojeva od n do m predstavljaju
* prestupne godine. Godina je prestupna ako je
* zadovoljen sledeci skup uslova:
*	1. broj godine je deljiv sa cetiri, i
*	2. vazi jedno od sledecih pravila:
*		- broj godine nije deljiv sa 100
*		- broj godine je deljiv sa 400
*/

#include <stdio.h>
#include <stdbool.h>

bool prestupna(unsigned);

int main()
{
	unsigned n, m;

	printf("Unesite dva prirodna broja tako da je prvi manji od drugog\n");
	do
	{
		printf("> ");
		scanf("%u %u", &n, &m);
	} while (n < 0 || m < 0 || m <= n);

	for (int i = n; i <= m; i++)
		if (prestupna(i))
			printf("%d\n", i);

	return 0;
}

/*
* Proverava da li je prosledjen broj prestupna godina.
*/
bool prestupna(unsigned godina)
{
	if (godina % 4 == 0)
		if (godina % 400 == 0 || godina % 100 != 0)
			return true;
	return false;
}