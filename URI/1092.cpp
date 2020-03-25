#include <bits/stdc++.h>

#define INF 1e9
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
int M[610][610];

int maxHistogramArea(vector<int>& h, int row, int l, int r, vector<vii>& blocked, vector<int>& size, int sz);

int n, m, maxArea;

int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 and m == 0) break;
		getchar();
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &M[i][j]);
			}
		}
		maxArea = 1;
		vector<int> toCompute(m);
		vector<int> histogram(m);
		vector<vii> blocked(m);
		vector<int> size;
		size.assign(m, 0);
		for(int i = 0; i < m; ++i)
			blocked[i].resize(m);
		histogram[0] = 1;
		int tmp = 1;
		int bp = 0;
		int sz;
		for(int j = 1; j < m; ++j)
		{
			tmp++;
			histogram[j] = 1;
			if(M[0][j] <= M[0][j-1])
			{
				tmp = 1;
				blocked[j-1][size[j-1]++] = {j, 0};
				bp = j;
			}
			maxArea = max(maxArea, tmp);
		}
		
		for(int i = 1; i < n; ++i)
		{
			int iminusone = i-1;
			if(M[i][0] > M[iminusone][0])
				histogram[0]++;
			else
				histogram[0] = 1;

			int bp = 0;
			int pbp = 0;
			int sz = 1;
			toCompute[0] = histogram[0];
			for(int j = 1; j < m; ++j)
			{
				if((i+1)*(j-bp) > maxArea)
					maxArea = max(maxArea, maxHistogramArea(toCompute, i, bp, j-1, blocked, size, sz));
				if(M[i][j] > M[iminusone][j])
					histogram[j]++;
				else
					histogram[j] = 1;
				if(M[i][j] <= M[i][j-1])
				{
					sz = 0;
					if(size[j-1])
					{
						auto it = lower_bound(blocked[j-1].begin(), blocked[j-1].begin() + size[j-1], mp(j, 0));
						size[j-1] = (int) (it - blocked[j-1].begin());
					}
					blocked[j-1][size[j-1]++] = {j, i};
					bp = j;
					pbp = j;
				}
				else if(M[i][pbp] <= M[iminusone][j])
				{
					if(size[pbp] > 0)
					{
						auto it = lower_bound(blocked[pbp].begin(), blocked[pbp].begin() + size[pbp], mp(j, 0));
						size[pbp] = (int) (it - blocked[pbp].begin());
					}
					blocked[pbp][size[pbp]] = {j, iminusone};
					size[pbp++]++;
					while(pbp < j and M[i][pbp] <= M[iminusone][j])
					{
						if(size[pbp] > 0)
						{
							auto it = lower_bound(blocked[pbp].begin(), blocked[pbp].begin() + size[pbp], mp(j, 0));
							size[pbp] = (int) (it - blocked[pbp].begin());
						}
						blocked[pbp][size[pbp]] = {j, iminusone};
						size[pbp++]++;
					}
				}
				toCompute[sz++] = histogram[j];
			}
			maxArea = max(maxArea, maxHistogramArea(toCompute, i, bp, m, blocked, size, sz));
			sz = 0;
		}
		printf("%d\n", maxArea);
	}
	return 0;
}

int maxHistogramArea(vector<int>& h, int row, int l, int r, vector<vii>& blocked, vector<int>& size, int sz)
{
	int mx = 1;
	int mn = l;
	for(int i = 0; i < sz; ++i)
	{
		if(size[i+l] > 0)
		{
			auto it = upper_bound(blocked[i+l].begin(), blocked[i+l].begin() + size[i+l], mp(r, m));
			if(it != blocked[i+l].begin())
				h[i] = min(h[i], row - ((--it)->nd));
		}
		mx = max(mx, h[i]);
		if(h[mn] > h[i])
			mn = i;
	}
	if(mx*(r-l+1) < maxArea) return 0;
	if(max((r-l+1)*h[mn], max((mn - l)*mx, (r-mn)*mx)) < maxArea) return 0;
	int maxArea = 0;
	stack<int> s;
	int i = 0;
	while(i < sz)
	{
		if(s.empty() or h[s.top()] <= h[i])
			s.push(i++);
		else
		{
			int tp = s.top();
			s.pop();
			maxArea = max(maxArea, h[tp]*(s.empty() ? i : i - s.top() - 1));
		}
	}
	while(s.size())
	{
		int tp = s.top();
		s.pop();
		maxArea = max(maxArea, h[tp]*(s.empty() ? i : i - s.top() - 1));
	}
	return maxArea;
}