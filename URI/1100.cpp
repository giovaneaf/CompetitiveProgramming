#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
    int row;
    int col;
} POS;

int BFS (POS, POS);

int main()
{
    string ori;
    string dest;
    while (!(cin >> ori >> dest).eof())
    {
        POS inic, fin;
        inic.row = 7 - (ori[1] - '1');
        inic.col = ori[0] - 'a';
        fin.row = 7 - (dest[1] - '1');
        fin.col = dest[0] - 'a';
        POS teste = {7,4};
        cout << "To get from " << ori << " to " << dest << " takes " << BFS(inic,fin) << " knight moves." << endl;
    }
    return 0;
}

int BFS(POS inic, POS fin)
{
    if (inic.row == fin.row && inic.col == fin.col)
        return 0;
    POS controller = {-1,-1};
    POS addList;
    bool visited[8][8];
    queue<POS> toVisit;
    int i,j;
    for (i=0;i<8;i++)
        for (j=0;j<8;j++)
            visited[i][j] = false;
    visited[inic.row][inic.col] = true;
    toVisit.push(controller);
    int depth = 1;
    while (true)
    {
        if (inic.row + 2 == fin.row && inic.col + 1 == fin.col)
            return depth;
        if (inic.row + 2 < 8 && inic.col + 1 < 8)
        {
            addList.row = inic.row + 2;
            addList.col = inic.col + 1;
            toVisit.push(addList);
        }
        if (inic.row + 1 == fin.row && inic.col + 2 == fin.col)
            return depth;
        if (inic.row + 1 < 8 && inic.col + 2 < 8)
        {
            addList.row = inic.row + 1;
            addList.col = inic.col + 2;
            toVisit.push(addList);
        }
        if (inic.row + 2 == fin.row && inic.col - 1 == fin.col)
            return depth;
        if (inic.row + 2 < 8 && inic.col - 1 > -1)
        {
            addList.row = inic.row + 2;
            addList.col = inic.col - 1;
            toVisit.push(addList);
        }
        if (inic.row + 1 == fin.row && inic.col - 2 == fin.col)
            return depth;
        if (inic.row + 1 < 8 && inic.col -2 > -1)
        {
            addList.row = inic.row + 1;
            addList.col = inic.col - 2;
            toVisit.push(addList);
        }
        if (inic.row - 1 == fin.row && inic.col + 2 == fin.col)
            return depth;
        if (inic.row - 1 > -1 && inic.col + 2 < 8)
        {
            addList.row = inic.row - 1;
            addList.col = inic.col + 2;
            toVisit.push(addList);
        }
        if (inic.row - 2 == fin.row && inic.col + 1 == fin.col)
            return depth;
        if (inic.row - 2 > -1 && inic.col + 1 < 8)
        {
            addList.row = inic.row - 2;
            addList.col = inic.col + 1;
            toVisit.push(addList);
        }
        if (inic.row - 1 == fin.row && inic.col - 2 == fin.col)
            return depth;
        if (inic.row - 1 > -1 && inic.col - 2 > -1)
        {
            addList.row = inic.row - 1;
            addList.col = inic.col - 2;
            toVisit.push(addList);
        }
        if (inic.row - 2 == fin.row && inic.col - 1 == fin.col)
            return depth;
        if (inic.row - 2 > -1 && inic.col - 1 > -1)
        {
            addList.row = inic.row - 2;
            addList.col = inic.col - 1;
            toVisit.push(addList);
        }

        if (!toVisit.empty())
        {
            inic = toVisit.front();
            if (inic.row == -1 && inic.col == -1)
            {
                toVisit.pop();
                toVisit.push(controller);
                if (toVisit.empty())
                    break;
                inic = toVisit.front();
                depth++;
            }
            toVisit.pop();
        }
        else
            break;
    }
}