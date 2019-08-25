/*
In this problem you can use physics to compute the correct angle to launch the robot
Assuming that the robot has a initial velocity (v0) we can use the velocity in x (vx) is given by equation 
vx(t) = v0*cos(theta) taking the integral in respect to t you get x(t) = v0*cos(theta)*t so, 
isolating t when x(t) = X: t = X/(v0*cos(theta)) this is the time to get to point X.
Now you need theta to compute this time. you can compute sin(theta) using the velocity in y (vy)
vy(t) = v0*sin(theta) taking the integral in respect to t you get y(t) = v0*sin(theta)*t now we need to check 
how many in y we should move to get the position (X, 0), each sidewalk moves the robot by (ri - li)*vi/(v0*cos(theta))
given that the time to travel in x is equal to (distance)/(v0*cos(theta)), therefore you sum all contributions from
each sidewalk in y (don't include the dividend in the sum, we can simplify it before) and then we have a variable 
called sum/(v0*cos(theta)). 
Then you need that when y(t) = -sum/(v0*cos(theta)) when you reach the point X in x coordinate and get to the point (X, 0) 
because of the sidewalks. Therefore, using the y(t) equation:
-sum/(v0*cos(theta)) = v0*sin(theta)*t, but t is know because t = X/(v0*cos(theta)) is when we reach X in x, so:
-sum/(v0*cos(theta)) = v0*sin(theta)*(X/(v0*cos(theta))) so sin(theta) = -sum/(X*v0). You can compute cos(theta) with 
the given formula: 1 = cos^2(theta) + sin^2(theta). Then we know the time it takes to cross the path.
Another possible solution is to do binary search in the angle.
Here's the link to this topic:
https://en.wikipedia.org/wiki/Projectile_motion
*/

#include <bits/stdc++.h>
 
#define EPS 1e-9
 
using namespace std;
 
int main()
{
    int n, X;
    double v;
    while(cin >> n >> X >> v)
    {
        double sum = 0.0;
        while(n--)
        {
            int li, ri;
            double vi;
            cin >> li >> ri >> vi;
            sum += (ri-li)*vi;
        }
        double sint = -sum/(X*v);
        double cost = sqrt(1 - sint*sint);
        double curtime = X/(v*cost);
        double besttime = X/v;
        if(curtime < 2*besttime or (curtime - 2*besttime < EPS))
            printf("%.3f", curtime);
        else
            printf("Too hard");
        putchar('\n');
    }
    return 0;
}