#include <stdio.h>
#include <math.h>

main ()
{
    long long int real;
    int cent,i;
    int nota_moeda[12]; //vetor com o nº de notas/moedas de cada
    for (i=0;i<12;i++)
        nota_moeda[i]=0;
    int valores[] = {100,50,20,10,5,2,1,50,25,10,5,1}; //fazer a divisão de cada um e ver o resto para continuar
    float mostra_valores[] = {100.00,50.00,20.00,10.00,5.00,2.00,1.00,0.50,0.25,0.10,0.05,0.01}; //mostrar para cada caso
    float N;    //valor a ser testado
    scanf("%f",&N);
    real = N;   // int da parte dos reais
    cent = round((N-real)*100);  //int da parte dos centavos
    for (i=0;i<6;i++) //calcula a divisão inteira e o resto para ver qtas notas são possíveis
    {
        nota_moeda[i] = real/valores[i];
        real = real%valores[i];
    }
    if (real == 1)  //se real = 1, então temos que dar um real que está sobrando para a pessoa
        nota_moeda[i] = 1;
    for (i=7;i<12;i++)
    {
        nota_moeda[i] = cent/valores[i];
        cent = cent%valores[i];
    }

    //mostra o nº de notas e moedas

    printf("NOTAS:\n");
    for (i=0;i<6;i++)
        printf("%d nota(s) de R$ %.2f\n",nota_moeda[i],mostra_valores[i]);
    printf("MOEDAS:\n");
    for (i=6;i<12;i++)
        printf("%d moeda(s) de R$ %.2f\n",nota_moeda[i],mostra_valores[i]);
}