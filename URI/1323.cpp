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
        int squares = 0;
        for (int i = 1; i <= N; i++)
        {
            squares += (i*i);
        }
        cout << squares << endl;
    }
    return 0;
}
