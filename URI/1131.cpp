#include <iostream>
using namespace std;

int main()
{
    int continua;
    int inter,gremio,empate;
    inter=gremio=empate=0;
    int goli,golg;
    do
    {
        cin >> goli >> golg;
        if(goli>golg)
            inter++;
        else if (goli<golg)
            gremio++;
        else
            empate++;
        cout << "Novo grenal (1-sim 2-nao)" << endl;
        cin >> continua;
    }while(continua == 1);
    cout << inter+gremio+empate << " grenais" << endl;
    cout << "Inter:" << inter << endl;
    cout << "Gremio:" << gremio << endl;
    cout << "Empates:" << empate << endl;
    if(inter > gremio)
        cout << "Inter venceu mais" << endl;
    else if (inter < gremio)
        cout << "Gremio venceu mais" << endl;
    else
        cout << "Nao houve vencedor" << endl;
    return 0;
}
