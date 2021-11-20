#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;

	printf("Unesite dva broja: ");
	scanf("%d %d", &a, &b);

	for (int i = 2; i < sqrt(a); i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("Nisu uzajamno prosti.");
			return 0;
		}
	}

	printf("Jesu uzajamno prosti.");

	return 0;
}