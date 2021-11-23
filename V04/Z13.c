/*
 * Zadatak 13.
 * 
 * Nacrtati dijagram toka algoritma i napisati C
 * program koji u unesenom stringu s mala
 * slova pretvara u velika, i obrnuto. Ostale
 * karaktere u stringu (cifre, znakove interpunkcije,
 * itd.) program ne sme modifikovati.
 * 
 * Primer:
 * > afjbwnF@UBmf
 * AFJBWNf@ubMF
 */

#include <stdio.h>

int main()
{
	char str[100];

	// Unos stringa
	printf("Unesite string\n> ");
	gets(str);

	// Prolazi kroz ceo string
	for (int i = 0; str[i]; i++)
	{
		// Ako je veliko slovo, pretvori u malo
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		// Ako je malo slovo, pretvori u veliko
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
		// U suprotnom, samo preskoci karakter
	}

	printf("%s", str);

	return 0;
}