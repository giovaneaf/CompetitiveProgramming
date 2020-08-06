#include <bits/stdc++.h>
 
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, a, b) for(int i = a; i >= b; --i)
#define fst first
#define snd second
 
using namespace std;
 
int n, m;;
 
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        vii v(n);
        FOR(i, 0, n)
        {
            cin >> v[i].fst >> v[i].snd;
        }
        set<int> s;
        cin >> m;
        vi p(m);
        FOR(i, 0, m)
        {
            cin >>  p[i];
            s.insert(p[i]);
        }
        vi nPegs(n, 0);
        int j = 0;
        bool can = true;
        FOR(i, 0, n)
        {
            while(j < m && p[j] < v[i].fst) j++;
            while(j < m && v[i].fst <= p[j] && p[j] < v[i].snd)
            {
                j++; nPegs[i]++;
            }
            if(j < m && p[j] == v[i].snd) nPegs[i]++;
            if(nPegs[i] > 2)
            {
                can = false;
                break;
            }
        }
        if(!can)
        {
            printf("impossible\n");
        }
        else
        {
            vi ans;
            FOR(i, 0, n)
            {
                if(nPegs[i] < 2)
                {
                    if(s.find(v[i].snd) == s.end())
                    {
                        if(i < n-1 && nPegs[i+1] < 2 && v[i+1].fst == v[i].snd)
                        {
                            s.insert(v[i].snd);
                            ans.emplace_back(v[i].snd);
                            nPegs[i]++; nPegs[i+1]++;
                        }
                    }
                    while(nPegs[i] < 2)
                    {
                        int mid = (v[i].snd+v[i].fst)/2;
                        while(s.find(mid) != s.end()) mid++;
                        nPegs[i]++;
                        s.insert(mid);
                        ans.emplace_back(mid);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            printf("%d\n", (int) ans.size());
            FOR(i, 0, (int) ans.size())
            {
                if(i > 0) putchar(' ');
                printf("%d", ans[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}