#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

#define EPS 1e-9

vector<pair<int, int>> v;
double memo[300][12][12];
vector<pair<int, int>> p(12);

pair<int, int> location(char ch)
{
	if(ch == ' ')
		return mp(0, 1);
	if(ch <= 'c')
		return mp(2, ch - 'a' + 1);
	if(ch <= 'f')
		return mp(3, ch - 'd' + 1);
	if(ch <= 'i')
		return mp(4, ch - 'g' + 1);
	if(ch <= 'l')
		return mp(5, ch - 'j' + 1);
	if(ch <= 'o')
		return mp(6, ch - 'm' + 1);
	if(ch <= 's')
		return mp(7, ch - 'p' + 1);
	if(ch <= 'v')
		return mp(8, ch - 't' + 1);
	return mp(9, ch - 'w' + 1);
}

double B(int cur, int l, int r)
{
	if(cur == v.size())
		return 0.0;
	if(memo[cur][l][r] > EPS) return memo[cur][l][r];
	double distL = sqrt((p[l].first - p[v[cur].first].first)*(p[l].first - p[v[cur].first].first) + (p[l].second - p[v[cur].first].second)*(p[l].second - p[v[cur].first].second));
	double distR = sqrt((p[r].first - p[v[cur].first].first)*(p[r].first - p[v[cur].first].first) + (p[r].second - p[v[cur].first].second)*(p[r].second - p[v[cur].first].second));
	return memo[cur][l][r] = min(distL/30.0 + v[cur].second*0.2 + B(cur + 1, v[cur].first, r), 
								 distR/30.0 + v[cur].second*0.2 + B(cur + 1, l, v[cur].first));
}

int main()
{
	string s;
	p[2] = mp(0, 1);
	p[3] = mp(0, 2);
	p[4] = mp(1, 0);
	p[5] = mp(1, 1);
	p[6] = mp(1, 2);
	p[7] = mp(2, 0);
	p[8] = mp(2, 1);
	p[9] = mp(2, 2);
	p[0] = mp(3, 1);
	p[10] = mp(3, 2);
	while(getline(cin, s))
	{
	    v.clear();
		for(int i = 0; i < 2*s.size(); ++i)
		{
			for(int j = 0; j < 12; ++j)
			{
				for(int k = 0; k < 12; ++k)
				{
					memo[i][j][k] = 0.0;
				}
			}
		}
		v.push_back(location(s[0]));
		for(int i = 1; i < s.size(); ++i)
		{
			pair<int, int> loc = location(s[i]);
			if(v[v.size()-1].first == loc.first)
				v.push_back(mp(10, 1));
			v.push_back(loc);
		}
		printf("%.2f\n", B(0, 4, 6));
	}
	return 0;
}