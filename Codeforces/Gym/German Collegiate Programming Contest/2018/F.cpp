/*
In this problem you can think the fight in the reverse order, you start with a monster with life 0 and another with life 1
Then:
(0, 1) -> (1, 1) -> (1, 2) -> (3, 2) -> (3, 5) -> (8, 5) -> ...
So the only way to be possible is if there are two consecutive numbers in fibonacci sequence.
You can compute all fibonacci numbers until 10^6 and insert in a dictionary or map for example.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 50010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, ii> mm;
    int ant, fib;
    ant = 1;
    fib = 1;
    while(fib <= 1e6)
    {
        mm[fib] = mp(0, -1);
        int tmp = fib+ant;
        ant = fib;
        fib = tmp;
    }
    while(cin >> n)
    {
        int ans[n];
        int v[n];
        int idx = 0;
        FOR(i, 0, n)
        {
            cin >> v[i];
            auto it = mm.find(v[i]);
            if(it != mm.end())
            {
                it->second.first++;
                it->second.second = i+1;
            }
            if(v[i] == 1)
            {
                ans[idx++] = i+1;
            }
        }
        if(idx > 1)
        {
            printf("%d %d\n", ans[0], ans[1]);
        }
        else
        {
            bool can = false;
            for(auto it = mm.begin(); it != mm.end(); ++it)
            {
                if(it == mm.end()) break;
                auto it2 = it;
                it2++;
                if(it->second.first > 0 && it2->second.first > 0)
                {
                    can = true;
                    printf("%d %d\n", it->second.second, it2->second.second);
                    break;
                }
            }
            if(!can)
            {
                printf("impossible\n");
            }
        }
    }
    return 0;
}