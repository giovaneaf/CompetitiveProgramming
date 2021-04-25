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
#define MAXN 10000010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;

int computeSubtree(int cur, vvi& adj, vi& sub)
{
	sub[cur] = 1;
	for(int& v : adj[cur])
	{
		if(sub[v] > 0) continue;
		sub[cur] += computeSubtree(v, adj, sub);
	}
	return sub[cur];
}

string encode(int cur, vvi& adj, int dad)
{
	string s;
	s = '(';
	vector<string> str;
	for(int& v : adj[cur])
	{
		if(v == dad) continue;
		str.push_back(encode(v, adj, cur));
	}
	sort(str.begin(), str.end());
	for(string& ss : str)
		s += ss;
	s += ')';
	return s;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		vvi adjA(n);
		vvi adjB(n);
		int a, b;
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			a--, b--;
			adjA[a].push_back(b);
			adjA[b].push_back(a);
		}
		FOR(i, 0, n-1)
		{
			cin >> a >> b;
			a--, b--;
			adjB[a].push_back(b);
			adjB[b].push_back(a);
		}
		vi subA(n, 0);
		vi subB(n, 0);
		computeSubtree(0, adjA, subA);
		computeSubtree(0, adjB, subB);
		/*FOR(i, 0, n)
		{
			printf("%d ", subA[i]);
		}
		putchar('\n');
		FOR(i, 0, n)
		{
			printf("%d ", subB[i]);
		}
		putchar('\n');*/
		int c1, c2;
		string s1, s2;
		c1 = c2 = -1;
		int cur = 0;
		int dad = -1;
		int half = n/2;
		bool other;
		while(true)
		{
			other = false;
			for(int& v : adjA[cur])
			{
				if(v == dad) continue;
				if(subA[v] > half)
				{
					dad = cur;
					cur = v;
					other = true;
					break;
				}
			}
			if(!other)
			{
				c1 = cur;
				for(int& v : adjA[cur])
				{
					if(v == dad) continue;
					if(subA[v] == half)
					{
						c2 = v;
						break;
					}
				}
				break;
			}
		}
		s1 = encode(c1, adjA, -1);
		c1 = c2 = -1;
		cur = 0;
		dad = -1;
		while(true)
		{
			other = false;
			for(int& v : adjB[cur])
			{
				if(v == dad) continue;
				if(subB[v] > half)
				{
					dad = cur;
					cur = v;
					other = true;
					break;
				}
			}
			if(!other)
			{
				c1 = cur;
				for(int& v : adjB[cur])
				{
					if(v == dad) continue;
					if(subB[v] == half)
					{
						c2 = v;
						break;
					}
				}
				break;
			}
		}
		bool eq = false;
		s2 = encode(c1, adjB, -1);
		if(s1 == s2)
			eq = true;
		if(c2 > -1)
			s2 = encode(c2, adjB, -1);
		if(s1 == s2)
			eq = true;
		printf("%c\n", eq ? 'S' : 'N');
	}
	return 0;
}