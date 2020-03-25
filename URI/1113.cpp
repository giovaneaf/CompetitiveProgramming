#include <iostream>

int main()
{
    int x,y;
    while(true)
    {
        std::cin >> x >> y;
        if (x == y)
            break;
        if (x > y)
            std::cout << "Decrescente\n";
        else
            std::cout << "Crescente\n";
    }
    return 0;
}