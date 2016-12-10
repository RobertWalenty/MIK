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
		int semafor = 0;
		};

	struct maszyna stan;
	char czytany[8];
	char c;
	int licznik = 0;
	int i = 0;

	do
		{
		c = getchar();
		if (semafor == 0 && spacja(c) == 1) continue;
		if (spacja(c) == 0 && c != '%')
		
		
		}
	while (c == EOF);
}
