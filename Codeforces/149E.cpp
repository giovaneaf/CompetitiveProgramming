#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXM 44100
#define LOGMAXN 20
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n;
int st[MAXN][LOGMAXN]; // sparse table for suffix
			
void prep(int st[][LOGMAXN], vi& v){
    for(int i=n-1;i>=0;i--){
        st[i][0]=v[i];
        for(int j=1;j<LOGMAXN;j++)
            st[i][j]=max(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}

int query(int i, int j, int st[][LOGMAXN]){
    int m=j-i+1;
    if(m==1)return st[i][0];
    m=(31-__builtin_clz(m));
    return max(st[i][m],st[j-(1<<m)+1][m]);
}


struct KMP
{
	string P;
	vector<int> b;
	KMP(string& s) : P(s)
	{
		int n = P.size();
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
	vi match(string& T)
	{
		int n = T.size();
		vi ans(n, 0);
		int j = 0;
		FOR(i, 0, n)
		{
			while(j > 0 && T[i] != P[j]) j = b[j-1];
			if(T[i] == P[j])
			{
				j++;
				ans[i] = j;
				if(j == (int) P.size())
				{
					j = b[j-1];
				}
			}
			else
				ans[i] = j;
		}
		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string t;
	while(cin >> t)
	{
		string rt = t;
		reverse(rt.begin(), rt.end());
		int q;
		cin >> q;
		int ans = 0;
		while(q--)
		{
			string p;
			cin >> p;
			if((int) p.size() <= 1) continue;
			KMP kmp(p);
			vi x = kmp.match(t);
			reverse(p.begin(), p.end());
			KMP rkmp(p);
			vi y = rkmp.match(rt);
			n = (int) t.size();
			prep(st, y);
			FOR(i, 0, n-1)
			{
				if(x[i] > 0 && x[i] < n)	// if has common prefix and isn't all string
				{
					int comp = n-2-i;
					int mx = query(0, comp, st); // check maximum suffix in the rest of string
					if(mx >= (int) p.size()-x[i])
					{
						ans++;
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
