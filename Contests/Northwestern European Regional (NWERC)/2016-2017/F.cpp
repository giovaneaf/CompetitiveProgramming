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
#define MAXN 1000010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n;
int w[2*MAXN];

/* Sparse Table Code Begin */

int st[2*MAXN][LOGMAXN];

void prep(){
    for(int i=n-1;i>=0;i--){
        st[i][0]=w[i];
        for(int j=1;j<LOGMAXN;j++)
            st[i][j]=max(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}

int query(int i, int j){
    int m=j-i+1;
    if(m==1)return w[i];
    m=(31-__builtin_clz(m));
    return max(st[i][m],st[j-(1<<m)+1][m]);
}

/* Sparse Table Code End */

map<int, ii> mm;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		mm.clear();
		FOR(i, 0, n)
		{
			cin >> w[i];
			if(mm.find(w[i]) == mm.end())
			{
				mm[w[i]].fst = i;
			}
			else
			{
				mm[w[i]].snd = i;
			}
		}
		FOR(i, 0, n)
		{
			cin >> w[n+i];
			if(mm.find(w[n+i]) == mm.end())
			{
				mm[w[n+i]].fst = n+i;
			}
			else
			{
				mm[w[n+i]].snd = n+i;
			}
		}
		n *= 2;
		prep();
		ii p;
		int ans = 0;
		FOR(i, 0, n)
		{
			p = mm[w[i]];
			if(p.fst < n/2 && p.snd >= n/2)
			{
				ans = max(ans, w[i]); continue;
			}
			if(p.fst+1 == p.snd || i == p.snd) continue;
			ans = max(ans, min(w[i], query(p.fst+1, p.snd-1)));
		}
		printf("%d\n", ans);
	}
	return 0;
}