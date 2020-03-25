#include <bits/stdc++.h>

using namespace std;

typedef struct Point Point;

struct Point {
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	void print() {
	  printf("%d %d\n", x, y);
	}
	int x, y;
};

Point p;

Point nextToTop(stack<Point>& s) {
  Point top = s.top();
  s.pop();
  Point ant = s.top();
  s.push(top);
  return ant;
}

int cross(const Point& p, const Point& q, const Point& r) {
	return (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
}

int sqrdist(const Point& p, const Point& r) {
	return (r.x-p.x)*(r.x-p.x) + (r.y-p.y)*(r.y-p.y);
}

bool compare(const Point& q, const Point& r) {
	int o = cross(p, q, r);
	if(o == 0) {
		return sqrdist(p, q) < sqrdist(p, r);
	} else {
		return o < 0;
	}
}

int main() {
  int n;
  scanf("%d", &n);
  while(n) {
  	vector<Point> point(n);
  	int x, y, fst;
  	fst = 0;
  	scanf("%d %d", &x, &y);
  	point[0] = Point(x, y);
    for(int i = 1; i < n; ++i) {
    	scanf("%d %d", &x, &y);
    	point[i] = Point(x, y);
    	if(y < point[fst].y or (y == point[fst].y and x < point[fst].x)) fst = i;
    }
    swap(point[0], point[fst]);
    p = point[0];
    sort(point.begin()+1, point.end(), compare);
    int m = 1;
    for(int i = 1; i < n; ++i) {
    	while(i < n-1 and cross(p, point[i], point[i+1]) == 0)
    		i++;
    	point[m++] = point[i];
    }
    stack<Point> s;
    s.push(point[0]);
   	s.push(point[1]);
   	s.push(point[2]);
   	for(int i = 3; i < m; ++i) {
   		while(cross(nextToTop(s), s.top(), point[i]) > 0)
   			s.pop();
   		s.push(point[i]);
   	}
   	Point ant = s.top();
   	s.pop();
   	double dist = sqrt(sqrdist(p, ant));
   	while(s.size()) {
   	  dist += sqrt(sqrdist(s.top(), ant));
   	  ant = s.top();
   	  s.pop();
   	}
   	printf("Tera que comprar uma fita de tamanho %.2f.\n", dist);
    scanf("%d", &n);
  }
}