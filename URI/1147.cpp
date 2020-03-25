#include <stdio.h>

int safe_pos(char v[9][3],char valid_pos[9][3])
{
    int i,j,safety;
    int val_pos = valid_pos[8][0]-48;
    for (i=0,safety=0;i<val_pos;i++)
    {
        for (j=1;j<9;j++)
        {
            if ((valid_pos[i][0]+1 != v[j][0] || valid_pos[i][1]+1 != v[j][1]) && (valid_pos[i][0]+1 != v[j][0] || valid_pos[i][1]-1 != v[j][1]))
                continue;
            else
            {
                j=10;
                break;
            }
        }
        if (j==9)
            safety++;
    }
    return safety;
}

char av_pos(char pos[8][3],char valid_pos[9][3])
{
    int i,j;
    char avaible;
    for (i=0,avaible=0;i<8;i++)
        if (pos[i][0]>'0' && pos[i][0]<'9' && pos[i][1]>='a' && pos[i][1]<'i')
        {
            valid_pos[avaible][0] = pos[i][0];
            valid_pos[avaible][1] = pos[i][1];
            avaible++;
        }
    valid_pos[8][0] = avaible+48;
}

char positions(char v[9][3],char pos[8][3])
{
    pos[0][0] = v[0][0] + 1;
    pos[0][1] = v[0][1] + 2;
    pos[1][0] = v[0][0] + 1;
    pos[1][1] = v[0][1] - 2;
    pos[2][0] = v[0][0] - 1;
    pos[2][1] = v[0][1] + 2;
    pos[3][0] = v[0][0] - 1;
    pos[3][1] = v[0][1] - 2;
    pos[4][0] = v[0][0] + 2;
    pos[4][1] = v[0][1] + 1;
    pos[5][0] = v[0][0] + 2;
    pos[5][1] = v[0][1] - 1;
    pos[6][0] = v[0][0] - 2;
    pos[6][1] = v[0][1] + 1;
    pos[7][0] = v[0][0] - 2;
    pos[7][1] = v[0][1] - 1;
}

int main()
{
    int i,j;
    char v[9][3];
    char pos[8][3];
    char valid_pos[9][3];
    int cont=1;
    while (scanf("%s",v[0]) != EOF)
    {
        if (v[0][0] == '0')
            break;
        for (i=1;i<9;i++)
            scanf("%s",v[i]);
        positions(v,pos);
        av_pos(pos,valid_pos);
        printf("Caso de Teste #%d: %d movimento(s).\n",cont,safe_pos(v,valid_pos));
        cont ++;
    }
    return 0;
}
