#include <cstdio>
#include <cmath>

bool primeNumber(unsigned long long int N)
{
    for (int i = 3; i <= sqrt(N); i++)
    {
        if (N%i == 0)
            return false;
    }
    return true;
}

int main()
{
  unsigned long long int N;
  while(scanf("%llu",&N) != EOF) {
    if (N%2 == 0)
    {
      if (N == 2)
        printf("1\n");
      else
        printf("%llu\n",N-2);
    }
    else
    {
      if (primeNumber(N))
        printf("%llu\n",N-1);
      else if (primeNumber(N-2))
        printf("%llu\n",N-2);
      else
        printf("%llu\n",N-3);
    }
  }
  return 0;
}