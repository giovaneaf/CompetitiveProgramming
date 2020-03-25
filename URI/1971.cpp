#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-8

typedef struct Point Point;

struct Point {
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  void print() {
      printf("%d %d\n", this->x, this->y);
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

void running() {
  printf(" O>\n<| \n/ >\n");
}

void surrender() {
  printf("\\O/\n | \n/ \\\n");
}

int main() {
  int n = 4;
  vector<Point> point(4);
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
  if(m < 3) {
    running();
    return 0;
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
  if(s.size() < 3) {
    running();
    return 0;
  }
  Point student;
  scanf("%d %d", &student.x, &student.y);
  int size = 0;
  while(s.size()) {
    point[size] = s.top();
    s.pop();
    size++;
  }
  int times = 0;
  bool inside = false;
  for(int i = 0; i < size; ++i) {
    int next = ((i == size-1) ? 0 : i+1);
    int rightMost, leftMost;
    if(point[i].x > point[next].x) {
      rightMost = i;
      leftMost = next;
    } else {
      rightMost = next;
      leftMost = i;
    }
    double a, b;
    a = ((double) (point[rightMost].y-point[leftMost].y))/ (point[rightMost].x - point[leftMost].x);
    b = point[rightMost].y - a*point[rightMost].x;
    if(fabs(a) < EPS) {
      if(point[leftMost].x <= student.x and student.x <= point[rightMost].x) {
        inside = true;
        break;
      }
    } else {
        double xPoint = ((double) (student.y - b))/a;
        if(xPoint < student.x)
            continue;
        if(fabs(a*student.x + b - student.y) < EPS) {
          inside = true;
          break;
        }
        if((point[leftMost].x <= xPoint and xPoint <= point[rightMost].x) 
            or fabs(point[leftMost].x - xPoint) < EPS 
            or fabs(point[rightMost].x - xPoint) < EPS)
        {
            times++;
        }
    }
  }
  if(inside or times == 1) {
    surrender();
  } else {
    running();
  }
}