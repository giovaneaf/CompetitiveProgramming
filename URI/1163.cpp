#include <bits/stdc++.h>

using namespace std;

#define g 9.80665
#define PI 3.14159
#define EPS 10e-7

int main()
{
	double h;
	while(scanf("%lf", &h) != EOF)
	{
		int p1, p2;
		scanf("%d %d", &p1, &p2);
		int T;
		scanf("%d", &T);
		while(T--)
		{
			double angle, speed;
			scanf("%lf %lf", &angle, &speed);
			double t;
			angle = angle*PI/180.0f;
			double vy = speed*sin(angle);
			t = (vy + sqrt(vy*vy+2.0f*g*h))/g;
			double x = speed*cos(angle)*t;
			printf("%.5lf -> ", x);
			if((x > p1 and x < p2) or fabs(x-p1) < EPS or fabs(x-p2) < EPS)
			{
				printf("DUCK");
			}
			else
			{
				printf("NUCK");
			}
			putchar('\n');
		}
	}
	return 0;
}