#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> even;
    vector<int> odd;
    for(int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        if(num&1) odd.push_back(num);
        else even.push_back(num);
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end());
    for(int i = 0; i < even.size(); ++i) {
        printf("%d\n", even[i]);
    }
    for(int i = 0; i < odd.size(); ++i) {
        printf("%d\n", odd[i]);
    }
    return 0;
}