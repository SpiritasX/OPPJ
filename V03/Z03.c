#include <stdio.h>

int main()
{
	int a, b, c, min;

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &a, &b, &c);

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;

	printf("Najmanji broj je %d", min);

	return 0;
}