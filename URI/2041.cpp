#include <iostream>
using namespace std;

int main()
{
    string num,tmp;
    int N,i,j,k;
    char cont;
    while (!(cin >> N).eof())
    {
        num = "13";
        if (N == 1)
            cout << 3 << endl;
        else if (N == 2)
            cout << 13 << endl;
        else
        {
            for (k=2;k<N;k++)
            {
                tmp = "";
                for (i=0,j=0,cont='1';i<num.size()-1;i++,j+=2)
                {
                    if (num[i] == num[i+1])
                        cont++;
                    else
                    {
                        tmp.push_back(cont);
                        tmp.push_back(num[i]);
                        cont = '1';
                    }
                }
                tmp.push_back(cont);
                tmp.push_back(num[i]);
                num = tmp;
            }
            cout << num << endl;
        }
    }
    return 0;
}