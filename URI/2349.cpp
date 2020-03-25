#include <iostream>
using namespace std;

int main()
{
    int N,C,S,i,cur,program;
    int times = 0;
    cin >> N >> C >> S;
    cur = 1;
    if (S == 1)
        times++;
    for (i = 0; i < C; i++)
    {
        cin >> program;
        if (program == 1)
        {
            if (cur == N)
                cur = 1;
            else
                cur++;
        }
        else
        {
            if (cur == 1)
                cur = N;
            else
                cur--;
        }
        if (cur == S)
            times++;
    }
    cout << times << endl;
    return 0;
}
