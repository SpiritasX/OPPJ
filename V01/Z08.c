#include <stdio.h>

int main()
{
	int a = 0, b = 1, sled, n;

	printf("Koliko clanova zelite: ");
	scanf("%d", &n);
	
	if (n == 1)
		printf("%d", a);
	else if (n == 2)
		printf("%d %d", a, b);
	else
	{
		printf("%d %d ", a, b);
		for (int i = 3; i <= n; i++)
		{
			sled = a + b;
			a = b;
			b = sled;
			printf("%d ", sled);
		}
	}

	return 0;
}