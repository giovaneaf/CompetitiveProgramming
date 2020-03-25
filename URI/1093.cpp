#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vii vector<ii>

int ev1, ev2, at, d, st;

double M[445][445];
double ans[445][445];

inline void ones(double y[445][445])
{
	for(int i = 0; i < st; i++)
		for(int j = 0; j < st; j++)
			y[i][j] = (i == j ? 1 : 0);
}

void mul(int a)
{
	double tmp[445][445];
	for(int i = 0; i < st; i++)
		for(int j = 0; j < st; j++)
			tmp[i][j] = 0.0;
	if(a == 0)
	{
		for(int i = 0; i < st; i++)
		{
			for(int j = 0; j < st; j++)
			{
				for(int k = 0; k < st; k++)
				{
					tmp[i][j] += (M[i][k]*M[k][j]);
				}
			}
		}
		for(int i = 0; i < st; i++)
			for(int j = 0; j < st; j++)
				M[i][j] = tmp[i][j];
	}
	else
	{
		for(int i = 0; i < st; i++)
		{
			for(int j = 0; j < st; j++)
			{
				for(int k = 0; k < st; k++)
				{
					tmp[i][j] += (ans[i][k]*M[k][j]);
				}
			}
		}
		for(int i = 0; i < st; i++)
			for(int j = 0; j < st; j++)
				ans[i][j] = tmp[i][j];
	}
}

void expbysquaring(int L)
{
	ones(ans);
	while(L > 0)
	{
		if(L & 1)
			mul(1);
		L >>= 1;
		mul(0);
	}
}

int main()
{
	while(cin >> ev1 >> ev2 >> at >> d)
	{
		if(ev1 == 0) break;
		memset(M, 0, sizeof(M));
		map<ii, int> index;
		st = 0;
		queue<ii> q;
		q.push({ev1, ev2});
		index[q.front()] = st++;
		double proba = (double) at/6;
		double probb = 1 - proba;
		int indexans;
		while(q.size())
		{
			ii cur = q.front();
			q.pop();
			ii nst1, nst2;
			nst1 = {cur.first+d, max(0, cur.second-d)};
			nst2 = {max(0, cur.first-d), cur.second+d};
			if(cur.first > 0 && cur.second > 0)
			{
				if(index.find(nst1) == index.end())
				{
					index[nst1] = st++;
					if(nst1.second <= 0) indexans = st-1;
					q.push(nst1);
				}
				if(index.find(nst2) == index.end())
				{
					index[nst2] = st++;
					if(cur.first > 0 && cur.second > 0) q.push(nst2);
				}
				M[index[cur]][index[nst1]] = proba;
				M[index[cur]][index[nst2]] = probb;
			}
			else
			{
				M[index[cur]][index[cur]] = 1.0;
			}
		}
		expbysquaring(1000);
		printf("%.1f\n", ans[0][indexans]*100.0);
	}
}