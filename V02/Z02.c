/*
 * Zadatak 2.
 * 
 * Napisati C program za konverziju temperature iz
 * farenhajta u celzijuse. Konverzija se vrsi po sledecoj
 * formuli:
 * 
 * C = (5/9) * (F - 32)
 * 
 * gde su c i f promenljive koje predstavljaju vrednosti
 * temperature u celzijusima i farenhajtima, respektivno.
 * Prikazati odgovarajucu temperaturu u celzijusima za
 *  F  |    C
 *   0 | -17.78
 * 100 |  37.78
 * 200 |  93.33
 * 
*/

#include <stdio.h>

int main()
{
	printf("%6.2fC\n", 5.0 / 9 * (0 - 32));
	printf("%6.2fC\n", 5.0 / 9 * (100 - 32));
	printf("%6.2fC", 5.0 / 9 * (200 - 32));

	return 0;
}