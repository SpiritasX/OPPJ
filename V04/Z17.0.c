/*
 * Zadatak 17.0.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * koji uneseni string sifruje Cezarovom sifrom za
 * KLJUC (ceo broj) mesta udesno i ispisuje sifrovan string.
 * Program treba da radi samo za mala slova abecede.
 * Rezultujuce slovo se racuna kao slovo na KLJUC mesta
 * udesno od pocetnog.
 * 
 * Primer:
 * > zdravo
 * > 3
 * cgudyr
 * > cao
 * > 26
 * cao
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
	printf("Unesite kljuc za sifrovanje\n> ");
	scanf("%d", &kljuc);

	// Prolazi kroz ceo string
	for (int i = 0; str[i]; i++)
	{
		// Ako je veliko slovo, zamenjuje ga u malo
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		// Ako je karakter slovo
		if (str[i] >= 'a' && str[i] <= 'z')
			// Pomera karakter za kljuc mesta u desno
			// Prvo "normalizujem" karakter da bude izmedju 0 i 25
			// Zatim dodam na njega kljuc karaktera i uradim moduo od 26
			// zato sto svaki broj koji predje 25, treba da krene od 0 opet
			// i na kraju vratimo brojeve u njihove karaktere sa + 'a'.
			str[i] = (str[i] - 'a' + kljuc) % 26 + 'a';
	}

	printf("%s", str);
}