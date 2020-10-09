#include <bits/stdc++.h>

using namespace std;

int n;
int t[200010];
int last[200010];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	memset(last, -1, sizeof(last));
	last[0] = 0;
	int minRooms = 1;
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		int ti = t[i];
		if(last[ti] != -1)
		{
			index = last[ti];
			last[ti] = -1;
			last[i+1] = index;
		}
		else
		{
			minRooms++;
			index = minRooms;
			last[i+1] = index;
		}
	}
	cout << minRooms << endl;
	return 0;
}