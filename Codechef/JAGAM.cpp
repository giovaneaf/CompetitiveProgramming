#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 1010
#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		ll z1, z2;
		cin >> n >> z1 >> z2;
		vector<ll> v(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		bool a = false;
		bool b = true;
		for(int i = 0; i < n; ++i)
		{
			if(v[i] == z1 || -v[i] == z1 || v[i] == z2 || -v[i] == z2)
			{
				a = true;
				break;
			}
			else
			{
				for(int k = 0; k < 2 && b; ++k)
				{
					ll val = (k == 0 ? v[i] : -v[i]);
					bool tmp = false;
					for(int j = 0; j < n; ++j)
					{
						if(val+v[j] == z1 || val-v[j] == z1 || val+v[j] == z2 || val-v[j] == z2) 
						{
							tmp = true;
							break;
						}
					}
					b = tmp;
				}
			}
		}
		if(a)
			printf("1\n");
		else if (b)
			printf("2\n");
		else
			printf("0\n");
	}
	return 0;
}