#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct
{
    int x,y;
}COORD;

int compare(const void* a, const void* b)
{
    return (* (COORD *)a).x - (*(COORD *)b).x;
}

int main()
{
    int N, i, j, k, rec = 0;;
    cin >> N;
    COORD v[N];
    for (i = 0; i < N; i++)
    {
        cin >> v[i].x >> v[i].y;
    }
    qsort(v,N,sizeof(COORD),compare);
    int up, down;
    for (i = 0; i < N-1; i++)
    {
        if (v[i].x != v[i+1].x && v[i].y != v[i+1].y)
            rec++;
        up = down = v[i+1].y;
        for (j = i+2; j < N; j++)
        {
            if (v[j].x != v[i].x)
            {
                if (!((v[j].y <= down && v[i].y >= down) || (v[j].y >= up && v[i].y <= up)))
                    rec++;
            }
            int dist = v[j].y - v[i].y;
            if ((((abs(dist)) < (abs(up - v[i].y))) || (up < v[i].y)) && dist >= 0)
                up = v[j].y;
            if (((abs(dist)) < (abs(down - v[i].y)) || (down > v[i].y)) && dist <= 0)
                down = v[j].y;
            if (up == v[i].y || down == v[i].y)
                break;
        }
    }
    cout << rec << endl;
    return 0;
}