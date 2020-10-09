#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, k;
    while(scanf("%lld %lld", &n, &k) != EOF) {
        if (k > 70) {
            printf("No\n");
            continue;
        }
        set<int> s;
        for (int i = 1; i <= k; ++i)
            s.insert(n % i);
        if(s.size() == k) printf("Yes\n");
        else printf("No\n");
    }
}