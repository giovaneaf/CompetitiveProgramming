#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        string str;
        cin >> str;
        set<char> s;
        for(int i = 0; i < str.size(); ++i)
        {
            s.insert(str[i]);
        }
        if(k > n)
        {
            for(int i = n; i < k; ++i)
            {
                str += *(s.begin());
            }
            cout << str << endl;
        }
        else
        {
            string ans;
            bool smaller = false;
            for(int i = k-1; i >= 0; --i)
            {
                if(smaller)
                {
                    ans = str[i] + ans;
                }
                else
                {
                    auto it = s.upper_bound(str[i]);
                    if(it == s.end())
                    {
                        ans = *(s.begin()) + ans;
                    }
                    else
                    {
                        ans = *it + ans;
                        smaller = true;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
