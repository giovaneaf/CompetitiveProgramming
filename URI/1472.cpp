#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		vector<int> sum(N);
		int dist;
		cin >> dist;
		sum[0] = dist;
		int i;
		for(i = 1; i < N; i++)
		{
			cin >> dist;
			sum[i] = sum[i-1]+dist;
		}
		if(sum[N-1]%3 == 0)
		{
			int triangles = 0;
			int thirdPart = sum[N-1]/3;
			i = 0;
			int j, k;
			j = k = 0;
			while(thirdPart >= sum[i])
			{
				while(sum[j] < sum[i] + thirdPart) j++;
				while(sum[k] < sum[i] + 2*thirdPart) k++;
				if((sum[j] == sum[i] + thirdPart) && sum[k] == (sum[i] + 2*thirdPart))
					triangles++;
				i++;
			}
			cout << triangles;
		}
		else
		{
			cout << "0";
		}
		cout << endl;	
	}
	return 0;
}