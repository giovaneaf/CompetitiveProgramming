/*
Here you can compute for each position starting at index i the largest square you can build with binary search because
if you think about it, if you can't build a square of size k starting from i then you can't build a largest square starting
at the same position i. So you need to binary search in the largest index j you can end the square the size of the square
will be j-i+1 if you are building a square in range [i, j]. You can compute if it's possible to build a square from i to j
by querying the maximum value from the ai's (called lb) and querying the minimum value from the bi's (called rb) 
then you can build a square from i to j if rb-lb+1 >= j-i+1 because the rb-lb+1 is the number of columns available to use
in the rows from i to j.
Note that the largest square you can build from [i, j] is min(j-i+1, rb-lb+1).
You need a RMQ for maximum and minimum, I used sparse table because the query is O(1) and there are no updates.
Then you just binary search for the maximum starting from each point i.
*/

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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9
#define EPS 1e-9

int n;
int a[MAXN];
int b[MAXN];
int stn[MAXN][LOGMAXN];
int stx[MAXN][LOGMAXN];
 
void prep(bool mn)
{
    if(mn)
    {
        for(int i=n-1;i>=0;i--)
        {
            stn[i][0]=b[i];
            for(int j=1;j<LOGMAXN;j++)
                stn[i][j]=min(stn[i][j-1],stn[min(i+(1<<(j-1)),n-1)][j-1]);       
        }
    }
    else
    {
       for(int i=n-1;i>=0;i--)
       {
            stx[i][0]=a[i];
            for(int j=1;j<LOGMAXN;j++)
                stx[i][j]=max(stx[i][j-1],stx[min(i+(1<<(j-1)),n-1)][j-1]);       
       } 
    }
}
 
ll query(int i, int j, bool mn)
{
    if(mn)
    {
        int m=j-i+1;
        if(m==1)return b[i];
        m=(31-__builtin_clz(m));
        return min(stn[i][m],stn[j-(1<<m)+1][m]);
    }
    else
    {
        int m=j-i+1;
        if(m==1)return a[i];
        m=(31-__builtin_clz(m));
        return max(stx[i][m],stx[j-(1<<m)+1][m]);
    }
}

bool can(int i, int mid)
{
    int lb = query(i, mid, false);
    int rb = query(i, mid, true);
    return rb-lb+1 >= mid-i+1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> a[i] >> b[i];
    }
    prep(false);
    prep(true);
    int ans = 1;
    FOR(i, 0, n)
    {
        int l = i;
        int h = n-1;
        while(h-l > 1)
        {
            int mid = l + (h-l)/2;
            if(can(i, mid))
                l = mid;
            else
               	h = mid-1;
        }
        if(can(i, h))
        {
            int lb = query(i, h, false);
            int rb = query(i, h, true);
            ans = max(ans, min(h-i+1, rb-lb+1));
        }
        else
        {
            int lb = query(i, l, false);
            int rb = query(i, l, true);
            ans = max(ans, min(l-i+1, rb-lb+1));
        }
    }
    printf("%d\n", ans);
    return 0;
}
