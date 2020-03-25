#include <iostream>
using namespace std;

int main()
{
    int n;
    while (!(cin >> n).eof())
    {
        int div;
        int resto;
        int cont=1;
        div = 1;
        do
        {
            if (div < n)
            {
                div = div*10+1;
                cont++;
            }
            resto = div%n;
            div = resto;
        } while(resto != 0);
        cout << cont << endl;
    }
    return 0;
}