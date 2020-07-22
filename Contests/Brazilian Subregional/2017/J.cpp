#include <stdio.h>
#include <string.h>

int main()
{
	char s[110];
	scanf("%s", s);
	int res = 0;
	for(int i = 0; i < strlen(s); i++)
	{
		res += (s[i] - '0');
	}
	if(res%3 == 0)
		printf("0\n");
	else if(res%3 == 1)
		printf("1\n");
	else
		printf("2\n");
	return 0;
}