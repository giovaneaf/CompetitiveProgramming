#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int ii,is,aux;
        std::cin >> ii >> is;
        if (ii > is)
        {
            aux = is;
            is = ii;
            ii = aux;
        }
        int start;
        if ((ii+1)%2 != 0)
            start = ii+1;
        else
            start = ii+2;
        int sum = 0;
        while(start < is)
        {
            sum += start;
            start += 2;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}