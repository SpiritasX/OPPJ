/*
 * Zadatak 20.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * koji uporeduje 2 unesena stringa i racuna najvecu i
 * najmanju razliku izmedu njih i ispisuje ih. Oba stringa
 * su iste duzine i sastoje se samo iz malih slova i
 * upitnika koji je dzoker znak i moze da zameni bilo
 * koje slovo.
 * 
 * Primer:
 * > a?c
 * > ??b
 * 1 3
 * > ?abac
 * > aba?w
 * 3 5
 * > abw?bw?
 * > abws?d?
 * 1 4
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[100], s2[100];
	int min = 0, max = 0;

	// Unos stringa 1
	printf("Unesite prvi string malim slovima\n");
	do
	{
		printf("> ");
		scanf("%s", s1);

		for (int i = 0; s1[i]; i++)
		{
			// Ako je upitnik, samo nastavi dalje
			if (s1[i] == '?')
				continue;
			// Ako nije malo slovo, unosi novi string
			if (s1[i] < 'a' || s1[i] > 'z')
			{
				s1[0] = '\0';
				break;
			}
		}
	} while (!s1[0]);

	// Unos stringa 2
	printf("Unesite drugi string iste duzine kao prvi\n");
	do
	{
		printf("> ");
		scanf("%s", s2);

		for (int i = 0; s2[i]; i++)
		{
			if (s2[i] == '?')
				continue;
			if (s2[i] < 'a' || s2[i] > 'z')
			{
				s2[0] = '\0';
				break;
			}
		}
	} while (!s2[0] || strlen(s2) != strlen(s1));

	for (int i = 0; s1[i]; i++)
	{
		// Maksimalna razlika se povecava u 3 od 4
		// slucaja tako da cemo je povecati na pocetku
		// i smanjiti samo ako udje u taj jedan slucaj.
		max++;

		// Ako su oba karaktera poznata
		if (s1[i] != '?' && s2[i] != '?')
		{
			// Minimalna razlika se povecava samo u
			// jednom slucaju, a to je ako su oba
			// karaktera poznata i razliciti su.
			if (s1[i] != s2[i])
				min++;
			else
				max--;
		}
	}

	printf("%d %d", min, max);
}