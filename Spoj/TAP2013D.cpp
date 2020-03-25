#include <bits/stdc++.h>
 
#define MAXN 510
#define INF 1e9
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
 
int main()
{
	int n, f;
	scanf("%d %d", &n, &f);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	set<int> s[f];
	int e = a;
	int team[n];
	team[0] = a;
	s[e].insert(0);
	for(int i = 1; i < n; ++i)
	{
		e = ((long long) b*e + c)%f;
		s[e].insert(i);
		team[i] = e;
	}
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int i;
		scanf("%d %d", &i, &e);
		i--;
		if(s[e].empty())
		{
			printf("%d %d\n", n, n);
			s[team[i]].erase(i);
			team[i] = e;
			s[e].insert(i);
		}
		else
		{
			if(s[e].size() == 1)
			{
				int index = *s[e].begin();
				if(index == i)
				{
					printf("%d %d\n", n, n);
					continue;
				}
				else
				{
					if(i < index)
					{
						printf("%d %d\n", n - (index - i), index-i);
					}
					else
					{
						printf("%d %d\n", i - index, n-(i-index));
					}
				}
			}
			else
			{
				auto it = s[e].upper_bound(i);
				if(it == s[e].end())
				{
					--it;
					if(*it == i)
						--it;
					auto it2 = s[e].begin();
					printf("%d %d\n", i - *it, n - (i - *it2));
				}
				else
				{
					set<int>::iterator it2 = it;
					if(it2 != s[e].begin())
					{
						it2--;
						if(*it2 == i)
						{
							if(it2 == s[e].begin())
								it2 = s[e].end();
							it2--;
						}
					}
					else
					{
						it2 = s[e].end();
						it2--;
					}
					if(i < *it2)
					{
						printf("%d %d\n", n - (*it2 - i), *it - i);
					}
					else
					{
						printf("%d %d\n", i - *it2, *it - i);
					}
				}
			}
			s[team[i]].erase(i);
			team[i] = e;
			s[e].insert(i);
		}
	}
	return 0;
}