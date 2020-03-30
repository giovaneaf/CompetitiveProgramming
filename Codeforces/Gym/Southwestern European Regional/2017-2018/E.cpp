/*
The main ideia here is to do a toposort to update each pizza according to statement.
Then you have the pair (cost, prestige) for each pizza and you need to compute the Knapsack without repetitions
to maximize the prestige value. You can recover the cost to get the prestige from a top down Knapsack just by 
taking the minimum column (cost) that has the prestige equal to the B column.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 2000000000
#define EPS 1e-9

string a[1000010];
string b[1000010];
int c[1000010];
int p[1000010];
pair<int, int> memo[10010];
int deg[10010];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int B, n;
    cin >> B >> n;
    map<string, int> mm;
    int cnt = 0;
    string ignore;
    FOR(i, 0, n)
    {
        cin >> a[i] >> b[i] >> ignore >> c[i] >> p[i];
        if(mm.find(a[i]) == mm.end())
            mm[a[i]] = cnt++;
    }
    FOR(i, 0, cnt) 
    {
        memo[i] = {1000000000, 0};
        deg[i] = 0;
    }
    vector<pair<int, pair<int, int>>> adj[10010];
    FOR(i, 0, n)
    {
        if(mm.find(b[i]) == mm.end())
        {
            int idx = mm[a[i]];
            if(c[i] < memo[idx].first || (c[i] == memo[idx].first && p[i] > memo[idx].second))
            {
                memo[idx] = {c[i], p[i]};
            }
        }
        else
        {
            int idxa = mm[a[i]];
            int idxb = mm[b[i]];
            adj[idxb].emplace_back(mp(idxa, mp(c[i], p[i])));
            deg[idxa]++;
        }
    }
    queue<int> q;
    FOR(i, 0, cnt) 
    {
        if(deg[i] == 0) q.push(i);
    }
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(pair<int, pair<int, int>> p : adj[cur])
        {
            int nc, np;
            nc = p.second.first + memo[cur].first;
            np = p.second.second + memo[cur].second;
            if(nc < memo[p.first].first || (nc == memo[p.first].first && np > memo[p.first].second))
            {
                memo[p.first] = {nc, np};
            }
            deg[p.first]--;
            if(deg[p.first] == 0) q.push(p.first);
        }
    }
    int knapsack[2][10010];
    memset(knapsack, 0, sizeof(knapsack));
    int it = 0;
    for(int i = 0; i < cnt; ++i)
    {
        for(int j = 0; j <= B; ++j)
        {
            knapsack[it][j] = knapsack[it^1][j];
            if(memo[i].first <= j)
            {
                knapsack[it][j] = max(knapsack[it][j], memo[i].second + knapsack[it^1][j - memo[i].first]);
            }
        }
        it ^= 1;
    }
    it ^= 1;
    int x = B;
    while(x > 0 && max(knapsack[it][x-1], knapsack[it^1][x-1]) == max(knapsack[it][x], knapsack[it^1][x])) x--;
    printf("%d\n%d\n", knapsack[it][B], x);
	return 0;
}