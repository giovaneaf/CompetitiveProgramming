#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int k = 0; k < N; k++)
    {
        int i,j;
        int M[9][9];
        bool num[9];
        for (i = 0; i < 9; i++)
        {
            num[i] = false;
        }
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                cin >> M[i][j];
            }
        }
        bool solved = true;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (!num[M[i][j]-1])
                    num[M[i][j]-1] = true;
                else
                {
                    solved = false;
                    break;
                }
            }
            if (solved)
            {
                for (j = 0; j < 9; j++)
                {
                    num[j] = false;
                }
            }
            else
                break;
        }
        if (solved)
        {
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 9; j++)
                {
                    if (!num[M[j][i]-1])
                        num[M[j][i]-1] = true;
                    else
                    {
                        solved = false;
                        break;
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                }
                else
                    break;
            }
        }
        if (solved)
        {
                for (j = 0; j < 9; j++)
                {
                    num[j] = false;
                }
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (!num[M[i][j]-1])
                            num[M[i][j]-1] = true;
                        else
                        {
                            solved = false;
                            break;
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 3; j < 6; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 6; j < 9; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 3; i < 6; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 3; i < 6; i++)
                    {
                        for (j = 3; j < 6; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 3; i < 6; i++)
                    {
                        for (j = 6; j < 9; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 6; i < 9; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 6; i < 9; i++)
                    {
                        for (j = 3; j < 6; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }
                if (solved)
                {
                    for (j = 0; j < 9; j++)
                    {
                        num[j] = false;
                    }
                    for (i = 6; i < 9; i++)
                    {
                        for (j = 6; j < 9; j++)
                        {
                            if (!num[M[i][j]-1])
                                num[M[i][j]-1] = true;
                            else
                            {
                                solved = false;
                                break;
                            }
                        }
                    }
                }

        }
        cout << "Instancia " << k+1 << endl;
        if (solved)
            cout << "SIM\n";
        else
            cout << "NAO\n";
        cout << endl;
    }
    return 0;
}