#include <iostream>

int main()
{
    int N, M, aux;
    while(true)
    {
        std::cin >> N >> M;
        if (N <= 0 || M <= 0)
            break;
        if (N > M)
        {
            aux = M;
            M = N;
            N = aux;
        }
        int sum = 0;
        for (int i = N; i <= M; i++)
        {
            sum += i;
            std::cout << i << " ";
        }
        std::cout << "Sum=" << sum << std::endl;
    }
    return 0;
}