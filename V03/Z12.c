/*
 * Zadatak 12.
 *
 * Bankomat: Napisati C program kojim se sa tastature
 * unose trenutni iznos (u RSD) na racunu korisnika u banci,
 * kao i iznos koji korisnik zeli da podigne sa bankomata.
 * Ukoliko je iznos deljiv sa 500 onda je transakciju moguce
 * uspresno obaviti i sa provizijom banke od 15 RSD. U
 * suprotnom, transakcija je neuspesna i stanje na racunu
 * ostaje nepromenjeno. Ipisati poruku o uspresnosti
 * transakcije kao i preostali iznos na racunu.
 *
 * Primer:
 * > 77200 2500
 * USPESNO 74685
 *
 * > 45900 1400
 * NEUSPESNO 45900
 */

#include <stdio.h>

int main()
{
	int stanje, iznos;

	printf("Unesite trenutno stanje i iznos koji zelite da podignete\n> ");
	scanf("%d %d", &stanje, &iznos);

	if (iznos % 500)
		printf("NEUSPESNO %d", stanje);
	else
		printf("USPESNO %d", stanje - iznos - 15);

	return 0;
}