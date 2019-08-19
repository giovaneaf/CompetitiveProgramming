/*
https://www.spoj.com/problems/NAJPF/
Implement Knuth-Morris-Pratt (KMP) algorithm.
*/

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
class KMP {
	string P;
	vector<int> b;
	int m;
public:
	KMP(const char* _P) : P(_P) {
		m = P.size(); b.assign(m+1, -1);
		for(int i = 0, j = -1; i < m;) {
			while (j >= 0 && P[i] != P[j]) j = b[j];
			b[++i] = ++j;
		}
	}
	vector<int> match(const char* T) {
		vector<int> ans;
		for (int i=0, j=0, n=strlen(T); i < n;) {
			while (j >= 0 && T[i] != P[j]) j = b[j];
			i++; j++;
			if (j == m) {
				ans.push_back(i - j);
				j = b[j];
			}
		}
		return ans;
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		string a, b;
		cin >> a >> b;
		KMP kmp(b.c_str());
		vector<int> index = kmp.match(a.c_str());
		if((int) index.size() > 0) printf("%d\n", (int) index.size());
		FOR(i, 0, (int) index.size())
		{
			if(i > 0) putchar(' ');
			printf("%d", index[i]+1);
		}
		if((int) index.size() == 0) printf("Not Found");
		puts("");
		if(t < T-1) puts("");
	}
	return 0;
}  
