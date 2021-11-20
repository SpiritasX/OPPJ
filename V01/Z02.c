#include <stdio.h>

int main()
{
	int x;

	printf("Unesite ceo broj: ");
	scanf("%d", &x);

	if (x < 0)
	{
		printf("|%d| = %d", x, -x);
	}
	else
	{
		printf("|%d| = %d", x, x);
	}

	return 0;
}