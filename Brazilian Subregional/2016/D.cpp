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
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int n = INF;
    int j;
    FOR(i, 2, sqrt(C)+1)
    {
        j = i;
        if(C%j == 0)
        {
            if(j < n && j%A == 0 && j%B > 0 && D%j > 0)
                n = j;
            j = C/j;
            if(j < n && C%j == 0 && j%A == 0 && j%B > 0 && D%j > 0)
                n = j;
        }
    }
    printf("%d\n", n == INF ? -1 : n);
    return 0;
}