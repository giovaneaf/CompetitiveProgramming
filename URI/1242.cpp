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

inline bool isPair(char c1, char c2)
{
    if(c1 > c2) swap(c1, c2);
    return (c1 == 'B' && c2 == 'S') || (c1 == 'C' && c2 == 'F');
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string str;
    while(cin >> str)
    {
        stack<char> s;
        int ans = 0;
        for(char c : str)
        {
            if(s.empty() || !isPair(s.top(), c))
            {
                s.push(c);
            }
            else
            {
                s.pop();
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
