#include "funcoes.h"

// embaralha
pilha embaralha()
{
    pilha pi=cria_pilha();
    tipo_chave num_sorteado,cor;
    tipo_simbolo naipe_sorteado;
    int i;

    /*
        srand(time(NULL)) objetiva inicializar o gerador de números aleatórios com o valor da função time(NULL).
        Este por sua vez, é calculado como sendo o total  de segundos passados desde 1 de janeiro de 1970
        até a data atual. Desta forma, a cada execução o valor da "semente" será diferente.
    */
    srand(time(NULL));

    // loop para sortear todas as cartas
    for(i=0;i<=NUM_CARTAS;i++)
    {
        do{
            // sorteria o numero e o naipe
            num_sorteado=1+(rand()%NUMEROS);
            naipe_sorteado=1+(rand()%NAIPES);

            switch(naipe_sorteado)
            {
            case 1:
                naipe_sorteado='c';
                cor=0;
                break;
            case 2:
                naipe_sorteado='o';
                cor=0;
                break;
            case 3:
                naipe_sorteado='e';
                cor=1;
                break;
            case 4:
                naipe_sorteado='p';
                cor=1;
                break;
            }
        }while(!verifica_sorteio(pi,num_sorteado,naipe_sorteado));

        // adiciona a carta ao baralho
        push(pi,num_sorteado,cor,naipe_sorteado);
    }

    return pi;
}

// verifica a carta sorteada já está no baralho
int verifica_sorteio(pilha pi, tipo_chave num_sorteado, tipo_simbolo naipe_sorteado)
{
    int i;

    // percorre a pilha a cartas
    for(i=0;i<NUM_CARTAS-1;i++)
        // se encontrar
        if(pi->cartas[i].numero==num_sorteado && pi->cartas[i].naipe==naipe_sorteado)
            return 0;

    return 1;
}

// divide o baralho em 4 pilhas de 7 e 4 pilhas de 6
void divide_baralho(pilha piaux, pilha pi, int tamanho)
{
    int i;

    for(i=0;i<tamanho;i++)
    {
        push(pi,piaux->cartas[piaux->topo].numero,piaux->cartas[piaux->topo].cor,piaux->cartas[piaux->topo].naipe);
        pop(piaux);
    }
}
