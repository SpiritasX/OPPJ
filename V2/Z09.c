#include <stdio.h>

#define PI 3.14159

int main()
{
	float r, S, V;

	printf("Unesite poluprecnik lopte: ");
	scanf("%f", &r);
	
	S = 4*PI*r*r;
	V = 4.0/3*PI*r*r*r;

	printf("Povrsina lopte je %.3f, a zapremin %.3f", S, V);

	return 0;
}