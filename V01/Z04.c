#include <stdio.h>

int main()
{
	int b, g, s = 0;

	printf("Do kog broja zelite da sabirate: ");
	scanf("%d", &g);

	do
	{
		printf("Unesite ceo broj: ");
		scanf("%d", &b);
		s += b;
	} while(s <= g);

	printf("Zbir = %d", s);
	return 0;
}