#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
ll mod = 1000000007LL;
int n, m;
string str, aux;
string rev[510];
int aa[510];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		map<string, int> mm;
		vi adj[n];
		vi L(n), p(n);
		FOR(i, 0, n)
		{
			cin >> str;
			mm[str] = i;
			rev[i] = str;
		}
		int id;
		FOR(i, 0, n)
		{
			cin >> str >> m;
			id = mm[str];
			getline(cin, aux);
			FOR(j, 0, m)
			{
				getline(cin, aux);
				stringstream ss(aux);
				ss >> aux;
				while(ss >> aux)
				{
					if(aux[(int) aux.size()-1] == ',') aux = aux.substr(0, (int) aux.size()-1);
					adj[mm[aux]].emplace_back(id);
				}
			}
		}
		int cur, pos;
		int ans = n+1;
		bool found;
		FOR(i, 0, n) // BFS n times
		{
			fill(L.begin(), L.end(), -1);
			fill(p.begin(), p.end(), -1);
			queue<int> q;
			q.push(i);
			L[i] = 0;
			found = false;
			while(q.size() && !found)
			{
				cur = q.front();
				q.pop();
				for(int& v : adj[cur])
				{
					if(L[v] == -1)
					{
						p[v] = cur; L[v] = 1 + L[cur];
						q.push(v);
					}
					else if(L[v] == 0)	// shortest loop between i and i
					{
						if(L[cur]+1 < ans)
						{
							ans = L[cur]+1;
							pos = 0;
							while(cur > -1)
							{
								aa[pos++] = cur;
								cur = p[cur];
							}
						}
						found = true;
						break;
					}
				}
			}
		}
		if(ans == n+1) 
			printf("SHIP IT\n");
		else
			FOR(i, 0, ans)
			{
				printf("%s\n", rev[aa[i]].c_str());
			}
	}
	return 0;
}
