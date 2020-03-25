#include <bits/stdc++.h>

#define MAXN 110

using namespace std;

struct state
{
    int dir;
    int r, c;
};

int n, m, s;
string M[110];
string A;
state st;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int solve()
{
    int stickers = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 'D')
        {
            st.dir = (st.dir+1)%4;
        }
        else if(A[i] == 'E')
        {
            st.dir = (st.dir-1+4)%4;
        }
        else
        {
            int nr = st.r + dr[st.dir];
            int nc = st.c + dc[st.dir];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m || M[nr][nc] == '#') continue;
            if(M[nr][nc] == '*')
            {
                stickers++;
                M[nr][nc] = '.';
            }
            st.r = nr;
            st.c = nc;
        }
    }
    return stickers;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m >> s)
    {
        if(n == 0) break;
        for(int i = 0; i < n; ++i)
        {
            cin >> M[i];
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(M[i][j] == 'N')
                {
                    st.dir = 0;
                    st.r = i;
                    st.c = j;
                    break;
                }
                else if(M[i][j] == 'L')
                {
                    st.dir = 1;
                    st.r = i;
                    st.c = j;
                    break;
                }
                else if(M[i][j] == 'S')
                {
                    st.dir = 2;
                    st.r = i;
                    st.c = j;
                    break;
                }
                else if(M[i][j] == 'O')
                {
                    st.dir = 3;
                    st.r = i;
                    st.c = j;
                    break;
                }
            }
        }
        cin >> A;
        cout << solve() << '\n';
    }
    return 0;
}
