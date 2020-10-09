#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(string& a) {
    ll cnt=0, ans=0;
    for(auto i:a) {
        if(i == 's') cnt++;
        else ans += cnt;
    }
    return ans;
}

bool cmp(string& a, string &b) {
    string s1 = a+b, s2 = b+a;
    return f(s1) > f(s2);
}

int main(){
    int n;
    cin >> n;
    vector<string> v;
    string a, ans;
    while(n--) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto i : v) ans += i;
    cout << f(ans) << endl;
}