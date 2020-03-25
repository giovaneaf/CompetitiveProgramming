#include <iostream>
using namespace std;

int main()
{
    int L, N;
    cin >> L >> N;
    unsigned long long int ans = (L-N+1);
    ans *= (L-N+1);
    ans += (N-1);
    cout << ans << endl;
    return 0;
}
