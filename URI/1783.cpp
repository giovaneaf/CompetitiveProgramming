#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

#define EPS 1e-9

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int t = 0; t < T; t++)
  {
    double x1b, y1b, x2b, y2b, x1a, y1a, x2a, y2a;
    cin >> x1b >> y1b >> x1a >> y1a >> x2b >> y2b >> x2a >> y2a;
    double a = 2*(x2b-x1b);
    double b = 2*(y2b-y1b);
    double c = 2*(x2a-x1a);
    double d = 2*(y2a-y1a);
    double k1, k2, yc, xc;
    k1 = x2b*x2b - x1b*x1b + y2b*y2b - y1b*y1b;
    k2 = x2a*x2a - x1a*x1a + y2a*y2a - y1a*y1a;
    xc = (k1*d-b*k2)/(a*d-b*c);
    yc = (a*k2-k1*c)/(a*d-b*c);
    printf("Caso #%d: %.2f %.2f\n", t+1, fabs(xc) < EPS ? 0.00 : xc , fabs(yc) < EPS ? 0.00 : yc);
  }
  return 0;
}
