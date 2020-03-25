#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    while(!(cin >> N).eof())
    {
        if(N==0)
            break;
        int i,j;
        char start[26],finish[26];
        stack<char> pilha;
        for(i=0;i<N;i++)
            cin >> start[i];
        for(i=0;i<N;i++)
            cin >> finish[i];
        j = 0;
        i = 1;
        pilha.push(start[0]);
            cout << "I";
        do
        {
            if(pilha.empty())
            {
                pilha.push(start[i]);
                cout << "I";
                i++;
            }
            while(pilha.top()!=finish[j] && i<N)
            {
                pilha.push(start[i]);
                cout << "I";
                i++;
            }
            while (pilha.top()==finish[j])
            {
                pilha.pop();
                cout << "R";
                j++;
                if(pilha.empty())
                    break;
            }
        }while(i<N);
        if (j<N)
            cout << " Impossible";
        cout << endl;
    }
    return 0;
}