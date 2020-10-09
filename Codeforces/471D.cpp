#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;

struct KMP
{
	vector<int> P;
	vector<int> b;
	KMP(int* s, int sz)
	{
		P.assign(sz, 0);
		FOR(i, 0, sz)
		{
			P[i] = s[i];
		}
		int n = sz;
		b.assign(n, 0);
		int j = 0;
		FOR(i, 1, n)
		{
			while(j > 0 && P[j] != P[i]) j = b[j-1];
			if(P[j] == P[i])
			{
				b[i] = j+1;
				j++;
			}
			else
			{
				b[i] = 0;
			}
		}
	}
	vector<int> match(int* T, int sz)
	{
		int n = sz;
		vector<int> ans;
		int j = 0;
		FOR(i, 0, n)
		{
			while(j > 0 && T[i] != P[j]) j = b[j-1];
			if(T[i] == P[j])
			{
				j++;
				if(j == (int) P.size())
				{
					ans.emplace_back(i-j+1);
					j = b[j-1];
				}
			}
		}
		return ans;
	}
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		int T[n-1];
		int ant, cur;
		cin >> ant;
		FOR(i, 0, n-1)
		{
			cin >> cur;
			T[i] = cur-ant;
			ant = cur;
		}
		int P[m-1];
		cin >> ant;
		FOR(i, 0, m-1)
		{
			cin >> cur;
			P[i] = cur-ant;
			ant = cur;
		}
		if(m == 1)
		{
			printf("%d\n", n);
			continue;
		}
		KMP kmp(P, m-1);
		vi ans = kmp.match(T, n-1);
		printf("%d\n", (int) ans.size());
	}
	return 0;
} 