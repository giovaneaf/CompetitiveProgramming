/*
Simulate the robot and check you many times he passed by S.
*/

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int N,C,S,i,cur,program;
    int times;
    while(cin >> N >> C >> S)
	{
		times = 0;
		cur = 1;
		if (S == 1)
			times++;
		for (i = 0; i < C; i++)
		{
			cin >> program;
			if (program == 1)
			{
				if (cur == N)
					cur = 1;
				else
					cur++;
			}
			else
			{
				if (cur == 1)
					cur = N;
				else
					cur--;
			}
			if (cur == S)
				times++;
		}
		cout << times << endl;
	}
    return 0;
}
