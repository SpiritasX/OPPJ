#include <stdio.h>

int main()
{
	int a, b, temp;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);
	
	printf("[%d, %d]\n", a, b);

	temp = a;
	a = b;
	b = temp;

	printf("[%d, %d]\n", a, b);

	return 0;
}