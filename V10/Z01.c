/*
* Zadatak 1.
* 
* Napisati C program kojim ce se pomocu rekurzivne
* funkcije vrsiti konverzija nenegativnih celih brojeva iz
* dekadnog zapisa u binarni.
* 
* Primer:
* > 17
* 10001
* > 53
* 110101
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

long toBinary(unsigned x)
{
	if (x == 1)
		return 1;
	else
		return toBinary(x / 2) * 10 + x % 2;
}

int main()
{
	int broj = 1024;

	assert(broj <= 1023);

	printf("%ld\n", toBinary(broj));

	return 0;
}