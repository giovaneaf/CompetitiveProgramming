#include <iostream>

using namespace std;

int main()
{
    int N,x = 1;
    int i = 1;
    cin >> N;
    x = 2;
    while (x != 1)
    {
        if (x <= (N/2))
            x *= 2;
        else
            x = 2*(x - (N/2+1)) + 1;
        i++;
    }
    cout << i << endl;
    return 0;
}