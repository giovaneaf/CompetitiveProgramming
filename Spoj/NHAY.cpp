#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 1010
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;
 
vector<int> rabin_karp(string const& s, string const& t) 
{
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
 
    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;
 
    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
 
    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) 
	{ 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		string p, s;
		cin >> p >> s;
		vector<int> rk = rabin_karp(p, s);
		for(int i = 0; i < rk.size(); ++i)
			cout << rk[i] << '\n';
		cout << '\n';
	}
	return 0;
} 