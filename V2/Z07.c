#include <stdio.h>

int main()
{
	int a, b;

	printf("Unesite dvocifren broj: ");
	scanf("%d", &a);

	b = a % 10;
	b = b * 10;
	b = b + a/10;

	printf("%d", b);

	return 0;
}