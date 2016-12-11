#include <stdlib.h>
#include <stdio.h>

int potega (int podstawa, int wykladnik)
{
  if (wykladnik < 0) return potega (1/podstawa, -wykladnik);
  if (wykladnik == 0) return 1;
  if (wykladnik == 1) return podstawa;
  if (wykladnik%2 == 0) return potega (podstawa*podstawa, wykladnik/2);
  else return podstawa *potega (podstawa*podstawa, (wykladnik-1)/2);
}

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
      if (j<=15) suma = suma + j*potega(16, i);
      if (15 < j && j <= 23) suma = suma + (j-16)*potega(8, i);
      if (j == 25) suma = suma + potega(2, i); 
      if (25<j) suma = suma + (j-26)*potega(10, i);
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
	int i;
	int j;

	do
		{	
		c = getchar();
		if (spacja(c) == 0 && c != '%')
			{
			czytany[i] = c;
			i++;
			}
		else
			{
			if (i == 0 && spacja(c) == 1) continue;
			if (i !=0 && (spacja(c) == 1 || c == '%'))
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
					}

				}
			if (c == '%') licznik++;
			}
		
		}
	while (c == EOF);
}
