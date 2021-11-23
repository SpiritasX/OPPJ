/*
 * Zadatak 11.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji proverava da li su stringovi s1 i s2
 * jednaki.
 * 
 * Primer:
 * > abc
 * > cda
 * Ne
 * > Dejan
 * > dejan
 * Ne
 * > da
 * > da
 * Da
 */

#include <stdio.h>

int main()
{
	char s1[100], s2[100];
	int n1 = 0, n2 = 0;

	// Unos stringa 1
	printf("Unesite string 1\n> ");
	gets(s1);
	
	// Unos stringa 2
	printf("Unesite string 2\n> ");
	gets(s2);

	// Velicina stringa 1
	while (s1[++n1]);

	// Velicina stringa 2
	while (s2[++n2]);

	// Ako su razlicite duzine, zavrsi program
	if (n1 != n2)
	{
		printf("Nemaju ni istu velicinu...");
		return 0;
	}

	for (int i = 0; s1[i]; i++)
	{
		// Ako im se ne poklapaju dva karaktera, zavrsi program
		if (s1[i] != s2[i])
		{
			printf("Ne");
			return 0;
		}
	}

	// Ako se sve poklopilo, jednaki su
	printf("Da");

	return 0;
}