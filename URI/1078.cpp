#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < 10; i++)
        cout << i+1 << " x " << N << " = " << ((i+1)*N) << endl;
    return 0;
}
