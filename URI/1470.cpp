#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 100010
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int maxm;
int minm;

void print(vi& cur)
{
    for(int i = 0; i < cur.size(); ++i)
    {
        cout << cur[i] << " ";
    }
    putchar('\n');
}

bool solve(vi& cur, vi& target)
{
	if(cur.size() == target.size())
	{
	    if(cur == target)
		    return true;
		vi a = cur;
		reverse(a.begin(), a.end());
		return a == target;
	}
	bool ans = false;
	for(int i = 0; i < cur.size()/2; ++i)
	{
		int size = i+1;
		vector<int> adj;
		for(int j = cur.size() - 1; j >= 2*size; --j)
		{
			adj.push_back(cur[j]);
		}
		for(int j = 0; j < size; ++j)
		{
			adj.push_back(cur[j] + cur[2*size-1-j]);
		}
		if(adj.size() < target.size() || *max_element(adj.begin(), adj.end()) > maxm) continue;
		if(*min_element(adj.begin(), adj.end()) > minm) continue;
		ans = ans || solve(adj, target);
		if(ans)
			return ans;
	}
	int size = 1;
	for(int i = cur.size()-2; i >= cur.size()/2; --i)
	{
		vector<int> adj;
		for(int j = 0; j < cur.size() - 2*size; ++j)
		{
			adj.push_back(cur[j]);
		}
		int cnt = 0;
		for(int j = cur.size() - 2*size; j <= i; ++j)
		{
			adj.push_back(cur[j] + cur[j + 2*size-1-cnt]);
			cnt += 2;
		}
		size++;
		if(adj.size() < target.size() || *max_element(adj.begin(), adj.end()) > maxm) continue;
		if(*min_element(adj.begin(), adj.end()) > minm) continue;
		ans = ans || solve(adj, target);
		if(ans)
			return ans;
	}
	return ans;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int maxn = 0;
		int minn = 1000000000;
		int s1 = 0;
		vi start(n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &start[i]);
			maxn = max(maxn, start[i]);
			minn = min(minn, start[i]);
			s1 += start[i];
		}
		maxm = 0;
		minm = 1000000000;
		int m;
		int s2 = 0;
		scanf("%d", &m);
		vi target(m);
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", &target[i]);
			maxm = max(maxm, target[i]);
			minm = min(minm, target[i]);
			s2 += target[i];
		}
		if(maxn > maxm || minn > minm || n < m || s1 != s2) 
		{
			printf("N");
		}
		else
		{
			bool ans = solve(start, target);
			if(ans)
				printf("S");
			else
				printf("N");
		}
		putchar('\n');
	}
	return 0;
}