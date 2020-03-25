#include <iostream>

int main()
{
    int N;
    while(true)
    {
        std::cin >> N;
        if (N == 2002)
        {
            std::cout << "Acesso Permitido\n";
            break;
        }
        else
        {
            std::cout << "Senha Invalida\n";
        }
    }
    return 0;
}