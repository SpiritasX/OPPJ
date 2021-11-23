/*
 * Zadatak 9.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji proverava da li je ucitani string
 * palindrom. Program napraviti tako da radi za reci, a
 * potom ga prosiriti da radi i sa recenicama (ignorisuci
 * znakove razmaka) kako bi string "Ana voli
 * Milovana" program registrovao kao palindrom.
 * 
 * Primer:
 * > Ana voli Milovana
 * Jeste
 * > Zdravo
 * Nije
 */

#include <stdio.h>

int main()
{
	char str[100], tmp[100];
	int n = 0;

	// Unos stringa
	printf("Unesite string\n> ");
	scanf("%99[^\n]", tmp);

	// Odredjivanje duzine stringa
	while (tmp[n])
	{
		// Sacuvaj string u drugu promenljivu
		str[n] = tmp[n];
		n++;
	}
	str[n] = '\0';

	// Petlja za sredjivanje stringa
	// pod pretpostavkom da string ima samo
	// slova i razmake.
	for (int i = 0; i < n; i++)
	{
		// Ako je veliko slovo, pretvara ga u malo
		if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			// 'a' se nalazi 32 karaktera ispred 'A'
			// u ascii tabeli, oduzimanjem jednog od
			// drugog dobijamo tu razliku i kad to
			// dodamo na bilo koje veliko slovo,
			// dobicemo njegovo malo.
			tmp[i] += 'a' - 'A';
		// Ako je razmak:
		if (tmp[i] == ' ')
		{
			// Nova petlja prolazi kroz string od tog karaktera
			// i pomera ih sve za jedno mesto u levo
			for (int j = i; j < n; j++)
				tmp[j] = tmp[j + 1];
			// Smanji duzinu stringa za jedan i vrati brojac u nazad
			n = n - 1;
			i = i - 1;
		}
	}

	// Petlja za proveravanje da li je palindrom
	for (int i = 0; i < n / 2; i++)
	{
		// Ako su mu (prvi + i) i (poslednji - i) karakteri razliciti,
		// nije palindrom.
		if (tmp[i] != tmp[n - 1 - i])
		{
			// Zavrsi program
			printf("\"%s\" nije palindrom.\n", str);
			return 0;
		}
	}

	// Ispis rezultata
	printf("\"%s\" jeste palindrom!\n", str);

	return 0;
}