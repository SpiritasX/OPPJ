#include <stdio.h>

int main()
{
	int a, b;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	printf("a+b: %d\n", a + b);
	printf("a-b: %d\n", a - b);
	printf("a*b: %d\n", a * b);
	printf("a/b: %d\n", a / b);

	return 0;
}