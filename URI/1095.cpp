#include <bits/stdc++.h>

using namespace std;

int main() {
    int i = 1;
    for(int j = 60; j >= 0; j -= 5) {
        printf("I=%d J=%d\n", i, j);
        i += 3;
    }
    return 0;
}