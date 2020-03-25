#include <stdio.h>
#include <string.h>

int main ()
{
    int i,parenteses;
    char v[1001] = {}; // precisa vetor com 1001 caracteres?
    while (scanf("%s",v) != EOF)
    {
        for (i=0,parenteses=0;i<strlen(v);i++) // loop que vai de i até o tamanho da string
            if (v[i]=='(') // adiciona 1 se o parenteses está abrindo
                parenteses++;
            else if (parenteses > 0 && v[i] == ')') // subtrai um parênteses se está fechando e já abriu pelo menos um parênteses
                parenteses--;
            else if (parenteses == 0 && v[i] == ')') // acaba o loop se tu fecha parênteses que tu n abriu
            {
                parenteses = 1;
                break;
            }
        if (parenteses) // se parênteses não for igual a zero
            printf("incorrect\n");
        else // se abriu e fechou todos o parênteses direito
            printf("correct\n");
    }
    return 0;
}