#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second

struct plant
{
    int x, y;
    ll val;
    plant(int x = 0, int y = 0, ll val = 0LL) : x(x), y(y), val(val) {}
    bool operator< (const plant& p) const { return x < p.x; }
};

struct vLine /* vertical line */
{
    int x, ymin, ymax;
    vLine(int x = 0, int ymin = 0, int ymax = 0LL) : x(x), ymin(ymin), ymax(ymax) {}
    bool operator< (const vLine& p) const
    {
        return x < p.x;
    }
};

int P, V;
bool st[16*MAXN];
int lazy[16*MAXN];

inline int nxt(int idx)
{
    return idx + 1 == V ? 0 : idx+1;
};

inline int prev(int idx)
{
    return idx - 1 == -1 ? V-1 : idx-1;
};

void update(int cur, int l, int r, int ql, int qr, int x)
{
	if(l > r) return;
    int lc, rc;
    lc = 2*cur+1;
    rc = lc+1;
    if(lazy[cur] > -1)
    {
        st[cur] = lazy[cur];
        if(l != r)
        {
            lazy[lc] = lazy[cur];
            lazy[rc] = lazy[cur];
        }
        lazy[cur] = -1;
    }
    if(ql > r || qr < l) return ;
    if(ql <= l && r <= qr)
    {
        st[cur] = x;
        if(l != r)
        {
            lazy[lc] = st[cur];
            lazy[rc] = st[cur];
        }
        return ;
    }
    int mid = (l+r)/2;
    update(lc, l, mid, ql, qr, x);
    update(rc, mid+1, r, ql, qr, x);
}

bool query(int cur, int l, int r, int x)
{
    int lc, rc;
    lc = 2*cur+1;
    rc = lc+1;
    if(lazy[cur] > -1)
    {
        st[cur] = lazy[cur];
        if(l != r)
        {
            lazy[lc] = lazy[cur];
            lazy[rc] = lazy[cur];
        }
        lazy[cur] = -1;
    }
    if(l == r)
    {
        return st[cur];
    }
    int mid = (l+r)/2;
    if(x <= mid)
        return query(lc, l, mid, x);
    return query(rc, mid+1, r, x);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> P >> V)
    {
        map<int, int> mm;
        vector<ii> yValues(V+P);
        vector<plant> vplant(P);
        FOR(i, 0, P)
        {
            cin >> vplant[i].x >> vplant[i].y;
            vplant[i].val = i+1LL;
            yValues[i].fst = vplant[i].y;
			yValues[i].snd = 0;
        }
        sort(vplant.begin(), vplant.end());
        vector<plant> vpoly(V);
        FOR(i, 0, V)
        {
            cin >> vpoly[i].x >> vpoly[i].y;
        }
        if(V < 4)
        {
            printf("%lld\n", (((long long) (V+1))*V)/2LL);
            continue;
        }
        vector<vLine> v(V);
        int cnt = 0;
        FOR(i, 0, V)
        {
            yValues[i+P].fst = vpoly[i].y;
			yValues[i+P].snd = 1;
            int inxt = nxt(i);
            if(vpoly[inxt].x == vpoly[i].x)
            {
                v[cnt].x = vpoly[i].x;
                v[cnt].ymin = min(vpoly[inxt].y, vpoly[i].y);
                v[cnt].ymax = max(vpoly[inxt].y, vpoly[i].y);
                cnt++;
            }
        }
        v.resize(cnt);
        sort(v.begin(), v.end());
		/*for(auto& x : v)
		{
			printf("%d %d %d\n", x.x, x.ymin, x.ymax);
		}*/
        sort(yValues.begin(), yValues.end());
        int pos = 0;
        FOR(i, 0, V+P)
        {
            if(mm.find(yValues[i].fst) == mm.end())
            {
                mm[yValues[i].fst] = pos;
                pos++;
            }
			if(yValues[i].snd)
			{
				pos++;
			}
        }
        memset(st, 0, sizeof(st));
        memset(lazy, -1, sizeof(lazy));
        int idx = 0;
        ll ans = 0LL;
        FOR(i, 0, P)
        {
            while(idx < cnt && v[idx].x <= vplant[i].x)
            {
				//printf("updating %d %d %d %d\n", idx, mm[v[idx].ymin], mm[v[idx].ymax], query(0, 0, pos-1, mm[v[idx].ymin]+1) ? 0 : 1);
				update(0, 0, pos-1, mm[v[idx].ymin], mm[v[idx].ymax], query(0, 0, pos-1, mm[v[idx].ymin]+1) ? 0 : 1);
				idx++;
            }
            bool qans = query(0, 0, pos-1, mm[vplant[i].y]);
			//printf("querying (%d, %d) %d %d\n", vplant[i].x, vplant[i].y, mm[vplant[i].y], qans ? 1 : 0);
            if(!qans) ans += vplant[i].val;
        }
        printf("%lld\n", ans);
    }
    return 0;
}