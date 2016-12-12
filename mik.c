#include <stdlib.h>
#include <stdio.h>

/*int potega (int podstawa, int wykladnik)
{
  if (wykladnik < 0) return potega (1/podstawa, -wykladnik);
  if (wykladnik == 0) return 1;
  if (wykladnik == 1) return podstawa;
  if (wykladnik%2 == 0) return potega (podstawa*podstawa, wykladnik/2);
  else return podstawa *potega (podstawa*podstawa, (wykladnik-1)/2);
}*/

unsigned int konwerter (char deks[8], int length)
{
  int i;
  int j;
  char alfabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  unsigned int suma = 0;

  for (i=length -1; i>=0; i--)
    {
      j=0;
      while (deks[i] != alfabet[j]) 
		{
			j++;
		}
      if (j<=15) suma = suma*16 + j;
      if (15 < j && j <= 23) suma = suma*8 + (j-15);
      if (j == 24) suma = suma*2 + 1;
	  if (j == 25) suma = suma*2;
      if (25<j) suma = suma*10 + (j-25);
    }
return suma;
}

int spacja (char znak) /*sprawdza czy wczytany znak jest "blank space" */
{
if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r') return 1;
else return 0;
}

int main (void)
{
	struct maszyna
		{
		int rejestr[16];
		int dane[256];
		int instrukcje[256];
		int counter;
		};

	struct maszyna stan;
	char czytany[8];
	unsigned int sczytany;
	char c;
	int licznik = 0;
	int i = 0;
	int j = 0;
	
	while (i<16)
		{
		stan.rejestr[i] = 0;
		i++;
		}
	while (j <256)
		{
		stan.dane[j] = 0;
		j++;
		}

	do
		{	
		c = getchar();
		if (spacja(c) == 0 && c != '%')
			{
			czytany[i] = c;
			i++;
			}
		else /*wczytaliśmy spację lub % */
			{
			if (i == 0) /*czyli nie czytamy żadnej liczby */
				{
				if (c == '%') licznik++;
				}
			else /*kończymy czytanie liczby */
				{
				sczytany = konwerter (czytany, i);
				i = 0;
				switch (licznik)
				case 0: 
					{
					stan.rejestr[j] = sczytany;
					if (c == '%') j=0;
					else j++;
					} break;
				case 1:
					{
					stan.dane[j] = sczytany;
					if (c == '%') j=0;
					else j++;
					} break;
				case 2:
					{
					stan.instrukcje[j] = sczytany;
					j++;
					if (c == '%') stan.counter = j;
					} break;
				case 3:
					{
					stan.instrukcje[j] = sczytany;
					j++;
					} break;
				if (c == '%') licznik++;

				}

			}
		
		}
	while (c == EOF);
}
