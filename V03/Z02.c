#include <stdio.h>

int main()
{
	int a, b;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	printf("Manji broj je %d", (a < b) ? a : b);
}