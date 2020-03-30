/*
Because the colors are only 3 colors and each one cycles in the same order if you go line by line or column by column
you can just reduce the grid by a 3x3 grid just adding the widths or heights getting the modulo (%) 3. Then you just
compute the area of the resulting rectangle for each color.
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
#define MAXN 1000010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    ll col[n];
    ll row[n];
    ll ans[3];
    ll sum[3];
    memset(ans, 0LL, sizeof(ans));
    memset(sum, 0LL, sizeof(sum));
    FOR(i, 0, n)
    {
        cin >> col[i];
        sum[i%3] += col[i];
    }
    FOR(i, 0, n)
    {
        cin >> row[i];
    }
    FOR(i, 0, n)
    {
       FOR(j, 0, 3)
       {
           ans[(i+j)%3] += sum[j]*row[i];
       }
    }
    FOR(i, 0, 3)
    {
        if(i > 0)
            putchar(' ');
        printf("%lld", ans[(i+1)%3]);
    }
    putchar('\n');
    return 0;
}