#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 500010
#define MAXK 310
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
int v[MAXN];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, b;
	while(cin >> n >> b)
	{
		if(n == -1 && b == -1) break;
		b -= n;
		priority_queue<pair<ii, int>> pq;
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
			pq.push({{v[i], 1}, i});
		}
		for(int i = 0; i < b; ++i)
		{
			int t = pq.top().first.second;
			int index = pq.top().second;
			pq.pop();
			t++;
			double ppl = (double) v[index]/t;
			int p;
			if(fabs(ppl - round(ppl)) < EPS)
			{
				p = round(ppl);
			}
			else
			{
				p = ceil(ppl);
			}
			pq.push({{p, t}, index});
		}
		cout << pq.top().first.first << '\n';
	}
    return 0;
}