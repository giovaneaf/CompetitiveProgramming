#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
    int i, j;
    int a,b,c,d,e,f,g;
    int time;
} state;

int BFS(vector < string >& M, state& s, state& e, int ML, int MC)
{
    bool v[110][110][2][2][2][2][2][2][2];
    memset(v, false, sizeof v);
    queue < state > q;
    q.push(s);
    while(q.size())
    {
        state c = q.front();
        q.pop();
        if (!v[c.i][c.j][c.a][c.b][c.c][c.d][c.e][c.f][c.g])
        {
            v[c.i][c.j][c.a][c.b][c.c][c.d][c.e][c.f][c.g] = true;

            for (int n = -2; n <= 2; n++)
            {
                if (n == 0) continue;
                state aux = c;
                aux.i += (n/2); aux.j += (n%2);
                if (aux.i >= ML || aux.i < 0 || aux.j < 0 || aux.j >= MC) continue;
                if(aux.i == e.i && aux.j == e.j)
                    return aux.time+1;
                if (v[aux.i][aux.j][aux.a][aux.b][aux.c][aux.d][aux.e][aux.f][aux.g]) continue;
                if (M[aux.i][aux.j] != '#')
                {
                    aux.time += 1;
                    if (M[aux.i][aux.j] == 'a')
                    {
                        aux.a = 1;
                    }
                    else if (M[aux.i][aux.j] == 'b')
                    {
                        aux.b = 1;
                    }
                    else if (M[aux.i][aux.j] == 'c')
                    {
                        aux.c = 1;
                    }
                    else if (M[aux.i][aux.j] == 'd')
                    {
                        aux.d = 1;
                    }
                    else if (M[aux.i][aux.j] == 'e')
                    {
                        aux.e = 1;
                    }
                    else if (M[aux.i][aux.j] == 'f')
                    {
                        aux.f = 1;
                    }
                    else if (M[aux.i][aux.j] == 'g')
                    {
                        aux.g = 1;
                    }
                    else if (M[aux.i][aux.j] == 'A')
                    {
                        if (aux.a == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'B')
                    {
                        if (aux.b == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'C')
                    {
                        if (aux.c == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'D')
                    {
                        if (aux.d == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'E')
                    {
                        if (aux.e == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'F')
                    {
                        if (aux.f == 0)
                            continue;
                    }
                    else if (M[aux.i][aux.j] == 'G')
                    {
                        if (aux.g == 0)
                            continue;
                    }
                    q.push(aux);
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector < string > M(110);
    int lin = 0;
    while (getline(cin, M[lin]))
        lin++;
    int col = M[0].size();
    state s;
    s.a = s.b = s.c = s.d = s.e = s.f = s.g = s.time = 0;
    state e;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (M[i][j] == '@')
            {
                s.i = i;
                s.j = j;
            }
            else if (M[i][j] == '*')
            {
                e.i = i;
                e.j = j;
            }
        }
    }
    int dist = BFS(M, s, e, lin, col);
    if (dist == -1)
        cout << "--";
    else
        cout << dist;
    cout << endl;
    return 0;
}
