/*
 * Zadatak 17.1.
 *
 * Izmeniti zadatak 17 tako da se ponaša kao dešifrator.
 * (menja slova ulevo)
 * 
 * Primer:
 * > cgudyr
 * > 3
 * zdravo
 */

#include <stdio.h>

int main()
{
	int kljuc, n;
	char str[100];

	// Unos stringa
	printf("Unesite string\n> ");
	gets(str);

	// Unos kljuca
	printf("Unesite kljuc za DEsifrovanje\n> ");
	scanf("%d", &kljuc);

	// Prolazi kroz ceo string
	for (int i = 0; str[i]; i++)
	{
		// Ako je veliko slovo, zamenjuje ga u malo
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		// Ako je karakter slovo
		if (str[i] >= 'a' && str[i] <= 'z')
			// Ista logika kao i u proslom zadatku, samo
			// sto sad treba da oduzmemo kljuc od karaktera.
			// Oduzimanje po modulu ima specificnu
			// karakteristiku gde je neko (x - 3) % 26 isto
			// sto i (x + 23) % 26, a zato sto u jeziku C
			// % nije isto sto i matematicki moduo, % od negativnog
			// broja vraca negativan broj al po modulu, mi mozemo to
			// da oduzmemo od 26 i dobijemo odgovarajuci broj
			str[i] = (str[i] - 'a' + 26 - kljuc % 26) % 26 + 'a';
	}

	printf("%s", str);
}