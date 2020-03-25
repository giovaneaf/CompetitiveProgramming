#include <iostream>

typedef long long int ll;

ll GCD(ll X, ll Y)
{
    ll t;
    while (Y != 0)
    {
        t = X;
        X = Y;
        Y = t%Y;
    }
    return X;
}

int main()
{
    ll X,Y;
    while (!(std::cin >> X >> Y).eof())
    {
        if (X == Y)
            std::cout << "4\n";
        else
        {
            ll gcd = GCD (X,Y);
            ll stakes = 2*(1+X/gcd) + 2*(Y/gcd-1);
            std::cout << stakes << std::endl;
        }
    }
    return 0;
}