#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
 
using namespace std;
 
typedef long long int ll;
 
typedef struct state st;
 
struct state
{
  int val;
  int qty;
  bool operator< (const state& s) const
  {
    return val < s.val;
  }
};
 
ll dp[100000];
 
ll Backtrack(int i, int N, vector<st>& v)
{
  if(i >= N)
    return 0;
  if(i == N-1)
    return ((ll) v[i].qty)*v[i].val;
  if(dp[i] != -1)
    return dp[i];
  if(v[i].val == v[i+1].val-1)
  {
    return dp[i] = max(Backtrack(i+1, N, v), ((ll)v[i].qty)*v[i].val + Backtrack(i+2, N, v));
  }
  else
    return dp[i] = ((ll)v[i].qty)*v[i].val + Backtrack(i+1, N, v);
}
 
int main()
{
  int N;
  scanf("%d", &N);
  vector<int> s(N);
  vector<st> v;
  for(int i = 0; i < N; i++)
  {
    scanf("%d", &s[i]);
  }
  sort(s.begin(), s.end());
  for(int i = 0; i < N-1; i++)
  {
    st ss;
    ss.qty = 1;
    bool hasEqual = false;
    while(i < N-1 && s[i] == s[i+1])
    {
      hasEqual = true;
      ss.qty++;
      i++;
    }
    if(hasEqual)
    {
      ss.val = s[i-1];
    }
    else
      ss.val = s[i];
    v.push_back(ss);
  }
  if(s[N-1] != s[N-2])
  {
    st ss = {s[N-1], 1};
    v.push_back(ss);
  }
  memset(dp, -1, sizeof(ll)*v.size());
  cout <<  Backtrack(0, v.size(), v) << endl;
  return 0;
}