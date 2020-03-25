#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int CeilIndex(std::vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
} 
  
int LIS(std::vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1;
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		printf("%d\n", LIS(v));
	}
	return 0;
}