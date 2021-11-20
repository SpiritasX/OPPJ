#include <stdio.h>

int main()
{
	float a, b, x;

	printf("Unesite brojeve a i b: ");
	scanf("%f %f", &a, &b);

	if (a == 0 && b == 0)
		printf("X pripada R.");
	else if(a == 0)
		printf("Deljenje sa nulom nije dozvoljeno!");
	else
	{
		x = -b/a;
		printf("x = %.3f", x);
	}

	return 0;
}