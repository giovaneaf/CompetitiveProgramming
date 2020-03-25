#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 110
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

int mex(set<int>& s)
{
	if(s.empty()) return 0;
	auto it = s.begin();
	if(*it > 0) return 0;
	it++;
	int val = 0;
	for(; it != s.end(); ++it)
	{
		val++;
		if(*it > val) return val;
	}
	return val+1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int M[110][110];
	for(int i = 0; i < 101; ++i)
	{
		M[i][i] = 1;
		M[i][0] = 1;
		M[0][i] = 1;
	}
	M[0][0] = 0;
	for(int j = 1; j < 101; ++j)
	{
		for(int i = 1; i < 101; ++i)
		{
			if(i == j) continue;
			set<int> s;
			for(int k = 0; k < j; ++k)
				s.insert(M[i][k]);
			for(int k = 0; k < i; ++k)
				s.insert(M[k][j]);
			for(int k = 1; k <= min(i, j); ++k)
				s.insert(M[i-k][j-k]);
			M[i][j] = mex(s);
		}
	}
#if 0
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			printf("%3d", M[i][j]);
		}
		printf("\n");
	}
#endif
	for(int i = 0; i < 101; ++i)
	{
		M[i][i] = INF;
		M[i][0] = INF;
		M[0][i] = INF;
	}
	M[0][0] = INF;
	for(int j = 1; j < 101; ++j)
	{
		for(int i = 1; i < 101; ++i)
		{
			if(i == j) continue;
			set<int> s;
			for(int k = 1; k < j; ++k)
				s.insert(M[i][k]);
			for(int k = 1; k < i; ++k)
				s.insert(M[k][j]);
			for(int k = 1; k <= min(i, j); ++k)
				s.insert(M[i-k][j-k]);
			M[i][j] = mex(s);
		}
	}
#if 0
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			printf("%10d", M[i][j]);
		}
		printf("\n");
	}
#endif
	int n;
	while(cin >> n)
	{
		vector<ii> v(n);
		bool possible = false;
		for(int i = 0; i < n; ++i)
		{
			int r, c;
			cin >> r >> c;
			v[i] = {r, c};
			if(r == c) possible = true;
		}
		if(possible)
		{
			cout << "Y\n";
		}
		else
		{
			int xr = 0;
			for(int i = 0; i < n; ++i)
				xr ^= M[v[i].first][v[i].second];
			cout << ((xr == 0) ? "N" : "Y") << '\n';
		}
	}
    return 0;
}

