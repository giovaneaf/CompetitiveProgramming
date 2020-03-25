#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define ull unsigned long long int

int l, n, c;

int C[MAXN];

void print(set<tuple<int, int, int>>::iterator& it)
{
  printf("%d %d %d\n", get<0>(*it), get<1>(*it), get<2>(*it));
}

int main() 
{
  scanf("%d %d %d", &l, &c, &n);
  set<tuple<int, int, int>> s;
  s.insert(make_tuple(0, l-1, 1));
  C[1] = l;
  for(int i =  0; i < n; ++i)
  {
    int p, x, a, b;
    scanf("%d %d %d %d", &p, &x, &a, &b);
    int m1 = (a + (ull) C[p]*C[p])%((ull) l);
    int m2 =(a + (ull) (C[p]+b)*(C[p]+b))%((ull) l);
    if(m1 > m2) swap(m1, m2);
    vector<tuple<int, int, int>> del;
    vector<tuple<int, int, int>> add;
    set<tuple<int, int, int>>::iterator it;
    it = lower_bound(s.begin(), s.end(), make_tuple(m1+1, 0, 0));
    it--;
    while(true)
    {
      if(it == s.end()) break;
      if(get<0>(*it) > m2) break;
      tuple<int, int, int> t = *it;
      //print(it);
      C[get<2>(t)] -= get<1>(t) - get<0>(t) + 1;
      if(get<0>(t) < m1)
      {
        add.push_back(make_tuple(get<0>(t), m1-1, get<2>(t)));
        C[get<2>(t)] += m1-1 - get<0>(t) + 1;
      }
      if(get<1>(t) > m2)
      {
        add.push_back(make_tuple(m2+1, get<1>(t), get<2>(t)));
        C[get<2>(t)] += get<1>(t) - (m2 + 1) + 1;
      }
      del.push_back(t);
      it++;
    }
    for(int i = 0; i < del.size(); ++i)
      s.erase(del[i]);
    for(int i = 0; i < add.size(); ++i)
      s.insert(add[i]);
    s.insert(make_tuple(m1, m2, x));
    C[x] += m2 - m1 + 1;
  }
  int ans = 0;
  for(int i = 1; i <= c; ++i)
  {
    ans = max(ans, C[i]);
  }
  printf("%d\n", ans);
  return 0;
}