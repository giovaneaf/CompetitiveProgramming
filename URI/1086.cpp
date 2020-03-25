#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, l, k;
	while(cin >> n >> m)
	{
		if(n == 0 and m == 0) break;
		int cn = n*100;
		int cm = m*100;
		cin >> l;
		cin >> k;
		vector<int> v;
		v.assign(10010, 0);
		for(int i = 0; i < k; ++i)
		{
			int num;
			cin >> num;
			v[num]++;
		}
		bool possible = false;
		int ans = 1e9;
		if(cn%l == 0 and cn/l <= k)
		{
			int target = cn/l;
			int tmp = 0;
			int cnt = 0;
			cnt = min(target, v[m]);
			tmp += cnt;
			int i = m-1;
			while(i > m/2 and cnt < target)
			{
				int used = min(v[i], v[m-i]);
				used = min(used, target - cnt);
				tmp += (used << 1);
				cnt += used;
				--i;
			}
			if(cnt < target && ((m&1) == 0))
			{
				int used = v[m/2]/2;
				used = min(used, target - cnt);
				tmp += (used << 1);
				cnt += used;
			}
			if(cnt == target)
			{
				ans = tmp;
				possible = true;
			}
		}
		if(cm%l == 0 and cm/l <= k)
		{
			int target = cm/l;
			int tmp = 0;
			int cnt = 0;
			cnt = min(target, v[n]);
			tmp += cnt;
			int i = n-1;
			while(i > n/2 && cnt < target)
			{
				int used = min(v[i], v[n-i]);
				used = min(used, target - cnt);
				tmp += (used << 1);
				cnt += used;
				--i;
			}
			if(cnt < target && ((n&1) == 0))
			{
				int used = v[n/2]/2;
				used = min(used, target - cnt);
				tmp += (used << 1);
				cnt += used;
			}
			if(cnt == target)
			{
				ans = min(ans, tmp);
				possible = true;
			}
		}
		if(possible)
			printf("%d\n", ans);
		else
			printf("impossivel\n");
	}
	return 0;
}