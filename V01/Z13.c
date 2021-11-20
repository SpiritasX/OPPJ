#include <stdio.h>

int main()
{
	int a, b, nzs;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	nzs = (a > b) ? a : b;

	// Trazi prvi broj koji je deljiv i sa a i sa b pocevsi od veceg broja.
	while(nzs % a != 0 || nzs % b != 0)
		nzs++;

	printf("NZS(%d, %d) = %d", a, b, nzs);

	return 0;
}