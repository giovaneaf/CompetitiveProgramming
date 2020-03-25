#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while(cin >> n >> k)
	{
		if(n == 0 && k == 0) break;
		int A[n], B[n];
		FOR(i, 0, n) cin >> A[i] >> B[i];
		stack<int> s;
		bool GG = true;
		FOR(i, 0, n)
		{
			if(A[i] >= B[i]) continue;
			while(s.size() && s.top() <= A[i]) s.pop();
			if(s.size() == k || (s.size() && s.top() < B[i]))
			{
				GG = false;
				break;
			}
			s.push(B[i]);
		}
		while(s.size())
		{
			int a = s.top();
			s.pop();
			if(s.size() && s.top() < a)
			{
				GG = false;
				break;
			}
		}
		printf("%s\n", GG ? "Sim" : "Nao");
	}
	return 0;
}