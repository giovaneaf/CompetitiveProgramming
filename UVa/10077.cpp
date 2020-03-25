#include <bits/stdc++.h>

using namespace std;

struct st
{
    int a, b;
};

void tree(st val, st l, st r)
{
    st mid = {l.a + r.a, l.b + r.b};
    if(mid.a == val.a and mid.b == val.b) return ;
    double vmid = (double) mid.a/mid.b;
    double valmid = (double) val.a/val.b;
    if(valmid > vmid)
    {
        printf("R");
        tree(val, mid, r);
    }
    else
    {
        printf("L");
        tree(val, l, mid);
    }
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        if(m == 1 and n == 1) break;
        st a = {0, 1};
        st b = {1, 0};
        st val = {m, n};
        tree(val, a, b);
        cout << "\n";
    }
    return 0;
}