#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;
bool M[210][210];

void BToD(int lr, int lc, int ur, int uc, string& ans)
{
	bool a, b;
	a = false, b = false;
	FOR(i, lr, ur+1)
		FOR(j, lc, uc+1)
			if(M[i][j]) a = true;
			else b = true;
	if(a != b)
	{
		ans += (a ? '1' : '0');
		return ;
	}
	else
	{
		ans += 'D';
		int szr = ur-lr+1;
		int szc = uc-lc+1;
		int midr = (ur+lr)>>1;
		int midc = (uc+lc)>>1;
		if(szr > 1 && szc > 1)
		{
			BToD(lr, lc, midr, midc, ans);	
			BToD(lr, midc+1, midr, uc, ans);
			BToD(midr+1, lc, ur, midc, ans);
			BToD(midr+1, midc+1, ur, uc, ans);
		}
		else if(szr > 1)
		{
			BToD(lr, lc, midr, uc, ans);
			BToD(midr+1, lc, ur, uc, ans);
		}
		else if(szc > 1)
		{
			BToD(lr, lc, ur, midc, ans);
			BToD(lr, midc+1, ur, uc, ans);
		}
	}
}

int pos;

void DToB(int lr, int lc, int ur, int uc, string& s)
{
	//printf("%d %d %d %d %d\n", lr, lc, ur, uc, pos);
	if(s[pos] != 'D')
	{
		bool a = s[pos] == '1';
		FOR(i, lr, ur+1)
			FOR(j, lc, uc+1)
				M[i][j] = a;
		pos++;
		return ;
	}
	else
	{
		pos++;
		int szr = ur-lr+1;
		int szc = uc-lc+1;
		int midr = (ur+lr)>>1;
		int midc = (uc+lc)>>1;
		if(szr > 1 && szc > 1)
		{
			DToB(lr, lc, midr, midc, s);	
			DToB(lr, midc+1, midr, uc, s);
			DToB(midr+1, lc, ur, midc, s);
			DToB(midr+1, midc+1, ur, uc, s);
		}
		else if(szr > 1)
		{
			DToB(lr, lc, midr, uc, s);
			DToB(midr+1, lc, ur, uc, s);
		}
		else if(szc > 1)
		{
			DToB(lr, lc, ur, midc, s);
			DToB(lr, midc+1, ur, uc, s);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	string str;
	getline(cin, str);
	while(true)
	{
		//printf("%s\n", str.c_str());
		if(str[0] == '#') break;
		int c = str[0];
		n = 0, m = 0;
		int pp = 1;
		while(!isdigit(str[pp])) pp++;
		while(isdigit(str[pp])) n = 10*n + str[pp++] - '0';
		while(!isdigit(str[pp])) pp++;
		while(pp < (int) str.size() && isdigit(str[pp])) m = 10*m + str[pp++] - '0';
		string s;
		getline(cin, s);
		while(true)
		{
			getline(cin, str);
			if(str[0] == '#' || (str.size() > 1 && str[1] == ' ')) break;
			s += str.substr(0, (int) str.size());
		}
		if(c == 'B')
		{
			FOR(i, 0, n)
			{
				FOR(j, 0, m)
				{
					M[i][j] = (s[i*m + j] == '1');
				}
			}
			string ans;
			BToD(0, 0, n-1, m-1, ans);
			printf("D %3d %3d\n", n, m);
			FOR(i, 0, (int) ans.size())
			{
				int cnt = 0;
				while(i < (int) ans.size() && cnt < 50)
				{
					printf("%c", ans[i++]);
					cnt++;
				}
				i--;
				putchar('\n');
			}
		}
		else
		{
			printf("B %3d %3d\n", n, m);
			pos = 0;
			DToB(0, 0, n-1, m-1, s);
			int cnt = 50;
			FOR(i, 0, n)
				FOR(j, 0, m)
				{
					printf("%d", M[i][j]);
					cnt--;
					if(cnt == 0)
					{
						putchar('\n');
						cnt = 50;
					}
				}
			if(cnt < 50)
				putchar('\n');
		}
	}
    return 0;
}