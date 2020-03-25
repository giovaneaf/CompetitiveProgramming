#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	stack<int> s;
	multiset<int> m;
	for(int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if(str == "PUSH")
		{
			int v;
			cin >> v;
			s.push(v);
			m.insert(v);
		}
		else if(str == "MIN")
		{
			if(s.empty())
			{
				printf("EMPTY\n");
			}
			else
			{
				printf("%d\n", *m.begin());
			}
		}
		else
		{
			if(s.empty())
			{
				printf("EMPTY\n");
			}
			else
			{
				int v = s.top();
				s.pop();
				m.erase(m.find(v));
			}
		}
	}
	return 0;
}