/*
 * Zadatak 7.
 * 
 * Nacrtati dijagram toka algoritma i napisati C program
 * kojim se ucitava string. Potom se ucitani string ispisuje
 * u ucitanom i obrnutom redosledu, zajedno sa
 * informacijom o broju karaktera u stringu.
 */

#include <stdio.h>

int main()
{
	char str[100];
	int n = 0;

	// Unos stringa (nije preporucljivo koristiti gets funkciju!
	printf("Unesite string\n> ");
	gets(str);
	// fgets(str, 100, stdin);
	// scanf("%s", str); Procitaj string (white-space terminated)
	// scanf("%99[^\n]", str); Procitaj prvih 99 karaktera ili dok ne dodjes do Enter
	
	puts(str);

	// Pronalazi duzinu stringa
	// while se vrti dok je str[i] != '\0' (NULL)
	// ++n povecava n svaku iteraciju, time prolazeci
	// kroz ceo string
	while (str[++n]);

	// Ispis stringa u nazad karakter po karakter
	for (int i = n - 1; i >= 0; i--)
		printf("%c", str[i]);

	// Ispis velicine stringa
	printf("\n%d", n);

	return 0;
}