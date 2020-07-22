/*
This is an ad hoc problem, you need to find the pattern.
There are some cases (testing in this order and they are mutually exclusive)
1 - If the size of the input string is 1 or there aren't vowels then the answer is one because
there are only one way to insert this string because the vowels give the more options.
2 - If the first character isn't vowel then the answer is 0 because the last vowel added should be
in the first character of the string.
3 - If the number of vowels is 1 then the answer is the size of the string because you can put the
vowel at any time and this should form the input string.
4 - If more than one vowel exists then this is tricky...
Let's suppose we have a string s = V1|C1|C2|V2|C3|C4|C5|V3|C6|C7, Vx is a vowel and Cy is consonant.
Then the only way to construct this string is by adding V1 to the chain V3|C5|C4|C3|V2|C2|C1 and add C6|C7 to it
The only way to construct V3|C5|C4|C3|V2|C2|C1 is to add V3 to V2|C5|C4|C3 and add C2|C1 to it.
So you only have options to build the sequence V2|C5|C4|C3 which is the case 3 (there are size of sequence ways).
Note that you keep removing the vowels in the boundary and you'll keep with a vowel in the middle. So you need
to compute the number of consonants between vowels in the input string and the answer will be the middle element of
the vector + 1 (because you have one vowel associated with it).
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

inline bool isVowel(const char& c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	int n;
	while(cin >> s)
	{
		n = (int) s.size();
		int numVowels = 0;
		for(char c : s)
		{
			if(isVowel(c)) numVowels++;
		}
		if(n == 1 || numVowels == 0)
		{
			printf("1\n");
		}
		else if(!isVowel(s[0]))
		{
			printf("0\n");
		}
		else if(numVowels == 1)
		{
			printf("%d\n", n);
		}
		else
		{
			vector<int> ans;
			int lv = 0;
			int rv = 1;
			while(rv < n)
			{
				if(!isVowel(s[rv]))
				{
					rv++;
				}
				else
				{
					ans.emplace_back(rv-lv-1);
					lv = rv;
					rv = lv+1;
				}
			}
			printf("%d\n", ans[(int) ans.size()/2]+1);
		}
	}
	return 0;
}
