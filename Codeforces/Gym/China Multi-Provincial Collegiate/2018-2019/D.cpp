/*
Here I simulated the values and discovered the formula.
I don't know exactly why this is the correct value.
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
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int a, b;
        cin >> a >> b;
        double ans1 = 0.5;
        if(a == 1)
            ans1 = 1.0;
        double ans2;
        if(b == 1)
            ans2 = 1.0;
        else if(b&1)
        {
            int gap = (b-3)/2;
            ans2 = (double) (2+gap)/(3+gap*2);
        }
        else
        {
            int gap = (b-2)/2;
            ans2 = (double) (3+gap*2)/(4+gap*4);
        }
        printf("Case #%d: %.6f %.6f\n", t+1, ans1, ans2);
    }
    return 0;
}