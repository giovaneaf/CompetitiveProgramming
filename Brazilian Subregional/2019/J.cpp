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
#define MAXN 100010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int n, k;
int freq[15][15];
map<char, int> mm;

bool sendCard(int cur, int nxt, int& joker, bool& pass)
{
	bool passedJoker = false;
	if(cur == joker)
	{
		if(pass)
		{
			joker = nxt;
			pass = false;
			passedJoker = true;
		}
		else
		{
			pass = true;
		}
	}
	if(!passedJoker)
	{
		int cardToPass = -1;
		int curFreq = INF;
		FOR(j, 0, 15)
		{
			if(freq[cur][j] > 0 && freq[cur][j] < curFreq)
			{
				curFreq = freq[cur][j];
				cardToPass = j;
			}
		}
		freq[cur][cardToPass]--;
		freq[nxt][cardToPass]++;
	}
	if(cur != joker)
	{
		FOR(j, 0, 15)
		{
			if(freq[cur][j] == 4)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	mm['A'] = 0;
	mm['2'] = 1;
	mm['3'] = 2;
	mm['4'] = 3;
	mm['5'] = 4;
	mm['6'] = 5;
	mm['7'] = 6;
	mm['8'] = 7;
	mm['9'] = 8;
	mm['D'] = 9;
	mm['Q'] = 10;
	mm['J'] = 11;
	mm['K'] = 12;
	while(cin >> n >> k)
	{
		k--;
		FOR(i, 0, 15)
			FOR(j, 0, 15)
				freq[i][j] = 0;
		string s;
		int winner = -1;
		int joker = k;
		bool pass = false;
		FOR(i, 0, n)
		{
			cin >> s;
			FOR(j, 0, 4)
			{
				freq[i][mm[s[j]]]++;
			}
			if(winner == -1 && freq[i][mm[s[0]]] == 4 && i != joker)
			{
				winner = i+1;
			}
		}
		int cur = k;
		while(winner == -1)
		{
			int nxt = (cur+1+n)%n;
			bool win = sendCard(cur, nxt, joker, pass);
			if(win)
			{
				winner = cur+1;
				break;
			}
			cur = nxt;
		}
		printf("%d\n", winner);
	}
	return 0;
}