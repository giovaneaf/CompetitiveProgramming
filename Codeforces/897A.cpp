#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	int n, m;
	cin >> n >> m;
	char s[110];
	cin >> s;
	for(int i = 0; i < m; i++)
	{
		int l, h;
		char c1, c2;
		cin >> l >> h >> c1 >> c2;
		l--, h--;
		for(int i = l; i <= h; i++)
		{
			if(s[i] == c1)
			{
				s[i] = c2;
			}
		}
	}
	cout << s << endl;
    return 0;
}