#include <stdio.h>

int main()
{
	int a, b, c, temp, k;

	printf("Unesite tri cela broja: ");
	scanf("%d %d %d", &a, &b, &c);

	printf("Za koliko mesta zelite da rotirate: ");
	scanf("%d", &k);

	printf("[%d, %d, %d]\n", a, b, c);

	for (int i = 0; i < k; i++)
	{
		temp = a;
		a = b;
		b = c;
		c = temp;
	}

	printf("[%d, %d, %d]\n", a, b, c);

	return 0;
}