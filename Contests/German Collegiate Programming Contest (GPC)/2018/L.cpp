/*
The main idea here is note that the extension doesn't have any black cell so you can start from this place like an onion.
Just start from the extended board and you can update the diagonal that belongs to the the board directly.
In the end just check if the board is consistent with the input matrix. If it is then just print the board, print 
impossible otherwise.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 110
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n, m;
int M[MAXN][MAXN];
bool ans[MAXN][MAXN];
bool mark[MAXN][MAXN];
 
int dr[] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
int dc[] = {-1, 1, 0, 0, 1, -1, 1, -1, 0};
 
inline int neigh(int r, int c)
{
    int acc = 0;
    FOR(i, 0, 9)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= n+2 || nc < 0 || nc >= m+2 || !ans[nr][nc]) continue;
        acc++;
    }
    return acc;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        FOR(i, 0, n+2)
        {
            FOR(j, 0, m+2)
            {
                cin >> M[i][j];
                ans[i][j] = false;
                mark[i][j] = false;
            }
        }
        bool valid = true;
        int ur, uc, br, bc;
        ur = uc = 0;
        br = n+1; bc = m+1;
        int gap = 0;
        while(br - ur > 1 && bc - uc > 1)
        {
            FOR(i, 0, m-gap)
            {
                int cc = uc+i;
                int cur = M[ur][cc] - neigh(ur, cc);
                if(!mark[ur+1][cc+1])
                {
                    ans[ur+1][cc+1] = (cur > 0);
                    mark[ur+1][cc+1] = true;
                }
                cur = M[br][cc] - neigh(br, cc);
                if(!mark[br-1][cc+1])
                {
                    ans[br-1][cc+1] = (cur > 0);
                    mark[br-1][cc+1] = true;
                }
            }
            FOR(i, 0, n-gap)
            {
                int cr = ur+i;
                int cur = M[cr][uc] - neigh(cr, uc);
                if(!mark[cr+1][uc+1])
                {
                    ans[cr+1][uc+1] = (cur > 0);
                    mark[cr+1][uc+1] = true;
                }
                cur = M[cr][bc] - neigh(cr, bc);
                if(!mark[cr+1][bc-1])
                {
                    ans[cr+1][bc-1] = (cur > 0);
                    mark[cr+1][bc-1] = true;
                }
            }
            ur++, uc++, br--, bc--;
            gap += 2;
        }
        FOR(i, 0, n+2)
        {
            FOR(j, 0, m+2)
            {
                if(neigh(i, j) != M[i][j])
                {
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }
        if(valid)
        {
            FOR(i, 1, n+1)
            {
                FOR(j, 1, m+1)
                {
                    printf("%c", ans[i][j] ? 'X' : '.');
                }
                printf("\n");
            }
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}