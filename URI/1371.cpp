#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n) {
        printf("1");
        for(int i = 2; i*i <= n; ++i) {
            printf(" %d", i*i);
        }
        putchar('\n');
        scanf("%d", &n);
    }
}