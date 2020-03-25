/*
    String searching in O(n+m)
    Implementation of KMP algorithm
*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

struct KMP
{
    string P;
    vi b;
    KMP(string& s) : P(s)   // build KMP
    {
        int n = P.size();
        b.assign(n, 0);
        int j = 0;
        for(int i = 1; i < n; ++i)
        {
            while(j > 0 && P[j] != P[i]) j = b[j-1];
            if(P[j] == P[i])
            {
                b[i] = j+1;
                j++;
            }
            else
            {
                b[i] = 0;
            }
        }
    }
    vi match(string& T)    // return all indexes that matches
    {
        int n = T.size();
        vi ans;
        int j = 0;
        for(int i = 1; i < n; ++i)
        {
            while(j > 0 && T[i] != P[j]) j = b[j-1];
            if(T[i] == P[j])
            {
                j++;
                if(j == (int) P.size())
                {
                    ans.emplace_back(i-j+1);
                    j = b[j-1];
                }
            }
        }
        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s("abca");
    KMP kmp(s);                             // build pattern
    for(int i = 0; i < (int) s.size(); ++i)
    {
        printf("%d ", kmp.b[i]);            // print auxiliary array
    }
    putchar('\n');
    string T("abcxabcabca");                // search text
    vi match = kmp.match(T);                // get all matches
    for(int i = 0; i < (int) match.size(); ++i)
    {
        printf("%d ", match[i]);
    }
    putchar('\n');
    return 0;
} 