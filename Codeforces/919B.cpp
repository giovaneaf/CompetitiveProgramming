#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 19; ; ++i) {
        int aux = i;
        int sum = 0;
        while(aux > 0) {
            sum += aux%10;
            aux /= 10;
        }
        if(sum == 10) {
            if(--k == 0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}