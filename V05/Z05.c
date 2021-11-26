/*
 * Zadatak 5.
 * 
 * Nacratati dijagram toka algoritma i napisati C
 * program pomocu koga se upotrebom unije ispisuje
 * reprezentacija realnog broja 3.14159 kao celog broja
 * zapisanog u heksadecimalnom brojnom sistemu.
 * 
 * https://www.rapidtables.com/convert/number/binary-to-decimal.html
 * https://www.h-schmidt.net/FloatConverter/IEEE754.html
 * 
 * Primer:
 * 3.14159
 * 1078530000
 * 0x40490fd0
 */

#include <stdio.h>

#define PI 3.14159

typedef union
{
	float f;
	int i;
} broj;

int main()
{
	broj pi;

	pi.f = PI;

	printf("%f\n", pi.f);
	printf("%d\n", pi.i);
	printf("0x%x\n", pi.i);

	return 0;
}