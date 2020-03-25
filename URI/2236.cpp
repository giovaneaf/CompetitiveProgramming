#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

int* v;
int val;
int* Mi;
bool* visited;
vector<vector<int>> ST(65536*2);

void DFS(int i)
{
    if(i < val)
        val = i;
    if(visited[i])
    {
        return ;
    }
    visited[i] = true;
    DFS(v[i]);
}

void buildST(int index, int l, int h)
{
    if(l == h)
    {
        ST[index].push_back(Mi[l]);
        return ;
    }
    int mid = (l + h)/2;
    buildST(2*index + 1, l, mid);
    buildST(2*index + 2, mid+1, h);
    
    int a = 0, b = 0;
    
    for(int i = 0; i < ST[2*index+1].size() + ST[2*index+2].size() && a < ST[2*index+1].size() && b < ST[2*index+2].size(); i++)
    {
        if(ST[2*index+1][a] < ST[2*index+2][b])
        {
            ST[index].push_back(ST[2*index+1][a]);
            a++;
        }
        else
        {
            ST[index].push_back(ST[2*index+2][b]);
            b++;
        }
    }
    
    while(a < ST[2*index+1].size())
    {
        ST[index].push_back(ST[2*index+1][a]);
        a++;
    }
    
    while(b < ST[2*index+2].size())
    {
        ST[index].push_back(ST[2*index+2][b]);
        b++;
    }
}

int search(int index, int l, int h, int lq, int hq, int X)
{
    if(l >= lq && h <= hq)
    {
        vector<int>::iterator high;
        high = upper_bound(ST[index].begin(), ST[index].end(), X);
        return (high - ST[index].begin());
    }
    if(l > hq || h < lq)
        return 0;
    int mid = (l + h)/2;
    return search(2*index+1, l, mid, lq, hq, X) + search(2*index+2, mid+1, h, lq, hq, X);
}

int bestX(int ql, int qh, int N)
{
    int l, h;
	l = 0;
	h = N-1;
	while(h - l > 1)
	{
		int mid = (l+h)/2;
		double ans = (double) search(0, 0, N-1, ql, qh, mid+1)/(qh-ql+1);
		if(ans - 0.5 > EPS) h = mid;
		else l = mid;
	}
	double low = (double) search(0, 0, N-1, ql, qh, l+1)/(qh-ql+1);
	double high = (double) search(0, 0, N-1, ql, qh, h+1)/(qh-ql+1);
	if(fabs(low+high-1.0) < EPS or fabs(low - 0.5) < fabs(high - 0.5) or fabs(low-high) < EPS)
	{
		int nl = 0, nh = l;
		while(nh - nl > 1)
		{
			int mid = (nl+nh)/2;
			double ans = (double) search(0, 0, N-1, ql, qh, mid+1)/(qh-ql+1);
			if(fabs(ans - low) < EPS) nh = mid;
			else nl = mid;
		}
		double nls = (double) search(0, 0, N-1, ql, qh, nl+1)/(qh-ql+1);
		if(fabs(nls - low) < EPS) return nl;
		else return nh;
	}
	return h;
}

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	v = (int*) malloc (sizeof(int)*(N+1));
	for(int i = 1; i < N+1; i++)
		scanf("%d", &v[i]);
	Mi = (int*) malloc (sizeof(int)*(N+1));
	visited = (bool*) malloc (sizeof(bool)*(N+1));
	for(int i = 1; i < N+1; i++)
		visited[i] = false;
	Mi[0] = 1;
	for(int i = 2; i < N+1; i++)
	{
		val = i;
		DFS(i);
		Mi[i-1] = val;
		for(int j = 1; j < N+1; j++)
			visited[j] = false;
	}
	free(v);
	free(visited);
    buildST(0, 0, N-1);
    for(int i = 0; i < Q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", bestX(a-1, b-1, N) + 1);
    }
}
