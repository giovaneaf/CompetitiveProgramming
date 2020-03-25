#include <bits/stdc++.h>

using namespace std;

struct plane
{
	int A, B, C, D;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(cin >> n >> m)
	{
		vector<plane> p(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> p[i].A >> p[i].B >> p[i].C >> p[i].D;
		}
		unordered_map<string, int> mp;
		for(int i = 0; i < m; ++i)
		{
			int X, Y, Z;
			cin >> X >> Y >> Z;
			string code;
			for(int j = 0; j < n; ++j)
			{
				if(((p[j].A*X) + (p[j].B*Y) + (p[j].C*Z)) > p[j].D)
					code += '1';
				else
					code += '0';
			}
			auto it = mp.find(code);
			if(it != mp.end())
			{
				it->second++;
			}
			else
			{
				mp[code] = 1;
			}
		}
		int mx = 0;
		for(auto it = mp.begin(); it != mp.end(); ++it)
		{
			if(it->second > mx)
				mx = it->second;
		}
		cout << mx << "\n";
	}
	return 0;
}