/*
Yes, you can compute the sum of all divisors from an interval [a, b] in O(sqrt(b)).
The main idea here is to sum two different parts, the number that are less than sqrt(b) and that are greater.
For each number (i > 0) that are less than sqrt(b) you can compute how many times it appears in range [0, x] by taking
the floor division of x/i because there are this number of multiples of i in this range and you need to multiply this 
number by i because you are computing the sum of divisors and not how many times it appears in the range.
So you can compute for the interval [a, b] just by computing f(b) - f(a-1) of this first part.
The numbers greater than sqrt(b) are tricky to compute:
You can compute it by using arithmetic progression formula of the interval [max(sqrt(b), (a-1)/i), max(sqrt(b), b/i)]
this is because you are computing all the complementary factors that are not added in this formula.
For example: when a = 5 and b = 13 then:
if i = 1 you compute the interval [5, 13] which are getting the factors 5, 6, 7, .. , 13.
if i = 2 you compute the interval [3, 6] because you are computing the complementary factors of the 
following even numbers: 6, 8, 10 and 12.
if i = 3 you compute the interval [3, 4] because there are only two numbers multiple of 3 inside the range (3*3 and 3*4)
Hope this helps a little bit!
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m;
ll a, b;
 
ll triangles(ll x, ll y)
{
	x++;
	if(x > y) return 0LL;
	return (x+y)*(y-x+1)/2LL;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> a >> b)
    {
		a--;
		ll sqr = sqrt(b);
		ll ans = 0LL;
		FOR(i, 1, sqr+1)
		{
			ans += i*(b/i - a/i) + triangles(max(sqr, a/i), max(sqr, b/i));
		}
		printf("%lld\n", ans);
    }
	return 0;
}