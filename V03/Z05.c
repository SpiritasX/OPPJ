#include <stdio.h>

int main()
{
	int a;

	printf("Unesite ceo broj: ");
	scanf("%d", &a);

	if (a % 2)
		printf("Neparan broj...");
	else
		printf("%d", a + 3);

	return 0;
}