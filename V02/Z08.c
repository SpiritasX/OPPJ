#include <stdio.h>

int main()
{
	float G, p, god;

	printf("Unesite glavicu, kamatnu stopu i broj godina stednje: ");
	scanf("%f %f %f", &G, &p, &god);

	printf("Kamata = %.2f", G*p*god/100.0);

	return 0;
}