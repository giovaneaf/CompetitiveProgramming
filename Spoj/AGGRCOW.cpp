/*
Binary search the answer, for each mid value (x) in binary search check if its is possible to put C cows
inside the stalls with spacing equal to x, needs to sort the stall by position.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int n, c;
vector<int> stall;
 
bool f(int x) {
  int ncows = 1, last = stall[0];
  for(int i  = 1; i < n; ++i) {
    if(stall[i] - last >= x) {
      if(++ncows == c) return true;
      last = stall[i];
    }
  }
  return false;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    stall.clear();
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n;  ++i) {
      int xi;
      scanf("%d", &xi);
      stall.push_back(xi);
    }
    sort(stall.begin(), stall.end());
    int start = 0, end = stall[n-1] - stall[0] + 1, mid;
    while(end - start > 1) {
      mid = (end+start)>>1;
      (f(mid) ? start : end) = mid;
    }
    printf("%d\n", start);
  }
  return 0;
} 