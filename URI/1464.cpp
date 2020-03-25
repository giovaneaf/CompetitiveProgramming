#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Point Point;

struct Point
{
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	bool operator<(const Point& p) const
	{
		return y < p.y or (y == p.y and x < p.x);
	}
	bool operator==(const Point& p) const
	{
		return ((x - p.x) == 0 and (y - p.y) == 0);
	}
	int x, y;
};

int cross(const Point& p, const Point& q, const Point& r)
{
	return (q.x - p.x)*(r.y - p.y) - (q.y - p.y)*(r.x - p.x);
}

vector<Point> convex_hull(vector<Point>& P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	
	sort(P.begin(), P.end());
	
	for(int i = 0; i < n; i++)
	{
		while(k >= 2 and cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	
	for(int i = n-2, t = k+1; i >= 0; i--)
	{
		while(k >=t and cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	
	H.resize(k);
	return H;
	
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF && N)
	{
		vector<Point> v(N);
		for(int i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			v[i] = Point(x, y);
		}
		int layers = 0;
		while(v.size() > 2)
		{
			layers++;
			vector<Point> ch = convex_hull(v);
			for(int i = 0; i < ch.size(); i++)
			{
				for(int j = 0; j < v.size(); j++)
				{
					if(ch[i] == v[j])
					{
						v.erase(v.begin()+j);
						break;
					}
				}
			}
		}
		printf("%s\n", (layers%2 == 0 ? "Do not take this onion to the lab!" : "Take this onion to the lab!"));
		
	}
	return 0;
}