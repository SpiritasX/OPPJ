/*
* Zadatak 4.
* 
* Napisati C program kojim se cita datoteka
* "ulaz.txt" i njen sadrzaj u obrnutom
* redosledu ispisuje u izlaznu datoteku
* "izlaz.txt". Ulazna datoteka moze imati
* proizvoljan broj linija, a svaka linija moze imati
* proizvoljan broj karaktera.
*/

#include <stdio.h>

int main()
{
	FILE* ulaz = fopen("ulaz.txt", "r");
	FILE* izlaz = fopen("izlaz.txt", "w");
	
	char c;
	int i = 1;
	
	while (1)
	{
		// Sa ulaza citamo od nazad i
		// pomeramo se do prvog karaktera
		fseek(ulaz, -i, SEEK_END);
		if (ftell(ulaz) == 0)
		{
			c = fgetc(ulaz);
			fputc(c, izlaz);
			break;
		}
		c = fgetc(ulaz);
		fputc(c, izlaz);
		i++;
	}
	
	fclose(ulaz);
	fclose(izlaz);
	
	return 0;
}
