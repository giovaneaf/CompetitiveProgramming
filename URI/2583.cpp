#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9


int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		map<string, bool> mm;
		string a, b;
		FOR(i, 0, n)
		{
			cin >> a >> b;
			if(b == "chirrion")
				mm[a] = false;
			else if(b == "chirrin")
				mm[a] = true;
		}
		printf("TOTAL\n");
		for(auto p : mm)
		{
			if(p.second)
			{
				printf("%s\n", p.first.c_str());
			}
		}
	}
	return 0;
} 