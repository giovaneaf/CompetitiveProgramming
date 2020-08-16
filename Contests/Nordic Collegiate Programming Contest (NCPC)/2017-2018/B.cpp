#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

struct st
{
	string name;
	double a, b;
	bool operator< (const st& s)
	{
		return b < s.b;
	}
};

ll mod = 1000000007LL;
int n;
st v[510];
int ans[4];
int tmp[4];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		FOR(i, 0, n)
		{
			cin >> v[i].name >> v[i].a >> v[i].b;
		}
		sort(v, v+n);
		double best = 1e9;
		double aux;
		int cnt;
		FOR(i, 0, n)
		{
			aux = v[i].a;
			tmp[0] = i;
			cnt = 1;
			FOR(j, 0, n)
			{
				if(i == j) continue;
				tmp[cnt++] = j;
				aux += v[j].b;
				if(cnt == 4) break;
			}
			if(best > aux)
			{
				best = aux;
				FOR(j, 0, 4) ans[j] = tmp[j];
			}
		}
		printf("%f\n", best);
		FOR(i, 0, 4)
			printf("%s\n", v[ans[i]].name.c_str());
	}
	return 0;
}
