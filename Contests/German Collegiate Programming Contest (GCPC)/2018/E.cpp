/*
You need to check if a and b are primes in the irreducible fraction of a/b.
So you can multiply the real number by 100000, becareful of floating point representation (use round or read as integer)
then divide each number by the greatest common divisor (gcd) of the two input numbers then you have the irreducible 
fraction a/b.
Then you need to check if a and b are primes, you need to compute it fast because there are 10^5 queries. So you can't
check if each number is prime going until the square root of the number.
You can compute Sieve of Eratosthenes to compute all primes from 1 to n in O(n*log(log(n))).
Then just check in O(1) if a number is prime.
The tricky case is when a == b because a/(gcd(a, b)) = b/(gcd(a, b)) = 1, but you can represent this fraction as 2/2 and
two is prime. It's 2/2 because if there are multiple solutions then you are minimizing p+q.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 10000010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
bool prime[MAXN];
 
void Sieve()
{
    FOR(i, 2, MAXN) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < MAXN; ++i)
    {
        if(prime[i])
        {
            for(int j = i*i; j < MAXN; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    Sieve();
    int n;
    while(cin >> n)
    {
        double da, db;
        int a, b;
        FOR(i, 0, n)
        {
            cin >> da >> db;
            a = round(100000.0*da);
            b = round(100000.0*db);
            if(a == b)
            {
                printf("2 2\n");
                continue;
            }
            int gcd = __gcd(a, b);
            a /= gcd; b /= gcd;
            if(prime[a] && prime[b])
            {
                printf("%d %d\n", a, b);
            }
            else
            {
                printf("impossible\n");
            }
        }
    }
    return 0;
}