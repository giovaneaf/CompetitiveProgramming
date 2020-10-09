#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9
#define EPS 1e-9

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef long long ll;

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		int n = s.size();
		bool l, u, d;
		int sl, su, sd;
		l = u = d = false;
		sl = su = sd = 0;
		for(int i = 0; i < n; ++i)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				l = true;
				sl++;
			}
			else if(s[i] >= 'A' && s[i] <= 'Z') 
			{
				su++;
				u = true;
			}
			else if(s[i] >= '0' && s[i] <= '9') 
			{
				d = true;
				sd++;
			}
		}
		if(l && u && d)
		{
			cout << s << '\n';
		}
		else
		{
			if(l && u)
			{
				for(int i = 0; i < n; ++i)
				{
					if(s[i] >= 'a' && s[i] <= 'z')
					{
						if(sl > 1)
						{
							s[i] = '0';
							break;
						}
					}
					else
					{
						if(su > 1)
						{
							s[i] = '0';
							break;
						}
					}
				}
				cout << s << '\n';
			}
			else if(l && d)
			{
				for(int i = 0; i < n; ++i)
				{
					if(s[i] >= 'a' && s[i] <= 'z')
					{
						if(sl > 1)
						{
							s[i] = 'A';
							break;
						}
					}
					else
					{
						if(sd > 1)
						{
							s[i] = 'A';
							break;
						}
					}
				}
				cout << s << '\n';
			}
			else if(u && d)
			{
				for(int i = 0; i < n; ++i)
				{
					if(s[i] >= 'A' && s[i] <= 'Z')
					{
						if(su > 1)
						{
							s[i] = 'a';
							break;
						}
					}
					else
					{
						if(sd > 1)
						{
							s[i] = 'a';
							break;
						}
					}
				}
				cout << s << '\n';
			}
			else
			{
				if(l)
				{
					s[1] = 'A';
					s[2] = '0';
				}
				else if(u)
				{
					s[1] = 'a';
					s[2] = '0';
				}
				else
				{
					s[1] = 'A';
					s[2] = 'a';
				}
				cout << s << '\n';
			}
		}
	}
	return 0;
}
