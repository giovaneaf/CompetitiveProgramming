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
#define MAXN 210
#define LOGMAXN 20
#define INF 1e9
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        int cnt = 0;
        FOR(i, 0, n)
        {
            bool can = true;
            FOR(j, 0, m)
            {
                int a;
                cin >> a;
                if(a == 0)
                    can = false;
            }
            if(can) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}