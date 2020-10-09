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

int n, m, q, k;

class KMP {
public:
	string P;
	vector<int> b;
	KMP(const char _P[]) : P(_P) {
		int m = P.size();
		b.assign(m + 1, -1);
		for(int i = 0, j = -1; i < m;) {
			while (j >= 0 && P[i] != P[j]) j = b[j];
			b[++i] = ++j;
		}
	}
	vector<int> match(const char T[]) {
		vector<int> ans;
		for (int i = 0, j = 0, n = strlen(T); i < n;) {
			while (j >= 0 && T[i] != P[j]) j = b[j];
			i++; j++;
			if (j == (int)P.size()) {
				ans.push_back(i - j);
				j = b[j];
			}
		}
		return ans;
	}
	int repetend() {
		int n = P.size();
		int ans = n - b[n];
		if (n % ans) ans = n;
		return ans;
	}
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		n = s.size();
		KMP kmp(s.c_str());
		int ans = -1;
		if(kmp.b[n] > 0)
		{
			RFOR(i, n-1, 0)
			{
				if(kmp.b[i] == kmp.b[n])
				{
					ans = kmp.b[n];
					break;
				}
			}
			if(ans == -1)
			{
				if(kmp.b[kmp.b[n]] > 0) ans = kmp.b[kmp.b[n]];
			}
		}
		printf("%s\n", ans == -1 ? "Just a legend" : s.substr(0, ans).c_str());
	}
	return 0;
} 