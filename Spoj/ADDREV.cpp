#include <iostream>
 
using namespace std;
 
int reverseNum(int x)
{
    int remainder;
    int rev = 0;
    while (x)
    {
        remainder = x%10;
        rev = 10*rev + remainder;
        x /= 10;
    }
    return rev;
}
 
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n1,n2;
        cin >> n1 >> n2;
        n1 = reverseNum(n1);
        n2 = reverseNum(n2);
        n1 += n2;
        cout << reverseNum(n1) << endl;
    }
    return 0;
} 