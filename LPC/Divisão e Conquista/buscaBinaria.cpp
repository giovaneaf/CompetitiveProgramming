#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void buscaBinaria(ll maiorValor)
{
	// esquerda é o ponteiro da esquerda, direita é ponteiro da direita da busca binária
	// maiorValor é o maior valor escolhido pelo usuário
	ll esquerda, direita, numeroEscolhido, meio;
	numeroEscolhido = rand()%(maiorValor+1);		// gera um número aleatório entre 0 e maiorValor
	esquerda = 0;				// ponteiro da esquerda
	direita = maiorValor;		// ponteiro da direita
	int numeroDeIter = 0;		// conta o número de iterações
	printf("Valor a ser adivinhado = %lld...\n", numeroEscolhido);
	while(direita >= esquerda)
	{
		numeroDeIter++;
		meio = esquerda + (direita-esquerda)/2;
		printf("Chute atual = %lld...\n", meio);
		if(meio == numeroEscolhido)				// se encontrou, mostra o número de iterações
		{
			printf("Encontrou o valor com %d it.\n", numeroDeIter);
			break;
		}
		else if(meio < numeroEscolhido)			// se chute é menor então atualiza o ponteiro da esquerda
		{
			esquerda = meio+1;
		}
		else									// se chute é maior então atualiza o ponteiro da direita
		{
			direita = meio-1;
		}
	}
}

int main()
{
	srand(time(NULL));
	ll maiorValor;
	while(cin >> maiorValor)
	{
		buscaBinaria(maiorValor);
	}
	return 0;
}