/*
Convex Hull in O(n*log(n)) + point inside polygon in O(log n). The point inside the convex hull can be verified
only with the target triangle doing binary search. For example: with the points of convex hull stored in anti clockwise
order you can fix the first point and the two pointers: left (initially the last point) and the right (initially the 
second point) after that the mid value of the binary search can be updated checking the cross product.
*/

#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 1010
#define MOD 2147483647
#define INF 1e9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
struct Point
{
    ll x, y;
};
 
Point p0;
 
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
 
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
ll distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0LL) return 0;  // colinear
    return (val > 0LL)? 1: 2; // clock or counterclock wise
}
 
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
 
void convexHull(Point points[], int n, vector<Point>& p)
{
	
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   swap(points[0], points[min]);
 
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   int m = 1;
   for (int i=1; i<n; i++)
   {
	   
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++; 
   }
 
   if (m < 3) return;
 
 
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   for (int i = 3; i < m; i++)
   {
		while (orientation(nextToTop(S), S.top(), points[i]) != 2)
			S.pop();
		S.push(points[i]);
   }
   
   int sz = S.size()-1;
   p.resize(sz+1);
   while (!S.empty())
   {
		p[sz--] = S.top();
		S.pop();
   }
}
 
bool inTriangle(vector<Point>& p, Point& pt)
{
	bool inside = true;
	bool boundary = false;
	for(int i = 0; i < 3; ++i)
	{
		int next = i+1 == 3 ? 0 : i+1;
		int maxx, minx, maxy, miny;
		maxx = max(p[i].x, p[next].x);
		minx = min(p[i].x, p[next].x);
		maxy = max(p[i].y, p[next].y);
		miny = min(p[i].y, p[next].y);
		int o = orientation(p[i], p[next], pt);
		if(o == 1)
		{
			inside = false;
		}
		else if(o == 0 && minx <= pt.x && pt.x <= maxx && miny <= pt.y && pt.y <= maxy)
		{
			boundary = true;
			break;
		}
	}
	if(inside || boundary)
	{
		return true;
	}
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int L;
	while(cin >> L)
	{
		vector<Point> p;
		Point v[L];
		for(int i = 0; i < L; ++i)
		{
			cin >> v[i].x >> v[i].y;
		}
		convexHull(v, L, p);
		int n = p.size();
		int S;
		cin >> S;
		int ans = 0;
		while(S--)
		{
			Point pt;
			cin >> pt.x >> pt.y;
			int l = 1;
			int h = n-1;
			while(h - l > 1)
			{
				int mid = (h+l) >> 1;
				int o = orientation(p[0], p[mid], pt);
				if(o == 2)
					l = mid;
				else
					h = mid;
			}
			vector<Point> triangle;
			triangle.push_back(p[0]);
			triangle.push_back(p[l]);
			triangle.push_back(p[h]);
			if(inTriangle(triangle, pt)) ans++;
		}
		cout << ans << '\n';
	}
    return 0;
}
