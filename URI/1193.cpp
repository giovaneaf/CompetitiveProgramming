#include <stdio.h>
#include <math.h>

inic(char v[])        // inicia o vetor com * para determinar qual o nº de bits digitado
{
    int i;
    for (i=0;i<33;i++)
        v[i]='*';
}

size(char bits[])   // calcula o nº de bits inserido
{
    int i;
    for (i=0; bits[i]!='*';i++)
        ;
    return (i-2);
}

decimal(char bits[],int len,int hex)  //calcula o valor decimal
{
    int i,dec;
    for(i=0,dec=0;len>=0;len--,i++)
        if (hex)    //se for hexadecimal, determinamos o valor assim
            switch(bits[len])
            {
                case '1': dec += pow(16.0,i); break;
                case '2': dec += 2*pow(16.0,i); break;
                case '3': dec += 3*pow(16.0,i); break;
                case '4': dec += 4*pow(16.0,i); break;
                case '5': dec += 5*pow(16.0,i); break;
                case '6': dec += 6*pow(16.0,i); break;
                case '7': dec += 7*pow(16.0,i); break;
                case '8': dec += 8*pow(16.0,i); break;
                case '9': dec += 9*pow(16.0,i); break;
                case 'a': dec += 10*pow(16.0,i); break;
                case 'b': dec += 11*pow(16.0,i); break;
                case 'c': dec += 12*pow(16.0,i); break;
                case 'd': dec += 13*pow(16.0,i); break;
                case 'e': dec += 14*pow(16.0,i); break;
                case 'f': dec += 15*pow(16.0,i); break;
            }
        else    // se valor for binário, calculamos desse jeito
            if (bits[len]=='1')
                dec += pow(2.0,i);
    return dec;
}

binary(char bits[],int len,int dec) // calcula valor em binário
{
    int div,i,j;
    float aux;  // tenho que criar aux float para usar pow, se n dá errado
    char res[33]; // guarda os valores do resto das divisões
    char bin[33];
    inic(bin);
    if (dec)    // se valor é decimal, converte para decimal
    {
        for (i=0,aux=0;len>=0;len--,i++)
            switch(bits[len])
            {
                case '1': aux += pow(10.0,i); break;
                case '2': aux += 2.0*pow(10.0,i); break;
                case '3': aux += 3.0*pow(10.0,i); break;
                case '4': aux += 4.0*pow(10.0,i); break;
                case '5': aux += 5.0*pow(10.0,i); break;
                case '6': aux += 6.0*pow(10.0,i); break;
                case '7': aux += 7.0*pow(10.0,i); break;
                case '8': aux += 8.0*pow(10.0,i); break;
                case '9': aux += 9.0*pow(10.0,i); break;
            }
        div = aux; // inteiro que representa o valor decimal
    }
    else // se valor hexadecimal converte para decimal
        div = decimal(bits,len,1);
    for(i=0;div>0;i++)  // método da divisão para determinar binário
    {
        res[i] = div%2;
        div /= 2;
    }
    for (j=0;i>0;i--,j++)
        bin[j]=res[i-1];    // ordena os bits para ficar em ordem binária
    bin[j]='\0';
    for (i=0;i<j;i++)
        printf("%d",bin[i]); // mostra os bits em binário
}

hex(char bits[],int len,int dec) // calcula hexadecimal (mesmo passo do binário)
{
    int div,i,j;
    float aux;
    char res[33];
    char bin[33];
    inic(bin);
    if (dec) // se é decimal, calcula o valor decimal
    {
        for (i=0,aux=0;len>=0;len--,i++)
            switch(bits[len])
            {
                case '1': aux += pow(10.0,i); break;
                case '2': aux += 2.0*pow(10.0,i); break;
                case '3': aux += 3.0*pow(10.0,i); break;
                case '4': aux += 4.0*pow(10.0,i); break;
                case '5': aux += 5.0*pow(10.0,i); break;
                case '6': aux += 6.0*pow(10.0,i); break;
                case '7': aux += 7.0*pow(10.0,i); break;
                case '8': aux += 8.0*pow(10.0,i); break;
                case '9': aux += 9.0*pow(10.0,i); break;
            }
        div = aux; // inteiro que representa o valor decimal
    }
    else // se for binário, calcula o valor decimal do binário
        div = decimal(bits,len,0);
    for(i=0;div>0;i++)  // faz pelo método das divisões
    {
        if (div%16>=10) // como a variável armazenada é char, não pode ser um inteiro maior que 9, logo converte para a notação hexadecimal
            switch(div%16)
            {
                case 10: res[i] = 'a'; break;
                case 11: res[i] = 'b'; break;
                case 12: res[i] = 'c'; break;
                case 13: res[i] = 'd'; break;
                case 14: res[i] = 'e'; break;
                case 15: res[i] = 'f'; break;
            }
        else
            res[i] = div%16;
        div /= 16;
    }
    for (j=0;i>0;i--,j++)
        bin[j]=res[i-1];    //ordena o vetor como no binário
    bin[j]='\0';
    for (i=0;i<j;i++)   // mostra os bits em hexadecimal
        if (bin[i]>='a' && bin[i]<='f')
            printf("%c",bin[i]);
        else
            printf("%d",bin[i]);
}

int main()
{
    int N,len,i,teste;
    char base[4];   // inicia um vetor que armazena base que está o número
    char bits[33];  // inicia um vetor que armazena os bits da base
    scanf("%d",&N); // lê o nº de vezes que deseja consultar
    for (i=0;i<N;i++)
    {
        inic(bits); // inicia com vetor com *
        scanf(" %s",&bits); // lê bits
        scanf(" %s",&base); // lê base
        len = size(bits); // calcula o nº de bits
        if (base[0] == 'b' && base[1] == 'i' && base [2] == 'n' && decimal(bits,len,0)>0) // testa se dá em binário
        {
            // printa como pede na tela
            printf("Case %d:\n",i+1);
            printf("%d dec\n",decimal(bits,len,0));
            hex(bits,len,0);
            printf(" hex\n");
        }
        else
            if (base[0] == 'd' && base[1] == 'e' && base [2] == 'c') // testa se dá em decimal
            {
                // printa como pede na tela
                printf("Case %d:\n",i+1);
                hex(bits,len,1);
                printf(" hex\n");
                binary(bits,len,1);
                printf(" bin\n");
            }
            else // testa se dá em hexadecimal
                if (base[0] == 'h' && base[1] == 'e' && base [2] == 'x' && decimal(bits,len,1)>0)
                {
                    // printa como pede na tela
                    printf("Case %d:\n",i+1);
                    printf("%d dec\n",decimal(bits,len,1));
                    binary(bits,len,0);
                    printf(" bin\n");
                }
        putchar ('\n');
    }
    return 0;
}