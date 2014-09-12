#include "funcoes.h"

// limpa tela
void limpa_tela()
{
    system("cls");
}

// prompt universal
void prompt_universal()
{
    system("pause");
}

// cria pilha
pilha cria_pilha()
{
    pilha pi=(pilha)malloc(sizeof(tipo_pilha));

    if(pi)
        pi->topo=-1;

    return pi;
}

// termina pilha
void termina_pilha(pilha pi)
{
    free(pi);
}

// adiciona uma posição a pilha
int push(pilha pi, tipo_chave numero, tipo_chave cor, tipo_simbolo naipe)
{
    if(pilha_cheia(pi))
        return 0;

    pi->topo++;
    pi->cartas[pi->topo].numero=numero;
    pi->cartas[pi->topo].cor=cor;
    pi->cartas[pi->topo].naipe=naipe;

    return 1;
}

// remove uma posição da pilha
int pop(pilha pi)
{
    if(pilha_vazia(pi))
        return 0;

    pi->topo--;

    return 1;
}

// retorna verdadeiro se a pilha estiver cheia
int pilha_cheia(pilha pi)
{
    return pi->topo==NUM_CARTAS-1;
}

// retorna verdadeiro se a pilha estiver vazia
int pilha_vazia(pilha pi)
{
    return pi->topo==-1;
}

// retorna o maior "topo" de um vetor de pilhas
int maior_topo(pilha *pi)
{
    int i,maior=pi[0]->topo;

    for(i=1;i<NUM_PILHAS;i++)
    {
        if(pi[i]->topo>maior)
            maior=pi[i]->topo;
    }

    return maior;
}
