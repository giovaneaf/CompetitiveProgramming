#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define LOGMAXN 23
#define MAXM 1010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int n, m;

struct node 
{
	int val;
	bool belong[2];

	node* left, *right;

	node() {}
	node(node* l, node* r, int v)
	{
		left = l;
		right = r;
		val = v;
		belong[0] = belong[1] = true;
	}

};

node* st[2*MAXN];

void build(node* cur, int l, int r)
{
	if(l == r)
	{
		cur->val = 0;
		return;
	}
	int m = (l+r)/2;
	cur->left = new node(nullptr, nullptr, 0);
	cur->right = new node(nullptr, nullptr, 0);
	build(cur->left, l, m);
	build(cur->right, m+1, r);
	cur->val = cur->left->val + cur->right->val;
}

void update(node* prev, node* cur, int l, int r, int idx, int v)
{
	if(l == r)
	{
		cur->val = v;
		return;
	}
	int m = (l+r)/2;
	if(idx <= m)
	{
		cur->right = prev->right;
		cur->belong[1] = false;
		cur->left = new node(nullptr, nullptr, 0);

		update(prev->left, cur->left, l, m, idx, v);
	}
	else
	{
		cur->left = prev->left;
		cur->belong[0] = false;
		cur->right = new node(nullptr, nullptr, 0);

		update(prev->right, cur->right, m+1, r, idx, v);
	}
	cur->val = cur->left->val + cur->right->val;
}

int query(node* cur, int l, int r, int ql, int qr)
{
	if(r < ql || l > qr)
		return 0;
	if(ql <= l && r <= qr)
	{
		return cur->val;
	}
	int m = (l+r)/2;
	int v1 = query(cur->left, l, m, ql, qr);
	int v2 = query(cur->right, m+1, r, ql, qr);
	return v1+v2;
}

void deleteRec(node* cur, int l, int r)
{
	if(l == r)
	{
		delete cur;
		return;
	}
	int m = (l+r)/2;
	if(cur->belong[0])
		deleteRec(cur->left, l, m);
	if(cur->belong[1])
		deleteRec(cur->right, m+1, r);
	delete cur;
}

void destroy(int sz)
{
	FOR(i, 0, sz)
	{
		deleteRec(st[i], 0, n-1);
	}
}

int day[MAXN];
int dayToV[MAXN];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
	int v;
	while(cin >> n)
	{
		getline(cin, str);
		v = 0;
		st[v] = new node(nullptr, nullptr, 0);
		build(st[v], 0, n-1);
		v++;
		FOR(i, 0, n)
		{
			getline(cin, str);
			if((int) str.size() > 0)
			{
				stringstream ss(str);
				while(ss.good())
				{
					ss >> str;
					int value = (str[0] == '+' ? 1 : 0);
					int idx = stoi(str.substr(1));
					st[v] = new node(nullptr, nullptr, 0);
					update(st[v-1], st[v], 0, n-1, idx, value);
					v++;
				}
			}
			dayToV[i+1] = v-1;
		}
		FOR(i, 0, n)
		{
			cin >> day[i];
		}
		int x = 0;
		FOR(i, 0, n)
		{
			int qans = query(st[dayToV[day[i]]], 0, n-1, x, n-1);
			x = (x+qans)%n;
		}
		printf("%d\n", x);
		destroy(v);
	}
	return 0;
}