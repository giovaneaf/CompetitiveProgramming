#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> v(N);
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end(), greater<int>());
	int ans = K;
	int i = K;
	while(v[i-1] == v[i] && i < v.size())
	{
		ans++;
		i++;
	}
	printf("%d\n", ans);
	return 0;
}