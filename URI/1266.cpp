#include <iostream>

using namespace std;

int main()
{
    int N;
    while(true)
    {
        cin >> N;
        if (N == 0)
            break;
        bool fence;
        int first;
        int fences = 0;
        bool zero;
        bool impar;
        cin >> first;
        if (first)
        {
            fence = false;
            zero = false;
            impar = false;
        }
        else
        {
            fence = true;
            zero = true;
            impar = true;
        }
        int num;
        for (int i = 1; i < N; i++)
        {
            cin >> num;
            if (zero)
            {
                if (num)
                {
                    zero = false;
                    fence = false;
                }
                else
                {
                    if (impar)
                        impar = false;
                    else
                        impar = true;
                    if (fence)
                    {
                        fence = false;
                        fences++;
                    }
                    else
                    {
                        fence = true;
                    }
                }
            }
            else if (num)
            {
                fence = false;
            }
            else
            {
                if (fence)
                {
                    fence = false;
                    fences++;
                }
                else
                {
                    fence = true;
                }
            }
        }
        if (fence && (!first) && impar)
            fences++;
        cout << fences << endl;
    }
    return 0;
}