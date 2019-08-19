/*
http://codeforces.com/gym/101201
In this problem you need to find the leftmost affordable item many times due to the number of queries.
One way to do this is apply a binary search in x querying the minimum value between the interval [0, x]
and repeat it until the customer can't afford more items. The query for the minimum can be done with a segment
tree, but the log factor may result in TLE, it's better to use sparse table because there are no update and you can
query minimum value in interval with O(1).
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
 
int n, q;
 
ll a[MAXN];
ll st[MAXN][LOGMAXN];
 
void prep()
{
    for(int i=n-1;i>=0;i--)
	{
        st[i][0]=a[i];
        for(int j=1;j<LOGMAXN;j++)
            st[i][j]=min(st[i][j-1],st[min(i+(1<<(j-1)),n-1)][j-1]);       
    }
}
 
ll query(int i, int j)
{
    int m=j-i+1;
    if(m==1)return a[i];
    m=(31-__builtin_clz(m));
    return min(st[i][m],st[j-(1<<m)+1][m]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> q)
	{
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		prep();
		while(q--)
		{
			int l, r;
			ll v;
			cin >> v >> l >> r;
			l--, r--;
			ll ans = v;
			while(query(l, r) <= ans)
			{
				int low = l;
				int high = r;
				while(high - low > 1)
				{
					int mid = (high + low) >> 1;
					if(query(low, mid) <= ans)
					{
						high = mid;
					}
					else
					{
						low = mid+1;
					}
				}
				//cout << "number = ";
				if(a[low] <= ans)
				{
				    //cout << a[low] << "\n";
					ans %= a[low];
				}
				else
				{
				    //cout << a[high] << "\n";
					ans %= a[high];
				}
				//putchar('\n');
			}
			cout << ans << "\n";
		}
	}
	return 0;
}