#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

void DFS(char p1, char p2, vector< vector < int > >& v, bool M[][27])
{
    bool visited[26];
    memset(visited, false, sizeof(visited));
    stack<int> s;
    int init = p1-'a';
    s.push(init);
    while(s.size())
    {
        int cur = s.top();
        s.pop();
        if(!visited[cur])
        {
            visited[cur] = true;
            M[init][cur] = true;
            vector< int >::iterator it;
            for(it = v[cur].begin(); it != v[cur].end(); it++)
            {
                s.push(*it);
            }
        }
    }
    M[init][26] = true;
}

bool Can(string& p1, string& p2, vector< vector < int > >& v, bool M[][27])
{
    if(p1.size() != p2.size())
        return false;
    int len = p1.size();
    for(int i = 0; i < len; i++)
    {
        if(p1[i] != p2[i])
        {
            if(M[p1[i] - 'a'][26])
            {
                if(!M[p1[i] - 'a'][p2[i] - 'a'])
                    return false;
            }
            else
            {
                DFS(p1[i], p2[i], v, M);
                if(!M[p1[i] - 'a'][p2[i] - 'a'])
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    vector< vector < int > > v(26);
    bool M[26][27];
    memset(M, false, sizeof(M));
    int i, j;
    for(i = 0; i < 26; i++)
    {
        M[i][i] = true;
    }
    int m, n;
    string l;
    cin >> m >> n;
    getline(cin, l);
    char a, b;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a-'a'].push_back(b-'a');
    }
    vector< int >::iterator it;
    string p1, p2;
    for(i = 0; i < n; i++)
    {
        cin >> p1 >> p2;
        if(Can(p1, p2, v, M))
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}