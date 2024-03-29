/*
 * Zadatak 18.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * koji za uneseni string proverava da li je moguce da taj
 * string bude palindrom. Ako je moguce, treba da se
 * ispise potencijalni palindrom, ako ne, treba ispisati
 * "-1". Na ulazu su dozvoljena samo mala slova abecede i
 * tacka.Tacka je dzoker znak, tj. menja bilo koje slovo.
 * 
 * Primer:
 * > a.ba
 *   abba
 * > a..b
 * -1
 * > abnd.jbw..js..ba
 *   abndsjbwwbjsdnba
 */

#include <stdio.h>
#define MAX 30

int main()
{
	char string[MAX + 1];
	int n = 0;

	// Unos stringa
	printf("Unesite string: ");
	scanf("%s", string);

	// Prvi prolazak kroz string za uklanjanje gresaka.
	while (string[n])
	{
		// Ako string sadrzi nedozvoljene karaktere, zavrsi program.
		if (!(string[n] > 96 && string[n] < 123) && string[n] != '.')
		{
			printf("Vas string sadrzi nedozvoljene karaktere.");
			return 0;
		}
		n++;
	}

	// Drugi prolazak kroz string
	for (int i = 0; i < n/2; i++)
	{
		// Ako i-ti karakter od pocetka i i-ti karakter od kraja nisu isti, ili jedan od njih nije tacka, zavrsi program.
		if (string[i] != string[n - 1 - i] && string[i] != '.' && string[n - 1 - i] != '.')
		{
			printf("-1");
			return 0;
		}
		// Ako je jedan od njih tacka, zameni ga sa drugim i obrnuto.
		else if (string[i] == '.')
			string[i] = string[n - 1 - i];
		else if (string[n - 1 - i] == '.')
			string[n - 1 - i] = string[i];
	}

	printf("%s\n", string);
	return 0;
}