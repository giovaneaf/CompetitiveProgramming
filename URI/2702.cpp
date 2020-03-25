#include <iostream>
 
using namespace std;
 
int main() {
 
    int a, b, c;
    int aa, bb, cc;
    cin >> a >> b >> c;
    cin >> aa >> bb >> cc;
    int ans = 0;
    if(aa > a)
        ans += aa-a;
    if(bb > b)
        ans += bb-b;
    if(cc > c)
        ans += cc-c;
    cout << ans << endl;
    return 0;
}