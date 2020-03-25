#include <iostream>

using namespace std;

int main()
{
    int N,D;
    while(true)
    {
        cin >> N >> D;
        if (N == 0)
            break;
        bool alldin = false;
        bool alumni[N];
        int go;
        for (int j = 0; j < N; j++)
        {
            alumni[j] = true;
        }
        for (int i = 0; i < D; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> go;
                if (go == 0)
                    alumni[j] = false;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (alumni[j])
            {
                alldin = true;
                break;
            }
        }
        if (alldin)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}