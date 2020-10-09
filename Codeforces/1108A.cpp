#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int a1 = a;
		int a2 = c;
		if(c == a) a2 = d;
		cout << a1 << ' ' << a2 << '\n';
	}
	return 0;
}