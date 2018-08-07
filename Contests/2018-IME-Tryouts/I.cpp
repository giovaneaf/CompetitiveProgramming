// Did an algorithm to check if the point is inside the polygon
// using all the rays that defines the polygon
// Time Complexity: O((s+r+m)*n) - for each ray check if a point is to the left or to the right of it
//								   you can choose left and right in any order since you be consistent
//								   with your choice

// Point inside polygon: https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Tvector
{
	ll x, y;
	Tvector(ll x, ll y) : x(x), y(y) {}
	Tvector operator- (Tvector& v)
	{
		return Tvector(x - v.x, y - v.y);
	}
	ll crossp(Tvector& v)
	{
		return x*v.y - y*v.x;
	}
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int size[3];
	while(cin >> size[0] >> size[1] >> size[2])
	{
		vector<Tvector> point[3];
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < size[i]; ++j)
			{
				ll x, y;
				cin >> x >> y;
				point[i].push_back(Tvector(x, y));
			}
		}
		int n;
		cin >> n;
		map<int, string> m;
		m[0] = "Sheena";
		m[1] = "Rose";
		m[2] = "Maria";
		while(n--)
		{
			ll x, y;
			cin >> x >> y;
			Tvector p = Tvector(x, y);
			bool outside = true;
			for(int i = 0; i < 3; ++i)
			{
				bool inside = true;
				for(int j = 0; j < size[i]; ++j)
				{
					int next = (j+1 == size[i] ? 0 : j+1);
					Tvector vec = point[i][next] - point[i][j];
					Tvector vec2 = p - point[i][j];
					ll cp = vec.crossp(vec2);
					if(cp < 0)
					{
						inside = false;
						break;
					}
				}
				if(inside)
				{
					cout << m[i] << "\n";
					outside = false;
					break;
				}
			}
			if(outside)
				cout << "Outside\n";
		}
	}
	return 0;
}