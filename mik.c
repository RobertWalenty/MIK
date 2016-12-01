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
  char alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  unsigned int wynik = 0;

  for (i=length -1, i>=0, i--)
    {
      j=0;
      while (deks[i] != alfabet[j]) 
	{
	  j++;
	}
      if (j<=15) suma = suma + j*potega(16, i);
      if (15 < j && j <= 23) suma = suma + (j-16)*potega(8, i);
      if (23 < j && j<=25) suma = suma + (j-24)*potega(2, i); /*to jest źle, ma być na odwrót */
      if (25<j) suma = suma + (j-26)*potega(10, i);
    }
return wynik;
}
