#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        double sunflowers, violets, roses;
        double halfPerimeter = (a+b+c)/2.0;
        double triangleArea = sqrt(halfPerimeter*(halfPerimeter-a)*(halfPerimeter-b)*(halfPerimeter-c));
        double smallRadius = triangleArea/halfPerimeter;
        double largeRadius = a*b*c/(4.0*triangleArea);
        roses = M_PI*smallRadius*smallRadius;
        violets = triangleArea - roses;
        sunflowers = M_PI*largeRadius*largeRadius - triangleArea;
        printf("%.4f %.4f %.4f\n", sunflowers, violets, roses);
    }
    return 0;
}