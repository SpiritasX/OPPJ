/*
 * Zadatak 10.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji kao ulaz prihvata jedan string i
 * karakter, a odreduje broj pojavljivanja tog karaktera
 * u stringu.
 * 
 * Primer:
 * > Banana
 * > a
 * 3
 * > Govedo
 * > v
 * 1
 */

#include <stdio.h>

int main()
{
	char str[100], a;
	int n = 0, brojac = 0;

	// Unos stringa
	printf("Unesite string\n> ");
	gets(str);

	// Unos karaktera
	printf("Unesite karakter\n> ");
	scanf("%c", &a);

	// Velicina stringa
	while (str[++n]);

	for (int i = 0; i < n; i++)
		if (str[i] == a)
			brojac++;

	// Ispis rezultata
	printf("%d", brojac);
}