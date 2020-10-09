#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
    while(cin >> str)
	{
		stack<int> s;
		int cnt = 0;
		for(int i = 0; i < str.size(); ++i)
		{
			if(s.empty() || s.top() != str[i]) 
				s.push(str[i]);
			else 
			{
				s.pop();
				cnt++;
			}
		}
		printf("%s\n", (cnt&1) ? "Yes" : "No");
	}
	return 0;
}