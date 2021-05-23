#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 1000010
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000009LL;

int T;
int n, m;
string M[5];
vector<vb> row;
vector<vb> col;
int hor[2][5];
int ver[2][5];

int cnt;
char taller;

bool isValid()
{
    FOR(i, 0, n)
    {
        if(ver[0][i] > -1)
        {
            cnt = 1;
            taller = M[0][i];
            FOR(j, 1, n)
            {
                if(M[j][i] > taller)
                {
                    taller = M[j][i]; cnt++;
                }
            }
            if(cnt != ver[0][i])
                return false;
        }
        if(hor[0][i] > -1)
        {
            cnt = 1;
            taller = M[i][0];
            FOR(j, 1, n)
            {
                if(M[i][j] > taller)
                {
                    taller = M[i][j]; cnt++;
                }
            }
            if(cnt != hor[0][i])
                return false;
        }
        if(ver[1][i] > -1)
        {
            cnt = 1;
            taller = M[n-1][i];
            RFOR(j, n-2, 0)
            {
                if(M[j][i] > taller)
                {
                    taller = M[j][i]; cnt++;
                }
            }
            if(cnt != ver[1][i])
                return false;
        }
        if(hor[1][i] > -1)
        {
            cnt = 1;
            taller = M[i][n-1];
            RFOR(j, n-2, 0)
            {
                if(M[i][j] > taller)
                {
                    taller = M[i][j]; cnt++;
                }
            }
            if(cnt != hor[1][i])
                return false;
        }
    }
    return true;
}

bool solve(int r, int c)
{
    if(r == n)
        return isValid();
    int nr, nc;
    if(c == n-1)
    {
        nr = r+1;
        nc = 0;
    }
    else
    {
        nr = r;
        nc = c+1;
    }
    if(M[r][c] != '-')
    {
        return solve(nr, nc);
    }
    FOR(i, 0, n)
    {
        if(row[r][i] && col[c][i])
        {
            row[r][i] = false;
            col[c][i] = false;
            M[r][c] = i + '1';
            if(solve(nr, nc))
            {
                return true;
            }
            M[r][c] = '-';
            row[r][i] = true;
            col[c][i] = true;
        }
    }
    return false;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    row.resize(5, vb(5, true));
    col.resize(5, vb(5, true));
	while(cin >> T)
	{
        FOR(i, 0, 5)
            M[i] = "-----";
		FOR(t, 0, T)
		{
            if(t > 0)
                putchar('\n');
            cin >> n;
            FOR(i, 0, n)
            {
                fill(row[i].begin(), row[i].end(), true);
                fill(col[i].begin(), col[i].end(), true);
            }
            string str;
            cin >> str;
            str = str.substr(1, n);
            FOR(i, 0, n)
            {
                if(str[i] == '-')
                    ver[0][i] = -1;
                else
                    ver[0][i] = str[i]-'0';
            }
            FOR(i, 0, n)
            {
                cin >> str;
                if(str[0] == '-')
                    hor[0][i] = -1;
                else
                    hor[0][i] = str[0]-'0';
                if(str[n+1] == '-')
                    hor[1][i] = -1;
                else
                    hor[1][i] = str[n+1]-'0';
                FOR(j, 1, n+1)
                {
                    M[i][j-1] = str[j];
                    if(str[j] != '-')
                    {
                        row[i][str[j]-'1'] = false;
                        col[j-1][str[j]-'1'] = false;
                    }
                }
            }
            cin >> str;
            str = str.substr(1, n);
            FOR(i, 0, n)
            {
                if(str[i] == '-')
                    ver[1][i] = -1;
                else
                    ver[1][i] = str[i]-'0';
            }
            bool hasSol = solve(0, 0);
            if(!hasSol)
                printf("no\n");
            else
                FOR(i, 0, n)
                {
                    FOR(j, 0, n)
                    {
                        printf("%c", M[i][j]);
                    }
                    putchar('\n');
                }
		}
	}
	return 0;
}