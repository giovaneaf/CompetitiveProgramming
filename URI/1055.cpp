#include<bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());
    int j = n-1;
    int i = 1;
    int ans = 0;
    for(; j-i > 1; i++, j--)
    {
      ans += ((v[j] - v[i-1]) + (v[j] - v[i]));;
    }
    if(i == j)
      ans += (v[i] - v[0]);
    else
      ans += ((v[j] - v[i-1]) + max((v[i] - v[0]), (v[j] - v[i])));
    j = n-2;
    i = 0;
    int tmp = 0;
    for(; j-i > 1; i++, j--)
    {
      tmp += ((v[j+1] - v[i]) + (v[j] - v[i]));
    }
    if(i == j)
      tmp += (v[n-1] - v[i]);
    else
      tmp += ((v[j+1] - v[i]) + max((v[n-1] - v[j]), (v[j] - v[i])));
    ans = max(ans, tmp);
    cout << "Case " << t << ": ";
    cout << ans << endl;
  }
  return 0;
}