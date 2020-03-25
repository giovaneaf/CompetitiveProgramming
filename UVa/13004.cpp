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
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int dp[21][177150][3];
string s;
string tmp;

vi getCntArr(int cnt)
{
	vi freq(10);
	FOR(i, 0, 10)
	{
		freq[i] = cnt%3;
		cnt /= 3;
	}
	return freq;
}

int getCntNum(vi& cnt)
{
	int ans = 0;
	int pw = 1;
	FOR(i, 0, 10)
	{
		ans += pw*cnt[i];
		pw *= 3;
	}
	return ans;
}

inline bool isViable(vi& cnt)
{
	FOR(i, 0, 10)
	{
		if(cnt[i] > 2) return false;
	}
	return true;
}

bool B(int pos, int cnt, bool tight)
{
	vi v = getCntArr(cnt);
	if(pos >= (int) s.size()) 
		return true;
	if(dp[pos][cnt][tight] == -1)
	{
		for(int i = 9; i >= 0; --i)
		{
			if((tight && (s[pos]-'0') < i) || v[i] >= 2) continue;
			tmp[pos] = i + '0';
			v[i]++;
			if(B(pos+1, getCntNum(v), tight && ((s[pos]-'0') == i)))
				return dp[pos][cnt][tight] = 1;
			v[i]--;
		}
		dp[pos][cnt][tight] = 0;
	}
	return dp[pos][cnt][tight];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> s)
	{
		tmp.resize((int) s.size());
		memset(dp, -1, sizeof(dp));
		B(0, 0, true);
		printf("%s\n", tmp[0] == '0' ? tmp.substr(1).c_str() : tmp.c_str());
	}
	return 0;
}
