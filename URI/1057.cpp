#include <bits/stdc++.h>

using namespace std;

int n;
char M[15][15];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

typedef struct person
{
    person()
    {
        r = 0;
        c = 0;
    }
    int r, c;
} person;

bool equal (const person& p1, const person& p2)
{
    return p2.r == p1.r and p2.c == p1.c;
}

bool available(int i, int j)
{
    return i >= 0 and i < n and j >= 0 and j < n and M[i][j] != '#';
}

int BFS(person& a, person& b, person& c)
{
    unordered_set<int> s;
    queue<pair<int, int>> q;
    vector<person> v(3);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    int state = 0;
    for(int i = 0; i < 3; ++i)
    {
        state += (v[i].r << 8*i);
        state += (v[i].c << (4 + 8*i));
    }
    v.clear();
    q.push(make_pair(state, 0));
    int cnt = 0;
    while(q.size())
    {
        int state = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(s.count(state) != 0)
            continue;
        s.insert(state);
        vector<person> v(3);
        for(int i = 0; i < 3; ++i)
        {
            int mult = 1;
            for(int j = 0; j < 4; ++j)
            {
                v[i].r += (state & (1 << 8*i+j) ? 1 : 0)*mult;
                v[i].c += (state & (1 << 8*i+4+j) ? 1 : 0)*mult;
                mult <<= 1;
            }
        }
        if(v[0].r < 0 or v[0].r >= n or v[0].c < 0 or v[0].c >= n 
            or v[1].r < 0 or v[1].r >= n or v[1].c < 0 or v[1].c >= n
            or v[2].r < 0 or v[2].r >= n or v[2].c < 0 or v[2].c >= n)
            continue;
        if(M[v[0].r][v[0].c] == 'X' and M[v[1].r][v[1].c] == 'X' and M[v[2].r][v[2].c] == 'X')
            return dist;
        vector<person> aux(3);
        for(int i = 0; i < 4; ++i)
        {
            aux = v;
            vector<bool> stucked(3);
            for(int j = 0; j < 3; ++j)
            {
                if(available(aux[j].r + dr[i], aux[j].c + dc[i]))
                {
                    stucked[j] = false;
                }
                else
                {
                    stucked[j] = true;
                }
            }
            for(int j = 0; j < 3; ++j)
            {
                if(!stucked[j])
                {
                    aux[j].r = aux[j].r + dr[i];
                    aux[j].c = aux[j].c + dc[i];
                    if((stucked[(j+1)%3] and equal(aux[j], aux[(j+1)%3])) or (stucked[(j+2)%3] and equal(aux[j], aux[(j+2)%3])))
                    {
                        stucked[j] = true;
                        aux[j].r -= dr[i];
                        aux[j].c -= dc[i];
                    }
                    else if(equal(aux[j], aux[(j+1)%3]))
                    {
                        int idx = (j+1)%3;
                        int oidx = (j+2)%3;
                        if(stucked[oidx])
                        {
                            person p;
                            p.r = aux[idx].r + dr[i];
                            p.c = aux[idx].c + dc[i];
                            if(equal(p, aux[oidx]))
                            {
                                stucked[j] = stucked[idx] = true;
                                aux[j].r -= dr[i];
                                aux[j].c -= dc[i];
                            }
                        }
                    }
                    else if(equal(aux[j], aux[(j+2)%3]))
                    {
                        int idx = (j+2)%3;
                        int oidx = (j+1)%3;
                        if(stucked[oidx])
                        {
                            person p;
                            p.r = aux[idx].r + dr[i];
                            p.c = aux[idx].c + dc[i];
                            if(equal(p, aux[oidx]))
                            {
                                stucked[j] = stucked[idx] = true;
                                aux[j].r -= dr[i];
                                aux[j].c -= dc[i];
                            }
                        }
                    }
                }
            }
            int state = 0;
            for(int i = 0; i < 3; ++i)
            {
                state += (aux[i].r << 8*i);
                state += (aux[i].c << (4 + 8*i));
            }
            if(s.count(state) == 0)
                q.push(make_pair(state, dist+1));
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        cin >> n;
        person A, B, C;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cin >> M[i][j];
                if(M[i][j] == 'A')
                {
                    A.r = i;
                    A.c = j;
                }
                else if(M[i][j] == 'B')
                {
                    B.r = i;
                    B.c = j;
                }
                else if(M[i][j] == 'C')
                {
                    C.r = i;
                    C.c = j;
                }
            }
        }
        int ans = BFS(A, B, C);
        printf("Case %d: ", t);
        if(ans == -1)
            printf("trapped");
        else
            printf("%d", ans);
        putchar('\n');
    }
    return 0;
}
