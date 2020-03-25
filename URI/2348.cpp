#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int values[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    sort(values, values+n);
    vector<int> point(n);
    int j = 0;
    for(int i = n-1; i >= 0; i -= 2)
    {
        point[j] = values[i];
        j++;
    }
    j = n - 1;
    for(int i = n-2; i >= 0; i -= 2)
    {
        point[j] = values[i];
        j--;
    }
    double gap = 2.0*M_PI/n;
    double angle = gap/2.0;
    double area = 0.0;
    for(int i = 0; i < n; ++i)
    {
        int nxt = (i + 1 >= n ? 0 : i+1);
        area += cos(angle)*point[i]*sin(angle+gap)*point[nxt] - cos(angle+gap)*point[nxt]*sin(angle)*point[i];
        angle += gap;
    }
    printf("%.3f\n", fabs(area)/2.0);
    return 0;
}
