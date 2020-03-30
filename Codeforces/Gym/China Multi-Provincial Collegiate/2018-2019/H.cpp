/*
The first thing to note is that you can kill the monster's from the highest (damage/turns to kill) to lowest.
There are two main ways to compute the number of turns to kill a monster with x health points.
The first things is since you will hit 1, then 2, then 3, then 4 and so on you will keep with this:
1 + 2 + 3 + ... + n = n*(n+1)/2 (Arithmetic Progression formula).
Now with this you can compute it solving the second degree equation n*(n+1)/2 = x (just use ceil because you'll
get a float number) or you can binary search the number of turns (like it's commented in the code below).
Then you just simulate killing the monsters in this order that is written in the first line of this explanation.
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
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
long long hp[MAXN];
long long att[MAXN];
long long turn[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int n;
        long long sum = 0LL;
        long long ans = 0LL;
        cin >> n;
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n; ++i)
        {
            cin >> hp[i] >> att[i];
            sum += (long long) att[i];
            ll tt;
            // It's possible to do binary search to compute the number of turns to kill the monster
            /*ll l, h;
            l = 1LL;
            h = 100000000LL;
            while(h-l > 1LL)
            {
                ll mid = (h+l) >> 1;
                if((mid*(mid+1))/2 <= hp[i])
                    l = mid;
                else
                    h = mid;
            }
            tt = (l*(l+1)/2 >= hp[i] ? l : h);*/
            tt = (long long) ceil(((-1 + sqrt(1+8*hp[i]))/2.0));
            turn[i] = tt;
            pq.push({(double) att[i]/turn[i], i});
        }
        while(pq.size())
        {
            pair<double, int> p = pq.top();
            pq.pop();
            ans += (sum*turn[p.second]);
            sum -= att[p.second];
        }
        printf("Case #%d: %lld\n", t+1, ans);
    }
    return 0;
}