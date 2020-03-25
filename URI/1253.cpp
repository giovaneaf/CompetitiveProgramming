#include <iostream>
using namespace std;

int main()
{
    int j,i,N,casas;
    string pal;
    j=0;
    cin >> N;
    do
    {
        cin >> pal >> casas;
        for (i=0;i<pal.size();i++)
        {
            if ((char)(pal[i]-casas) >= 'A' && (char)(pal[i]-casas) <= 'Z')
            {
                pal[i] -= casas;
            }
            else
                pal[i] = pal[i]-casas+('Z'-'A'+1);
        }
        cout << pal << endl;
        j++;
    } while (j<N);
    return 0;
}