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
 
bool isPrime(int x)
{
    if(x == 2) return true;
    if(x < 2 || ((x&1) == 0)) return false;
    FOR(i, 3, sqrt(x)+1)
    {
        if(x%i == 0) return false;
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        bool fs = false;
        FOR(i, 2, sqrt(n)+1)
        {
            if(n%i == 0 && isPrime(i))
            {
                do
                {
                    if(fs)
                        putchar(' ');
                    printf("%d", i);
                    n /= i;
                    fs = true;
                } while(n%i == 0);
            }
        }
        if(n > 1)
        {
            if(fs)
                putchar(' ');
            printf("%d", n);
        }
        putchar('\n');
    }
    return 0;
} 