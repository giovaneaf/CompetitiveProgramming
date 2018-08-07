// Sparse table for O(1) query RMQ and binary search on leftmost affordable item
// O(max(building sparse table, querying costumers))
// Time Complexity: O(max(n*log(n), q*log(v)*log(l-r)))

// Sparse Table here: https://www.geeksforgeeks.org/sparse-table/
// Binary Search here: https://www.geeksforgeeks.org/binary-search/

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
				if(a[low] <= ans)
				{
					ans %= a[low];
				}
				else
				{
					ans %= a[high];
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}