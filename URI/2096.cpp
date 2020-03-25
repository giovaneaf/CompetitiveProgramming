#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int spf[MAXN];
int kdp[MAXN];

void sieve()
{
	spf[1] = spf[0] = 1;
	for(int i = 2; i < MAXN; ++i)
		spf[i] = i;
	for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
	for(int i = 3; i*i < MAXN; i += 2)
	{
		if(spf[i] == i)
		{
			for (int j = i*i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
		}
	}
}

int primeSum(int x)
{
    if(x < 2) return 1;
	int ant = -1;
	int sum = 0;
	int cpy = x;
	while(x != 1)
	{
		if(ant != spf[x])
			sum += spf[x];
		ant = spf[x];
		x /= spf[x];
	}
	return sum;
}

int K(int x)
{
	if(x < 2)
		return 0;
	if(spf[x] == x)
		return kdp[x] = 1;
	if(kdp[x] == -1)
		return kdp[x] = 1 + K(primeSum(x));
	return kdp[x];
}

vector<int> ST[4*MAXN];

void myMerge(int cur, int l, int r)
{
	int i = 0;
	int j = 0;
	while(i < ST[l].size() && j < ST[r].size())
	{
		if(ST[l][i] < ST[r][j])
			ST[cur].push_back(ST[l][i++]);
		else
			ST[cur].push_back(ST[r][j++]);
	}
	while(i < ST[l].size())
		ST[cur].push_back(ST[l][i++]);
	while(j < ST[r].size())
		ST[cur].push_back(ST[r][j++]);
}

void init(int cur, int l, int r)
{
	if(l > r)
		return ;
	if(l == r)
	{
		ST[cur].push_back(kdp[l]);
		return ;
	}
	int mid = (l+r)/2;
	init(2*cur+1, l, mid);
	init(2*cur+2, mid+1, r);
	myMerge(cur, 2*cur+1, 2*cur+2);
}

int query(int cur, int l, int r, int ql, int qr, int k)
{
	if (ql > r or qr < l)
		return 0;
	if(l >= ql and r <= qr)
	{
		auto it1 = lower_bound(ST[cur].begin(), ST[cur].end(), k);
		auto it2 = upper_bound(ST[cur].begin(), ST[cur].end(), k);
		return distance(it1, it2);
	}
	int mid = (l+r)/2;
	return query(2*cur+1, l, mid, ql, qr, k) + query(2*cur+2, mid+1, r, ql, qr, k);
}


int main()
{
	sieve();
	for(int i = 0; i < MAXN; ++i)
	{
		kdp[i] = -1;
	}
	for(int i = 0; i < MAXN; ++i)
	{
		kdp[i] = K(i);
	}
	init(0, 0, MAXN-1);
	int P;
	scanf("%d", &P);
	while(P--)
	{
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		cout << query(0, 0, MAXN-1, l, r, k) << "\n";
	}
    return 0;
}
