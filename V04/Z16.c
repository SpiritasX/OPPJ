/*
 * Zadatak 16.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji u datom stringu odreduje:
 *     a) broj reci;
 *     b) broj reci koje pocinju sa M;
 *     c) broj reci ciji su prvi i poslednji znak jednaki;
 *     d) duzinu najkrace reci.
 * 
 * Primer:
 * > jabuka auto majka oko pihtija
 * 5 0 1 3
 */

#include <stdio.h>

int main()
{
	char str[100], prvoSlovoReci, poslednjeSlovoReci;
	int brojReci = 0,
		brojReciM = 0,
		brojReciPP = 0,
		brojSlovaPoReci = 0,
		minSlova = 100;

	// Unos stringa
	printf("Unesite string\n> ");
	gets(str);

	// Prolazi kroz ceo string
	for (int i = 0; str[i]; i++)
	{
		// Ako je karakter slovo
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			brojSlovaPoReci++;
			// Ako je karakter pre ovog razmak ili i == -1
			if (str[i - 1] == ' ' || i - 1 == -1)
			{
				prvoSlovoReci = str[i];
				if (str[i] == 'M')
					brojReciM++;
			}
			// Ako je karakter posle ovog razmak ili '\0'
			if (str[i + 1] == ' ' || i + 1 == '\0')
			{
				poslednjeSlovoReci = str[i];
				if (prvoSlovoReci == poslednjeSlovoReci)
					brojReciPP++;
			}
		}
		// Ako je karakter razmak
		else if (str[i] == ' ')
		{
			// Gotova rec
			brojReci++;
			if (brojSlovaPoReci < minSlova)
				minSlova = brojSlovaPoReci;
			brojSlovaPoReci = 0;
			prvoSlovoReci = 0;
			poslednjeSlovoReci = 0;
		}
	}

	brojReci++;

	printf("%d %d %d %d", brojReci, brojReciM, brojReciPP, minSlova);

	return 0;
}