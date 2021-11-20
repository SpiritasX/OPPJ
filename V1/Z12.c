#include <stdio.h>

int main()
{
	int a, b, nzd = 1;

	printf("Unesite dva cela broja: ");
	scanf("%d %d", &a, &b);

	for (int i = 2; i < sqrt(a); i++)
	{
		if (a % i == 0 && b % i == 0)
			nzd = i;
	}

	printf("NZD(%d, %d) = %d", a, b, nzd);

	return 0;
}