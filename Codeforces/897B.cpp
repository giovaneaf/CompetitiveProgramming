#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
 
int main()
{
	ll k, p;
	cin >> k >> p;
	char s[110];
	ll ans = 0;
	s[0] = '0';
	s[1] = '0';
	s[2] = '\0';
	int ml = 0;
	int mh = 1;
	int n = 2;
	for(int a = 0; a < k; a++)
	{
		if(s[ml] == '9')
		{
			s[ml] = '0';
			s[mh] = '0';
			int d = 3;
			for(int i = ml-1; i >= 0; i--)
			{
				if(s[i] < '9')
				{
					s[i]++;
					s[i+d]++;
					break;
				}
				else
				{
					s[i] = s[i+d] = '0';
				}
				d += 2;
			}
			if(s[0] == '0')
			{
				for(int i = 0; i < n; i++)
				{
					s[i+1] = s[i];
				}
				s[0] = '1';
				s[n+1] = '1';
				s[n+2] = '\0';
				ml++;
				mh++;
				n += 2;
			}
		}
		else
		{
			s[ml] = s[mh] = s[ml] + 1;
		}
		ans = (ans + atoll(s))%p;
	}
	cout << ans << endl;
    return 0;
}