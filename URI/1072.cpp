#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int val;
    int in = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        if (val >= 10 && val <= 20)
            in++;
    }
    cout << in << " in\n";
    cout << (N-in) << " out\n";
    return 0;
}