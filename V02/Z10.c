/*
 * Zadatak 10.
 * 
 * Napisati C program kojim se na osnovi zadatih
 * dvocifrenih brojeva a i b formira i ispisuje
 * cetvorocifren broj c na sledeci nacin: prva cifra c
 * je prva cifra a, potom su sledece dve cifre c obe
 * cifre iz b, dok je poslednja cifra c druga cifra a.
 * 
 * Primer:
 * > 12 34
 * 1342
 * > 62 10
 * 6102
 */

#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	c = a / 10;		// Sacuvaj drugu deseticu iz a u c.
	c *= 1000;		// Pomeri taj broj na cetvrto mesto.
	c += b * 10;	// Dodaj na to ceo broj b pomeren za jedno mesto u levo
	c += a % 10;	// Dodaj na to prvu deseticu iz a.

	printf("%d", c);

	return 0;
}