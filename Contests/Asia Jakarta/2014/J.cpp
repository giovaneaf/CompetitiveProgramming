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
#define MAXN 1000010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m;
int L[MAXN];
string str;
int st[MAXN][LOGMAXN];

void prep(){
    for(int i=n-1;i>=0;i--){
        st[i][0]=L[i];
        for(int j=1;j<LOGMAXN;j++)
            st[i][j]=min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}

int query(int i, int j){
    int m=j-i+1;
    if(m==1)return L[i];
    m=(31-__builtin_clz(m));
    return min(st[i][m],st[j-(1<<m)+1][m]);
}

inline double getCost(char& c)
{
	if(c == '_') return 0.0;
	return 0.5;
}

inline int getL(int pos)
{
	if(str[pos] == '_') return str[pos-1] == '/' ? 1 : 0;
	if(str[pos] == '/') return str[pos-1] == '/' ? 1 : 0;
	return str[pos-1] == '/' ? 0 : -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		double ans = (double) INFLL;
		cin >> n >> m;
		cin >> str;
		L[0] = 0;
		FOR(i, 1, n)
		{
			L[i] = L[i-1] + getL(i);
		}
		prep();
		int lp = 0;
		int rp = 1;
		ll accL = 0;
		double add = getCost(str[0]);
		while(rp-lp+1 <= m)
		{
			add += getCost(str[rp]);
			accL += L[rp];
			rp++;
		}
		while(rp < n)
		{
			ans = min(ans, add + accL - ((ll) query(lp, rp-1))*m);
			accL += L[rp] - L[lp];
			add += getCost(str[rp]) - getCost(str[lp]);
			lp++; rp++;
		}
		ans = min(ans, add + accL - ((ll) query(lp, rp-1))*m);
		printf("Case #%d: %.1f\n", t+1, ans);
	}
	return 0;
}
