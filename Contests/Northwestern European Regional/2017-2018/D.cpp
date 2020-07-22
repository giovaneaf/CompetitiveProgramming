#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
int n, m;
 
int main()
{
	cin >> n;
	vector<string> v(n);
	map<string, int> cnt;
	for(int i = 0; i < n; ++i) 
	{
		cin >> v[i];
		cnt[v[i]]++;
	}
	cin >> m;
	map<string, string> mp;
	map<string,pair<ll, ll>> nm;
	bool unique = true;
	bool correct = true;
	for(int i = 0; i < m; ++i)
	{
		string a, b, c;
		cin >> a >> b >> c;
		if(mp.find(a) == mp.end())
		{
			mp[a] = b;
			nm[a] = {0LL, 0LL};
		}
		else if(cnt[a] > 0) unique = false;
		if(c[0] == 'i')
		{
			nm[a].second++;
			if(cnt[a] > 0) correct = false;
		}
		else nm[a].first++;
	}
	if(unique)
	{
		cout << mp[v[0]];
		for(int i = 1; i < n; ++i)
			cout << ' ' << mp[v[i]];
		cout << '\n' << (correct ? "correct" : "incorrect") << '\n';
	}
	else
	{
		unsigned long long all, correct;
		all = correct = 1LL;
		for(auto it = nm.begin(); it != nm.end(); ++it)
		{
			string a = it->first;
			unsigned long long cr = it->second.first;
			unsigned long long aa = cr + it->second.second;
			int size = cnt[a];
			for(int i = 0; i < size; ++i)
			{
				all *= aa;
				correct *= cr;
			}
		}
		cout << correct << " correct\n";
		cout << (all-correct) << " incorrect\n";
	}
}