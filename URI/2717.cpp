#include <iostream>
 
using namespace std;
 
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a+b <= n) printf("Farei hoje!");
        else printf("Deixa para amanha!");
        putchar('\n');
    }
    return 0;
}