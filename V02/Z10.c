#include <stdio.h>

int main()
{
	int a, b, c;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	c = a / 10;
	c *= 1000;
	c += b * 10;
	c += a % 10;

	printf("%d", c);

	return 0;
}