#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    while(!(cin >> A >> B >> C).eof())
    {
        if (A == B && B == C)
            cout << "*\n";
        else if (A != B && B == C)
            cout << "A\n";
        else if (B != A && A == C)
            cout << "B\n";
        else
            cout << "C\n";
    }
    return 0;
}