#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int sum[M];
    int D[M];
    int B[M];
    int pts;
    int pD = 0;
    for (int i = 0; i < M; i++)
    {
        sum[i] = 0;
        cin >> B[i];
        cin >> pts;
        D[i] = pts;
        sum[i] += pts;
        for (int j = 1; j < N; j++)
        {
            cin >> pts;
            sum[i] += pts;
        }
        if (sum[i] <= B[i])
            pD += D[i];
    }
    int bS = 0;
    for (int i = 0; i < M; i++)
    {
        int score = sum[i] - D[i];

        if (score + 10000 <= B[i])
            bS += 10000;
        else if (score + 1000 <= B[i])
            bS += 1000;
        else if (score + 100 <= B[i])
            bS += 100;
        else if (score + 10 <= B[i])
            bS += 10;
        else if (score + 1 <= B[i])
            bS += 1;
    }
    cout << (bS - pD) << endl;
    return 0;
}