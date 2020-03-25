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
#define INF 1e9
#define EPS 1e-9
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        bool fs = false;
        FOR(i, 2, n)
        {
            if(i%x == 0 && i%y > 0)
            {
                if(fs)
                {
                    putchar(' ');
                }
                printf("%d", i);
                fs = true;
            }
        }
        if(fs)
            putchar('\n');
    }
    return 0;
} 