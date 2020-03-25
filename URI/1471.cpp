#include <iostream>

using namespace std;

int main()
{
    int N, R, i;
    while(!(cin >> N >> R).eof())
    {
        if (N == R)
        {
            int returned;
            for (i = 0; i < R; i++)
            {
                cin >> returned;
            }
            cout << "*\n";
        }
        else
        {
            bool dead[N];
            for(i = 0; i < N; i++)
                dead[i] = true;
            int returned;
            for (i = 0; i < R; i++)
            {
                cin >> returned;
                dead[returned-1] = false;
            }
            for (i = 0; i < N; i++)
            {
                if (dead[i])
                    cout << i+1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}