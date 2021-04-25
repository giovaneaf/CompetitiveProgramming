#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MAXWORDS 1010
 
const ll mod = 1000000007LL;
int n, m;

class SuffixArray {
	int RA[MAXN], tempRA[MAXN];
	int tempSA[MAXN], c[MAXN], n;
	int Phi[MAXN], PLCP[MAXN]; //para LCP
	void countingSort(int k, int SA[]) { // O(n)
		int i, sum, maxi = max(300, n);
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
	void constructSA(char str[], int SA[]) { // O(nlogn)
		int i, k, r; n = strlen(str);
		str[n++] = '$'; str[n] = 0;
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
	void computeLCP(char str[], int SA[], int LCP[]) { // O(n)
		int i, L; n = strlen(str);
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

SuffixArray sa;

char str[MAXN];
int SA[MAXN], LCP[MAXN];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> str;
		n = strlen(str);
		sa.constructSA(str, SA);
		sa.computeLCP(str, SA, LCP);
		int ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			ans = max(ans, LCP[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}