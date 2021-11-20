#include <stdio.h>

int main()
{
	int a, b, c, temp;

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("[%d, %d, %d]\n", a, b, c);

	temp = a;
	a = b;
	b = c;
	c = temp;

	printf("[%d, %d, %d]\n", a, b, c);

	return 0;
}