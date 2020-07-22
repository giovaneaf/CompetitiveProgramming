#include <bits/stdc++.h>

#define INF 1000000000000000000LL

using namespace std;

typedef long long ll;

const int N = 11;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
	if (b == 0) return {1, 0, a};
	GCD_type pom = ex_GCD(b, a % b);
	return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int b, z;
long long a[N+1], n[N+1];

ll CRT()
{
	ll ans = a[1];
	ll lcm = n[1];
	for(int i = 2; i <= b; i++)
	{
		auto pom = ex_GCD(lcm, n[i]);
		int x1 = pom.x;
		int d = pom.d;
		if((a[i] - ans) % d != 0) return -1LL;
		ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
		lcm = LCM(lcm, n[i]);
	}
	return ans;
}
const int Z = 101;

pair<int, int> dist[Z+1];
int adj[N+1][Z+1];
bool zoo[Z+1];
int P[N+1];

void DFS(int beast, int curZoo, int time)
{
	dist[curZoo] = {0, time};
	if(dist[adj[beast][curZoo]].first == -1)
	{
		DFS(beast, adj[beast][curZoo], time+1);
	}
	else
	{
		int u = adj[beast][curZoo];
		if(u != curZoo)
		{
			int cycleLenght = time - dist[u].second + 1;
			while(u != curZoo)
			{
				dist[u].first = cycleLenght;
				u = adj[beast][u];
			}
			dist[u].first = cycleLenght;
		}
		else
			dist[u].first  = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> b >> z)
	{
		vector<pair<int, int>> binfo[z];
		for(int i = 0; i < b; ++i)
		{
			cin >> P[i];
			P[i]--;
			for(int j = 0; j < z; ++j)
			{
				cin >> adj[i][j];
				adj[i][j]--;
			}
		}
		if(b == 1)
		{
			cout << P[0]+1 << " 0\n";
			continue;
		}
		memset(zoo, true, sizeof(zoo));
		for(int i = 0; i < b; ++i)
		{
			for(int j = 0; j < z; ++j)
				dist[j] = {-1, -1};
			DFS(i, P[i], 0);
			for(int j = 0; j < z; ++j)
			{
				if(dist[j].first == -1) zoo[j] = false;
				else binfo[j].push_back(dist[j]);
			}
		}
		ll time = -1LL;
		int zooTime = -1;
		for(int i = 0; i < z; ++i)
		{
			if(zoo[i])
			{
				sort(binfo[i].begin(), binfo[i].end());	// sort to check if any animal cycle
				if(binfo[i][0].first == 0)				// if animal doesn't cycle in this zoo
				{
					// time is not an unkown, CRT isn't valid not modular equation
					int T = binfo[i][0].second;			// they can only met in this time at this zoo
					bool can = true;
					for(int j = 1; j < binfo[i].size(); ++j)
					{
						if(binfo[i][j].first == 0)	// if animal doesn't cycle in this zoo
						{
							if(T != binfo[i][j].second)	// then it's only possible if they met in the same T
							{
								can = false; break;
							}
						}
						else						// if animal cycle in this zoo
						{
							int nT = T - binfo[i][j].second;	// check if animal met at the same zoo at time T
							if(nT < 0 || (nT%binfo[i][j].first > 0))
							{
								can = false; break;
							}
							
						}
					}
					if(can && (time == -1LL || (time > T))) // update answer if they met
					{
						time = (ll) T;
						zooTime = i;
					}
				}
				else
				{
					for(int j = 0; j < b; ++j)
					{
						a[j+1] = (ll) binfo[i][j].second; 	// first time in zoo i
						n[j+1] = (ll) binfo[i][j].first; 	// modulo = cycle length
					}
					ll crt = CRT();							// compute the time via crt
					if(crt != -1LL && (time == -1LL || (time > crt)))	// update answer if they met
					{
						time = crt;
						zooTime = i;
					}
				}
			}
		}
		if(time == -1LL) cout << '*';
		else cout << zooTime+1 << ' ' << time;
		cout << '\n';
	}
	return 0;
}