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
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int sum = 1;
        FOR(i, 2, sqrt(n))
        {
            if(n%i == 0)
            {
                sum += i + n/i;
            }
        }
        int y = round(sqrt(n));
        if(y*y == n) sum += y;
        if(n == 1) sum = 0;
        printf("%d\n", sum);
    }
    return 0;
} 