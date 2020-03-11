#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
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
#define mp(a, b) make_pair(a, b)
 
 
int main()
{
    int n, m;
    cin >> n >> m;
    vi freq(45, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            freq[i+j]++;
    int ans = 0;
    for(int i = 2; i < freq.size(); ++i)
    {
        if(freq[ans] < freq[i]) ans = i;
    }
    int i = ans;
    do
    {
        printf("%d\n", i);
        i++;
    }
    while(i <= n+m && freq[i] == freq[ans]);
    return 0;
}
close