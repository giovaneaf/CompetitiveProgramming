#include <iostream>

using namespace std;

int main()
{
    int N, x;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x == 0)
        {
            cout << "NULL";
        }
        else if (x%2 == 0)
        {
            cout << "EVEN";
        }
        else
        {
            cout << "ODD";
        }
        if (x < 0 && x != 0)
        {
            cout << " NEGATIVE";
        }
        else if (x != 0)
        {
            cout << " POSITIVE";
        }
        cout << endl;
    }
    return 0;
}