#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef struct
{
	double a, b;
} StrLine;

typedef struct
{
	double x, y;
} Point;

double dist(Point a, Point b)
{
	return sqrt( pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

int main()
{
	int N;
	while(cin >> N)
	{
		int L, H;
		cin >> L >> H;
		int i;
		StrLine s[N];
		Point p[N];
		for(i = 0; i < N; i++)
		{
			int Xi, Yi;
			cin >> Yi >> p[i].x >> p[i].y;
			if(i%2 == 0)
			{
				Xi = 0;
			}
			else
			{
				Xi = L;
			}
			s[i].a = (p[i].y-Yi)/(p[i].x-Xi);
			s[i].b = Yi - Xi*s[i].a;
		}
		double size = L;
		double distance;
		for(i = 0; i < N-1; i++)
		{
			StrLine aux;
			aux.a = (-1/s[i+1].a);
			aux.b = p[i].y - p[i].x*aux.a;
			Point c;
			c.x = (s[i+1].b-aux.b)/(aux.a-s[i+1].a);
			if((p[i+1].x < c.x && i%2 == 1) || (p[i+1].x > c.x && i%2 == 0))
				distance = dist(p[i], p[i+1]);
			else
				distance = fabs((-s[i+1].a)*p[i].x + p[i].y - s[i+1].b)/(sqrt(pow(s[i+1].a, 2.0) + 1.0));
			if(i%2 == 0)
			{
				distance = min(distance, L-p[i].x);
			}
			else
				distance = min(distance, p[i].x);
			if(size > distance)
				size = distance;
		}
		if((N-1)%2 == 0)
		{
			distance = L-p[N-1].x;
		}
		else
		{
			distance = p[N-1].x;
		}
		if(size > distance)
			size = distance;
		printf("%.2f\n", size);
	}
}