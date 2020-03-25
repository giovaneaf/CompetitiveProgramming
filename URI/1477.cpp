#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

#define mt make_tuple

int lazy[4*MAXN];
int st[3][4*MAXN];

void init(int cur, int l, int r)
{
	if(l > r)
		return ;
	lazy[cur] = 0;
    if(l == r)
    {
        st[0][cur] = 1;
        st[1][cur] = st[2][cur] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    int left = 2*cur + 1;
    int right = 2*cur + 2;
    init(left, l, mid);
    init(right, mid+1, r);
    st[0][cur] = st[0][left] + st[0][right];
    st[1][cur] = st[2][cur] = 0;
}

void query(int cur, int l, int r, int ql, int qr, int* ans)
{
	if(lazy[cur]%3 > 0)
    {
        lazy[cur] = lazy[cur]%3;
        if(lazy[cur] == 1)
        {
            swap(st[0][cur], st[1][cur]);
            swap(st[0][cur], st[2][cur]);
        }
        else
        {
            swap(st[0][cur], st[2][cur]);
            swap(st[0][cur], st[1][cur]);
        }
        if(l != r)
		{
            	lazy[2*cur+1] += lazy[cur];
				lazy[2*cur+2] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(ql > r or qr < l)
        return ;
    if(l >= ql and r <= qr)
	{
		for(int i = 0; i < 3; ++i)
		{
			ans[i] += st[i][cur];
		}
		return ;
	}
    int mid = (l + r) >> 1;
    int left = 2*cur + 1;
    int right = 2*cur + 2;
    query(left, l, mid, ql, qr, ans);
    query(right, mid+1, r, ql, qr, ans);
    for(int i = 0; i < 3; ++i)
        st[i][cur] = st[i][left] + st[i][right];
}

void update(int cur, int l, int r, int ql, int qr)
{
	if(lazy[cur]%3 > 0)
    {
        lazy[cur] = lazy[cur]%3;
        if(lazy[cur] == 1)
        {
            swap(st[0][cur], st[1][cur]);
            swap(st[0][cur], st[2][cur]);
        }
        else
        {
            swap(st[0][cur], st[2][cur]);
            swap(st[0][cur], st[1][cur]);
        }
        if(l != r)
        {
            lazy[2*cur+1] += lazy[cur];
			lazy[2*cur+2] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(ql > r or qr < l)
        return ;
    if(l >= ql and r <= qr)
    {
		swap(st[0][cur], st[1][cur]);
        swap(st[0][cur], st[2][cur]);
		if(l != r)
		{
        	lazy[2*cur+1]++;
			lazy[2*cur+2]++;
		}
        return ;
    }
    int mid = (l + r) >> 1;
    int left = 2*cur + 1;
    int right = 2*cur + 2;
    update(left, l, mid, ql, qr);
    update(right, mid+1, r, ql, qr);
	for(int i = 0; i < 3; ++i)
        st[i][cur] = st[i][left] + st[i][right];
}


int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        init(0, 0, n-1);
        for(int i = 0; i < m; ++i)
        {
            char ch;
            int a, b;
            cin >> ch >> a >> b;
			--a, --b;
            if(ch == 'C')
            {
				int v[3] = {};
                query(0, 0, n-1, a, b, v);
                printf("%d %d %d\n", v[0], v[1], v[2]);
            }
            else
            {
                update(0, 0, n-1, a, b);
            }
        }
        putchar('\n');
    }
    return 0;
}