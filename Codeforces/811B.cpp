#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)

int n, m, sqrtn;

struct query
{
    int l, r, x, id;
    query(int l = 0, int r = 0, int x = 0, int id = 0) : l(l), r(r), x(x), id(id) {}
    bool operator< (const query& q) const
    {
        int b1 = l/sqrtn;
        int b2 = q.l/sqrtn;
        if(b1 < b2) return true;
        if(b1 == b2 && r < q.r) return true;
        if(b1 == b2 && r == q.r) return l < q.l;
        return false;
    }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        sqrtn = (int) sqrt(n);
        int v[n];
        FOR(i, 0, n) cin >> v[i];
        vector<query> q(m);
        FOR(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            q[i] = query(a, b, c, i);
        }
        sort(q.begin(), q.end());
        set<ii> s;
        int ql, qr;
        ql = qr = q[0].l;
		s.insert(mp(v[ql], ql));
        bool ans[m];
        FOR(i, 0, m)
        {
            int l = q[i].l;
            int r = q[i].r;
            while(qr < r)
            {
                qr++;
                s.insert(mp(v[qr], qr));
            }
            while(ql > l)
            {
                ql--;
                s.insert(mp(v[ql], ql));
            }
            while(qr > r)
            {
                s.erase(mp(v[qr], qr));
                qr--;
            }
            while(ql < l)
            {
                s.erase(mp(v[ql], ql));
                ql++;
            }
            int t = q[i].x;
            int pos = l + distance(s.begin(), s.find(mp(v[t], t)));
            ans[q[i].id] = (pos == t);
        }
        FOR(i, 0, m) printf("%s\n", ans[i] ? "Yes" : "No");
    }
	return 0;
}