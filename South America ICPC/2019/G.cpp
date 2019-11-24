/*
You need to be able to find the longest common prefix from each starting point of the query strings in
in O(log(n)) or faster. You can use any suffix structure like suffix array to find this.
Then you note that you can greedily choose the largest common prefix to use and that's it.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 600010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 10000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int str[MAXN];
int SA[MAXN];
int LCP[MAXN];
int rev[MAXN];
int cur[MAXN];
int prv[MAXN];
int nxt[MAXN];
int n, sep;

class SuffixArray {
	int RA[MAXN], tempRA[MAXN];
	int tempSA[MAXN], c[MAXN];
	int Phi[MAXN], PLCP[MAXN]; //para LCP
	void countingSort(int k, int SA[]) { // O(n)
		int i, sum, maxi = max(400100, n);
		memset(c, 0, sizeof c);
		for (i = 0; i < n; i++) c[i + k < n ? RA[i + k] : 0]++;
		for (i = sum = 0; i < maxi; i++) {
			int t = c[i];
			c[i] = sum;
			sum += t;
		}
		for (i = 0; i < n; i++)
			tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
		for (i = 0; i < n; i++) SA[i] = tempSA[i];
	}
public:
	int n;
	void constructSA(int str[], int SA[]) { // O(nlogn)
		int i, k, r; //n = strlen(str);
		for (i = 0; i < n; i++) RA[i] = str[i];
		for (i = 0; i < n; i++) SA[i] = i;
		for (k = 1; k < n; k <<= 1) {
			countingSort(k, SA);
			countingSort(0, SA);
			tempRA[SA[0]] = r = 0;
			for (i = 1; i < n; i++) 
				tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
			for (i = 0; i < n; i++) RA[i] = tempRA[i];
			if (RA[SA[n-1]] == n-1) break;
		}
	}
	void computeLCP(int str[], int SA[], int LCP[]) { // O(n)
		int i, L; //n = strlen(str);
		Phi[SA[0]] = -1;
		for (i = 1; i < n; i++)  Phi[SA[i]] = SA[i-1];
		for (i = L = 0; i < n; i++) {
			if (Phi[i] == -1) {
				PLCP[i] = 0; continue;
			}
			while (str[i + L] == str[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max(L-1, 0);
		}
		for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
	}
};

int st[MAXN][LOGMAXN]; 		// sparse table
			
void prep(){
    for(int i=n-1;i>=0;i--){
        st[i][0]=LCP[i];
        for(int j=1;j<LOGMAXN;j++)
            st[i][j]= min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);
			//        | change max for min if min query needed
    }
}

int query(int i, int j){
    int m=j-i+1;
    if(m==1)return st[i][0];
    m=(31-__builtin_clz(m));
    return min(st[i][m],st[j-(1<<m)+1][m]);
	//      | change max for min if min query needed
}

// just use prep() before using
// then just query range [l, r] --> 0-index based, so you can query in range [0, n-1]

SuffixArray sa;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		n = 0, sep = 1;
		for(char& c : s)
		{
			str[n++] = c+400000;
		}
		str[n++] = sep++;
		int Q;
		cin >> Q;
		while(Q--)
		{
			cin >> s;
			for(char& c : s)
			{
				str[n++] = c+400000;
			}
			str[n++] = sep++;
		}
		str[n] = 0;
		sa.n = n;
		sa.constructSA(str, SA);
		sa.computeLCP(str, SA, LCP);
		/*FOR(i, 0, n)
		{
			printf("%d %d\n", SA[i], LCP[i]);
		}*/
		FOR(i, 0, n)
		{
			rev[SA[i]] = i;
		}
		int cnt = 0;
		FOR(i, 0, n)
		{
			if(str[i] < 400000)
			{
				cur[rev[i]] = -1;
				cnt++; continue;
			}
			cur[rev[i]] = cnt;
		}
		int pp = -1;
		int nn = -1;
		FOR(i, 0, n)
		{
			if(cur[i] == 0) pp = i;
			prv[i] = pp;
			if(cur[n-1-i] == 0) nn = n-i-1;
			nxt[n-1-i] = nn;
		}
		prep();
		int idx = 0;
		while(str[idx] >= 400000) idx++;
		while(idx < n)
		{
			idx++;
			if(idx >= n) break;
			int ans = 0;
			while(str[idx] >= 400000)
			{
				int lcp = 0;
				int id = rev[idx];
				if(prv[id] > -1) lcp = query(prv[id]+1, id);
				if(nxt[id] > -1) lcp = max(lcp, query(id+1, nxt[id]));
				if(lcp == 0)
				{
					ans = -1;
					break;
				}
				ans++;
				idx += lcp;
			}
			if(ans == -1)
			{
				while(str[idx] >= 400000) idx++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

