#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	int arr[n];
	int sum[n+1];
	sum[0] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum[i+1] = (arr[i] + sum[i]);
	}
	int ans = 360;
	for(int i = 0; i < n; i++)
	{
		int j = i;
		while(j < n+1 && sum[j] - sum[i] <= 180)
			j++;
		if(j < n+1)
			ans = min(abs(180 - (sum[j] - sum[i])), min(abs(180 - (sum[j-1] - sum[i])), ans));
		else
			ans = min(abs(180 - (sum[j-1] - sum[i])), ans);
	}
	cout << 2*ans << endl;
    return 0;
}