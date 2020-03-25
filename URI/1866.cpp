#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int T;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        cout << (T%2) << endl;
    }
    return 0;
}
