#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, m;
pair<ii, double> v[MAXN];
double qty[MAXN];
bool init[MAXN];
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	while(cin >> n)
	{
		map<string, int> mm;
		mm["pink"] = 0;
		int colors = 1;
		FOR(i, 0, n)
		{
			cin >> a >> b >> v[i].snd;
			if(mm.find(a) == mm.end())
			{
				mm[a] = colors++;
			}
			v[i].fst.fst = mm[a];
			if(mm.find(b) == mm.end())
			{
				mm[b] = colors++;
			}
			v[i].fst.snd = mm[b];
			v[i].snd = log10(v[i].snd);
		}
		FOR(i, 1, colors) init[i] = false;
		init[0] = true;
		qty[0] = log10(1.0);
#if DEBUG
		for(auto it = mm.begin(); it != mm.end(); ++it)
		{
			printf("%s -> %d\n", it->fst.c_str(), it->snd);
		}
#endif
		if(mm.find("blue") == mm.end())
		{
			printf("%.10f\n", 0.0);
		}
		else
		{
			int a, b;
			double er;
			FOR(i, 0, n)
			{
				a = v[i].fst.fst; b = v[i].fst.snd; er = v[i].snd;
				if(!init[a] && init[b])
				{
					qty[a] = er+qty[b];
					init[a] = true;
				}
				else
				{
					qty[a] = max(qty[a], er+qty[b]);
				}
			}
			int id = mm["blue"];
			if(!init[id])
			{
				printf("%.10f\n", 0.0);
				continue;
			}
			else if(qty[id] > 1) qty[id] = 10.0;
			else qty[id] = pow(10.0, qty[id]);
			printf("%.10f\n", min(10.0, qty[id]));
		}
	}
	return 0;
}