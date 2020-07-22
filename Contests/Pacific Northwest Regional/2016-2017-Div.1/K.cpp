#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
 
int k, r;
ld logfact[(1 << 20)+1];
 
void pre()
{
	logfact[0] = 0;
	for(int i = 1; i <= (1 << 20); ++i)
	{
		logfact[i] = logfact[i-1] + log(i);
	}
}
 
int main()
{
	pre();
	while(scanf("%d %d", &k, &r) != EOF)
	{
	    ld ans = 0.0L;
	    int l = (1 << k)-r;
	    for(int i = 1; (1 << i)-1 <= l; ++i)
	    {
	        ans += exp(logfact[l] - logfact[l-((1 << i) - 1)] + (logfact[(1 << k) - (1 << i)] - logfact[(1 << k) - 1]));
	    }
		printf("%.5Lf\n", ans);
	}
	return 0;
}
close