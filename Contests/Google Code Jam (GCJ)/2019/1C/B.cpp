#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T, F;

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T >> F;
	vi freq(5);
	char res;
	int pos, cnt, lfreq;
	FOR(t, 1, T+1)
	{
		string ans;
		vb used(5, false);
		list<int> sets;
		FOR(i, 0, 119)
		{
			sets.push_back(i);
		}
		pos = 1;
		while(pos <= 4)
		{
			fill(freq.begin(), freq.end(), 0);
			vii v((int) sets.size());
			cnt = 0;
			for(int& s : sets)
			{
				printf("%d\n", pos+5*s);
				fflush(stdout);
				cin >> res;
				freq[res-'A']++;
				v[cnt++] = {res-'A', s};
			}
			lfreq = -1;
			FOR(i, 0, 5)
			{
				if(used[i]) continue;
				if(lfreq == -1 || freq[lfreq] > freq[i])
				{
					lfreq = i;
				}
			}
			ans += (lfreq+'A');
			used[lfreq] = true;
			sets.clear();
			FOR(i, 0, cnt)
			{
				if(v[i].fst == lfreq)
				{
					sets.push_back(v[i].snd);
				}
			}
			pos++;
		}
		FOR(i, 0, 5)
		{
			if(!used[i])
			{
				ans += (i+'A');
				break;
			}
		}
		printf("%s\n", ans.c_str());
		fflush(stdout);
		cin >> res;
		if(res == 'N') break;
	}
	return 0;
}

