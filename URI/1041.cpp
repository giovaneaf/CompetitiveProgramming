#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	double a, b;
	cin >> a >> b;
	if(a == 0.0 && b == 0.0)
		printf("Origem");
	else if(a == 0.0) printf("Eixo Y");
	else if(b == 0.0) printf("Eixo X");
	else if(a > 0.0 && b > 0.0) printf("Q1");
	else if(a > 0.0 && b < 0.0) printf("Q4");
	else if(a < 0.0 && b > 0.0) printf("Q2");
	else printf("Q3");
	putchar('\n');
	return 0;
}









