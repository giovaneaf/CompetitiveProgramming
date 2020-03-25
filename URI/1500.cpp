#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;
typedef long long ll;

ll st[4*MAXN];
ll lazy[4*MAXN];

void init(int cur, int l, int r)
{
    if(l > r)
        return ;
    lazy[cur] = 0LL;
    if(l == r)
    {
        st[cur] = 0LL;
        return ;
    }
    int mid = (l + r) >> 1;
    int left = 2*cur+1;
    int right = 2*cur+2;
    init(left, l, mid);
    init(right, mid+1, r);
    st[cur] = 0LL;
}

ll query(int cur, int l, int r, int ql, int qr)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(lazy[cur] > 0)
    {
        st[cur] += ((long long) r-l+1)*lazy[cur];
        if(l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0LL;
    }
    if(ql > r || qr < l) return 0LL;
    if(l >= ql && r <= qr)
    {
        return st[cur];
    }
    int mid = (l + r) >> 1;
    ll a = query(left, l, mid, ql, qr);
    ll b = query(right, mid+1, r, ql, qr);
    st[cur] = st[right] + st[left];
    return a + b;
}

void update(int cur, int l, int r, int ql, int qr, int val)
{
    int left = 2*cur+1;
    int right = 2*cur+2;
    if(lazy[cur] > 0)
    {
        st[cur] += ((long long) r-l+1)*lazy[cur];
        if(l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0LL;
    }
    if(ql > r || qr < l) return ;
    if(l >= ql && r <= qr)
    {
        st[cur] += ((long long) r-l+1)*val;
        if(l != r)
        {
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(left, l, mid, ql, qr, val);
    update(right, mid+1, r, ql, qr, val);
    st[cur] = st[left] + st[right];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
	    int n, c;
	    scanf("%d %d", &n, &c);
        init(0, 0, n-1);
        for(int i = 0; i < c; ++i)
        {
            int t, a, b;
            scanf("%d %d %d", &t, &a, &b);
            a--, b--;
            if(t == 1)
            {
                printf("%lld\n", query(0, 0, n-1, a, b));
            }
            else
            {
                int val;
                scanf("%d", &val);
                update(0, 0, n-1, a, b, val);
            }
        }
	    
	}
    return 0;
}