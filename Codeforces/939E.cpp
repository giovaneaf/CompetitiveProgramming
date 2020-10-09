#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int q;
  cin >> q;
  ll mx = 0;
  vector<ll> sum;
  for(int i = 0; i < q; ++i) {
    int type;
    cin >> type;
    if(type == 1) {
      cin >> mx;
      if(sum.size() == 0) sum.push_back(mx);
      else sum.push_back(mx + sum[sum.size()-1]);
    } else {
      int low = 0;
      int high = sum.size()-2;
      while(high > low) {
        int mid = (low+high)/2;
        int f = (sum[mid] + mx)/(mid+2);
        if((int) f < sum[mid+1]-sum[mid]) {
          high = mid;
        } else {
          low =  mid+1;
        }
      }
      printf("%.8f\n", (double) mx - (sum[low] + mx)/(double) (low+2));
    }
  }
}