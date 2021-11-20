#include <stdio.h>
#include <math.h>

int main()
{
	int n;

	printf("Unesite ceo broj: ");
	scanf("%d", &n);

	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			printf("Nije prost.");
			return 0;
		}
	}

	printf("Jeste prost!");

	return 0;
}