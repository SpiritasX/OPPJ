#include <stdio.h>

int main()
{
	int n, sum = 0;

	printf("Unesite ceo broj: ");
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		sum = sum + i;
	}
	
	printf("Zbir = %d", sum);

	return 0;
}