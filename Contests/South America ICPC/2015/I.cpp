#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int val;
    int score = 0;
    for (int i = 0 ; i < 5; i++)
    {
        cin >> val;
        if (val == T)
            score++;
    }
    cout << score << endl;
    return 0;
}