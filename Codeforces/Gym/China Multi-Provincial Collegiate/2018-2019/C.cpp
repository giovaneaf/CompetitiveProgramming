/*
Just compute the difference between encrypted string and actual string for the first letter (it's always valid because
the strings isn't empty in the input) you can sum the modulo (26) and then apply modulo (26) of the value to make sure it's
positive.
Then you need to decrypt the given string just by applying the difference computed (you need to subtract the difference)
again you can sum and then apply modulo operation to give a positive value.
*/

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
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    FOR(t, 1, T+1)
    {
        int shift;
        int n, m;
        cin >> n >> m;
        string a, b, c;
        cin >> a >> b >> c;
        shift = (b[0]-a[0]+26)%26;
        printf("Case #%d: ", t);
        FOR(i, 0, (int) c.size())
        {
            printf("%c", (c[i]-'A'-shift+26)%26+'A');
        }
        putchar('\n');
    }
    return 0;
}
close