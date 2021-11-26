/*
* Zadatak 4.
* 
* Nacrtati dijagram toka algoritma i napisati C
* program kojim se stampaju svi trocifreni brojevi (ako
* ih ima) koji su jednaki sumi faktorijela svojih cifara.
*/

#include <stdio.h>

unsigned faktorijel(unsigned);

int main()
{
	unsigned sum, c1, c2, c3, i;

	for (i = 100; i < 1000; i++)
	{
		c1 = i % 10;
		c2 = (i / 10) % 10;
		c3 = (i / 100) % 10;

		c1 = faktorijel(c1);
		c2 = faktorijel(c2);
		c3 = faktorijel(c3);

		sum = c1 + c2 + c3;

		if (sum == i)
			printf("%d ", i);
	}

	return 0;
}

/*
* Racuna faktorijel unetog broja.
*/
unsigned faktorijel(unsigned x)
{
	// Svaka rekurzivna funkcija mora da ima uslov
	// sa kojim ce se zavrsiti, inace program puca
	// posle zauzimanja previse memorije.
	// U ovom slucaju, posto nam se x smanjuje svakim
	// pozivom, pozivanje ce se zavrisiti kad x dodje do 0
	if (x > 1)
		return x * faktorijel(x - 1);
	// Kad dodje do kraja, vraca jedan zato sto je u izrazu
	// mnozenje i mnozenje sa 1 ne menja rezultat
	else
		return 1;
}