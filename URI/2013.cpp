#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char num[20];
    cin >> num;
    int tam = strlen(num);
    int i, val, val2;
    int times[10];
    bool achou;
    bool igual = true;
    for (i = 0; i < 10; i++)
        times[i] = 0;
    for (i = 0; i < tam; i++)
    {
        val = num[i]-'0';
        val2 = num[i]-'0';
        times[val]++;
        if (times[val] > 2)
        {
            igual = false;
            achou = false;
            while(!achou && i > 0)
            {
                val--;
                while(val >= 0)
                {
                    if (times[val] < 2)
                    {
                        times[val2]--;
                        num[i] = val+'0';
                        times[val]++;
                        achou = true;
                        break;
                    }
                    val--;
                }
                if (!achou)
                {
                    times[val2]--;
                    i--;
                    val = num[i] - '0';
                    val2 = val;
                }
            }
            break;
        }
    }
    if (igual)
    {
        cout << num << endl;
    }
    else if (!achou)
    {
        for (i = 0; i < tam-1; i++)
        {
            switch(i)
            {
                case 0:
                case 1: cout << "9";
                        break;
                case 2:
                case 3: cout << "8";
                        break;
                case 4:
                case 5: cout << "7";
                        break;
                case 6:
                case 7: cout << "6";
                        break;
                case 8:
                case 9: cout << "5";
                        break;
                case 10:
                case 11: cout << "4";
                        break;
                case 12:
                case 13: cout << "3";
                        break;
                case 14:
                case 15: cout << "2";
                        break;
                case 16:
                case 17: cout << "1";
                        break;
                default: cout << "0";
            }
        }
        cout << endl;
    }
    else
    {
        i++;
        int maxi = 9;
        while (i < tam)
        {
            while(times[maxi] < 2 && i < tam)
            {
                num[i] = maxi+'0';
                times[maxi]++;
                i++;
            }
            maxi--;
        }
        cout << num << endl;
    }
    return 0;
}