#include <stdio.h>
#define MAX 30

int main()
{
	char string[MAX + 1];
	int brojGlava = 0, brojRepova = 0;

	// Unos stringa
	printf("Unesite string: ");
	scanf("%s", string);

	for (int i = 0; string[i]; i++)
	{
		// Ako je pogresan karakter, zavrsi program.
		if (string[i] != 'G' && string[i] != 'R' && string[i] != '.')
		{
			printf("JOK\n");
			return 0;
		}
		// Ako se pojavi nova zmija, a da prosla jos nije prosla, zavrsi program.
		else if (string[i] == 'G' && brojGlava != 0)
		{
			printf("JOK\n");
			return 0;
		}
		// Ako se pojavi prvo rep bez glave, zavrsi program.
		else if (string[i] == 'R' && (brojRepova != 0 || brojGlava == 0))
		{
			printf("JOK\n");
			return 0;
		}
		// Ako prodje sve to, povecaj broj glava ili repova.
		// I ako se pojavi glava, resetuj broj repova i obrnuto.
		else if (string[i] == 'G')
		{
			brojRepova = 0;
			brojGlava++;
		}
		else if (string[i] == 'R')
		{
			brojGlava = 0;
			brojRepova++;
		}
	}

	// Ako poslednja zmija nije stigla da udje, zavrsi program.
	if (brojGlava != 0)
	{
		printf("JOK\n");
		return 0;
	}

	// Sve je uredu! :)
	printf("OK");
	return 0;
}