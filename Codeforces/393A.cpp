#include <stdio.h>
#include <string.h>
#include <algorithm>
 
int main()
{
	int q[26];
	for(int i = 0; i < 26; i++)
		q[i] = 0;
	char s[110];
	scanf("%s", s);
	int size = strlen(s);
	for(int i = 0; i < size; i++)
		q[s[i]-'a']++;
	int maximum = 0;
	if(q['n'-'a'] >= 3)
	{
		maximum = 1 + (q['n'-'a']-3)/2;
	}
	maximum = std::min(maximum, q['e'-'a']/3);
	maximum = std::min(maximum, q['i'-'a']);
	maximum = std::min(maximum, q['t'-'a']);
	printf("%d\n", maximum);
	return 0;
}