/*
Optimized version of the hospitals/residents version of stable marriage
in order to solve problem L (SWERC 2020-2021)
If capacity vector is equal to 1 then it is stable marriage algorithm
*/

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
#define MAXN 50010
#define LOGMAXN 23
#define MAXM 10010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int n, m;

int capacity[MAXM]; // set to 1 for stable marriage problem
int match[MAXN];
int idx[MAXN];
int clients[MAXM];

void GaleShapley(vi* prefn, vi* prefm)
{
	memset(match, -1, sizeof(match));
	memset(idx, 0, sizeof(idx));
	memset(clients, 0, sizeof(clients));
	map<ii, int> mm;
	FOR(j, 0, m)
	{
		FOR(i, 0, (int) prefm[j].size())
		{
			mm[mp(prefm[j][i], j)] = i;
		}
	}
	queue<int> q;
	priority_queue<ii> pq[m];
	FOR(i, 0, n)
	{
		q.push(i);
	}
	int i, j, k;
	do
	{
		i = q.front();
		q.pop();
		if(match[i] == -1)
		{
			if(idx[i] < (int) prefn[i].size())
			{
				j = prefn[i][idx[i]];
				idx[i]++;
				match[i] = j;
				pq[j].push(mp(mm[mp(i, j)], i));
				if(clients[j] == capacity[j])
				{
					k = pq[j].top().second;
					pq[j].pop();
					match[k] = -1;
					if(idx[k] < (int) prefn[k].size())
						q.push(k);
				}
				else
				{
					clients[j]++;
				}
			}
		}
	} while(q.size());
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		vi prefn[n];
		vi prefm[m];
		FOR(i, 0, m)
			cin >> capacity[i];
		string str;
		getline(cin, str);
		FOR(i, 0, n)
		{
			getline(cin, str);
			stringstream ss(str);
			while(ss.good())
			{
				ss >> str;
				prefn[i].push_back(stoi(str)-1);
			}
		}
		FOR(i, 0, m)
		{
			getline(cin, str);
			stringstream ss(str);
			while(ss.good())
			{
				ss >> str;
				prefm[i].push_back(stoi(str)-1);
			}
		}
		GaleShapley(prefn, prefm);
		FOR(i, 0, n)
		{
			if(match[i] > -1)
				printf("%d\n", i+1);
		}
	}
	return 0;
}