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
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n, m;
vector<string> ans[2];
vector<string> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
	getline(cin, str);
	stringstream ss(str);
	int k = 0;
	while(ss >> str) k++;
	cin >> n;
	v.resize(n);
	FOR(i, 0, n) cin >> v[i];
	int it, pos;
	it = pos = 0;
	while(n > 1)
	{
		pos = (pos+k-1)%n;
		ans[it].emplace_back(v[pos]);
		v.erase(v.begin()+pos);
		it ^= 1;
		n--;
	}
	ans[it].emplace_back(v[0]);
	FOR(i, 0, 2)
	{
		printf("%d\n", ans[i].size());
		for(string& s : ans[i])
		{
			printf("%s\n", s.c_str());
		}
	}
	return 0;
}