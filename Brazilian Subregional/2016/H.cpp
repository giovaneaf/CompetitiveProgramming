#include <stdio.h>
#include <string.h>

int is_vogal(char v)
{
  if (v=='a' || v=='e' || v=='i' || v=='o' || v=='u')
    return 1;
  return 0;
}  

int main()
{
  char pal[51];
  while(scanf("%s",pal) != EOF)
  {
      int i,j;
      i=0;
      j=strlen(pal);
      int funny=1;
      while(i<j && funny == 1)
	{
	  if(is_vogal(pal[i]) && is_vogal(pal[j]))
	    {
	      if(pal[i] != pal[j])
		funny=0;
	      i++;
	      j--;
	    }
	  else if(is_vogal(pal[i]) && !(is_vogal(pal[j])))
	    j--;
	  else if(!(is_vogal(pal[i])) && (is_vogal(pal[j])))
	    i++;
	  else
	  {
	    i++;
	    j--;
	  }
	}
      if(funny==1)
	printf("S\n");
      else
	printf("N\n");
  }
  return 0;
}