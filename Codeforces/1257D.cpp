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
#define MAXN 500010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int T;

struct Warrior
{
	int p, s;
	Warrior(int p = 0, int s = 0) : p(p), s(s) {}
	bool operator< (const Warrior& w) const
	{
		if(s == w.s) return p > w.p;
		return s > w.s;
	}
};

int st[MAXN][LOGMAXN]; 	
			
void prep(int st[][LOGMAXN], vi& v, int n, bool mn){
    for(int i=n-1;i>=0;i--){
        st[i][0]=v[i];
        for(int j=1;j<LOGMAXN;j++)
			if(mn)
				st[i][j]=min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);
			else
				st[i][j]=max(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);
    }
}

int query(int st[][LOGMAXN], int i, int j, bool mn){
    int m=j-i+1;
    if(m==1)return st[i][0];
    m=(31-__builtin_clz(m));
	if(mn)
		return min(st[i][m],st[j-(1<<m)+1][m]);
	else
		return max(st[i][m],st[j-(1<<m)+1][m]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			int n, m;
			cin >> n;
			vi a(n);
			map<int, int> mm;
			int cnt = 0;
			FOR(i, 0, n)
			{
				cin >> a[i];
			}
			cin >> m;
			vector<Warrior> w(m);
			FOR(i, 0, m)
			{
				cin >> w[i].p >> w[i].s;
			}
			vi aux;
			FOR(i, 0, n)
			{
				aux.emplace_back(a[i]);
			}
			FOR(i, 0, m)
			{
				aux.emplace_back(w[i].p);
			}
			sort(aux.begin(), aux.end());
			FOR(i, 0, (int) aux.size())
			{
				if(mm.find(aux[i]) == mm.end())
				{
					if(DEBUG)
						printf("%d %d\n", aux[i], cnt);
					mm[aux[i]] = cnt++;
				}
			}
			vb seen(cnt, false);
			vi maxS(cnt, 0);
			sort(w.begin(), w.end());
			FOR(i, 0, m)
			{
				int x = mm[w[i].p];
				if(DEBUG)
					printf("filling %d %d %d\n", x, w[i].p, w[i].s);
				for(int j = x; j >= 0 && !seen[j]; --j)
				{
					seen[j] = true;
					maxS[j] = w[i].s;
				}
			}
			if(DEBUG)
			{
				FOR(i, 0, cnt)
				{
					printf("%d ", maxS[i]);
				}
				putchar('\n');
			}
			bool can = true;
			FOR(i, 0, n)
			{
				if(maxS[mm[a[i]]] == 0)
				{
					can = false;
					break;
				}
			}
			if(!can)
			{
				printf("-1\n");
			}
			else
			{
				int pos = 0;
				int ans = 0;
				prep(st, a, n, false);
				while(pos < n)
				{
					int l = pos;
					int r = n-1;
					while(r - l > 1)
					{
						int mid = (l+r)/2;
						if(maxS[mm[query(st, pos, mid, false)]] >= mid-pos+1)
						{
							l = mid;
						}
						else
						{
							r = mid-1;
						}
					}
					r = maxS[mm[query(st, pos, r, false)]] >= r-pos+1 ? r : l;
					pos = r+1;
					if(DEBUG)
						printf("pos = %d\n", pos);
					ans++;
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
