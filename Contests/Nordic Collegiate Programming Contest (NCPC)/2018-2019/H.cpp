#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 2510
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll modn = 1000000007LL;

int l, n;

bool cmp(pair<string, ii>& p1, pair<string, ii>& p2)
{
	if(p1.snd.fst == p2.snd.fst)
		return p1.snd.snd < p2.snd.snd;
	return p1.snd.fst < p2.snd.fst;	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tl = 10080;
	while(cin >> l >> n)
	{
		string s, aux;
		vector<pair<string, ii>> v;
		int p, c, t, r;
		getline(cin, aux);
		double cutPerMin,cutPerWeek; 
		FOR(i, 0, n)
		{
			getline(cin, aux);
			stringstream ss(aux);
			getline(ss, s, ',');
			getline(ss, aux, ',');
			p = stoi(aux);
			getline(ss, aux, ',');
			c = stoi(aux);
			getline(ss, aux, ',');
			t = stoi(aux);
			getline(ss, aux, ',');
			r = stoi(aux);
			cutPerMin = (double) c*t/((double) t+r);
			cutPerWeek = cutPerMin*tl;
			if(cutPerWeek > l || abs(cutPerWeek - l) < EPS)
			{
				v.emplace_back(mp(s, mp(p, i)));
			}
		}
		sort(v.begin(), v.end(), cmp);
		if(v.empty())
		{
			cout << "no such mower" << '\n';
			continue;
		}
		auto it = v.begin();
		p = it->snd.fst;
		while(it != v.end() && p == it->snd.fst)
		{
			cout << it->fst << '\n';
			it++;
		}
	}
	return 0;
}
