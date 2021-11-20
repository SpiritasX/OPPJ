#include <stdio.h>
#include <math.h>

int main()
{
	int n, broj = 1, prost;
	
	printf("Unesite ceo broj: ");
	scanf("%d", &n);

	// Prvih n prostih brojeva
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", broj);

		// Povecavaj broj dok ne dodjes do prostog
		do
		{
			prost = 1;
			broj++;

			// Proveri da li je novi broj prost
			for (int j = 2; j <= sqrt(broj); j++)
				if (broj % j == 0)
					prost = 0;
		} while(prost != 1);
	}
	
	return 0;
}