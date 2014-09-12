#include "funcoes.h"

// verifica se o parâmetros o usuário são válidos
int verifica_jogada(int origem, int destino)
{
    if(origem<1 || origem>16 || destino<1 || destino>16)
        return 1;

    return 0;
}

// computa a jogada do usuário caso for válida
int computa_jogada(pilha *pi_inf, pilha *pi_sup, int o, int d)
{
    // se a pilha de origem pertencer as pilhas inferiores
    if(o>NUM_PILHAS)
    {
        if(d>NUM_PILHAS)
        {
            if(coluna_para_coluna(pi_inf[o-NUM_PILHAS-1],pi_inf[d-NUM_PILHAS-1]))
                return 1;
        }
        if(d>NUM_PILHAS/2)
        {
            if(coluna_para_base(pi_inf[o-NUM_PILHAS-1],pi_sup[d-1]))
                return 1;
        }
        else
        {
            if(coluna_para_retencao(pi_inf[o-NUM_PILHAS-1],pi_sup[d-1]))
                return 1;
        }

        return 0;
    }
    else
    {
        if(o>NUM_PILHAS/2)
            return 0;
        if(d>NUM_PILHAS)
        {
            if(retencao_para_coluna(pi_sup[o-1],pi_inf[d-NUM_PILHAS-1]))
                return 1;
        }
        if(d>NUM_PILHAS/2)
        {
            if(retencao_para_base(pi_sup[o-1],pi_sup[d-1]))
                return 1;
        }
        else
        {
            if(pilha_vazia(pi_sup[o-1]))
                return 0;
            if(retencao_para_retencao(pi_sup[o-1],pi_sup[d-1]))
                return 1;
        }

        return 0;
    }
}

// mover carta de coluna para coluna (pilha inferior para pilha inferior)
int coluna_para_coluna(pilha pi_inf1, pilha pi_inf2)
{
    tipo_chave num_o=pi_inf1->cartas[pi_inf1->topo].numero,
               cor_o=pi_inf1->cartas[pi_inf1->topo].cor,
               num_d=pi_inf2->cartas[pi_inf2->topo].numero,
               cor_d=pi_inf2->cartas[pi_inf2->topo].cor;

    if(pilha_vazia(pi_inf2))
    {
        push(pi_inf2,num_o,cor_o,pi_inf1->cartas[pi_inf1->topo].naipe);
        pop(pi_inf1);

        return 1;
    }

    if(cmp_cartas(num_o,cor_o,num_d,cor_d)==1)
    {
        push(pi_inf2,num_o,cor_o,pi_inf1->cartas[pi_inf1->topo].naipe);
        pop(pi_inf1);

        return 1;
    }

    return 0;
}

// mover carta de coluna para base (pilha inferior para pilha base)
int coluna_para_base(pilha pi_inf, pilha pi_sup)
{
    tipo_chave num_o=pi_inf->cartas[pi_inf->topo].numero,
               cor_o=pi_inf->cartas[pi_inf->topo].cor;
    tipo_simbolo naipe_o=pi_inf->cartas[pi_inf->topo].naipe;

    if(pilha_vazia(pi_sup))
    {
        if(num_o==1)
        {
            push(pi_sup,num_o,cor_o,pi_inf->cartas[pi_inf->topo].naipe);
            pop(pi_inf);

            return 1;
        }
    }
    else
    {
        tipo_chave num_d=pi_sup->cartas[pi_sup->topo].numero,
                   cor_d=pi_sup->cartas[pi_sup->topo].cor;
        tipo_simbolo naipe_d=pi_sup->cartas[pi_sup->topo].naipe;

        if(cmp_naipe(naipe_o,naipe_d))
        {
            if(cmp_cartas(num_o,cor_o,num_d,cor_d)==2)
            {
                push(pi_sup,num_o,cor_o,pi_inf->cartas[pi_inf->topo].naipe);
                pop(pi_inf);

                return 1;
            }
        }
    }

    return 0;
}

// mover carta de coluna para retenção (pilha inferior para pilha retenção)
int coluna_para_retencao(pilha pi_inf, pilha pi_sup)
{
    tipo_chave num_o=pi_inf->cartas[pi_inf->topo].numero,
               cor_o=pi_inf->cartas[pi_inf->topo].cor;

    if(pilha_vazia(pi_sup))
    {
        push(pi_sup,num_o,cor_o,pi_inf->cartas[pi_inf->topo].naipe);
        pop(pi_inf);

        return 1;
    }

    return 0;
}

// mover carta de retenção para coluna (pilha retenção para pilha inferior)
int retencao_para_coluna(pilha pi_sup, pilha pi_inf)
{
    tipo_chave num_o=pi_sup->cartas[pi_sup->topo].numero,
               cor_o=pi_sup->cartas[pi_sup->topo].cor,
               num_d=pi_inf->cartas[pi_inf->topo].numero,
               cor_d=pi_inf->cartas[pi_inf->topo].cor;

    if(pilha_vazia(pi_inf))
    {
        push(pi_inf,num_o,cor_o,pi_sup->cartas[pi_sup->topo].naipe);
        pop(pi_sup);

        return 1;
    }

    if(cmp_cartas(num_o,cor_o,num_d,cor_d)==1)
    {
        push(pi_inf,num_o,cor_o,pi_sup->cartas[pi_sup->topo].naipe);
        pop(pi_sup);

        return 1;
    }

    return 0;
}

// mover carta de retenção para base (pilha retenção para pilha base)
int retencao_para_base(pilha pi_sup1, pilha pi_sup2)
{
    tipo_chave num_o=pi_sup1->cartas[pi_sup1->topo].numero,
               cor_o=pi_sup1->cartas[pi_sup1->topo].cor;
    tipo_simbolo naipe_o=pi_sup1->cartas[pi_sup1->topo].naipe;

    if(pilha_vazia(pi_sup2))
    {
        if(num_o==1)
        {
            push(pi_sup2,num_o,cor_o,pi_sup1->cartas[pi_sup1->topo].naipe);
            pop(pi_sup1);

            return 1;
        }
    }
    else
    {
        tipo_chave num_d=pi_sup2->cartas[pi_sup2->topo].numero,
                   cor_d=pi_sup2->cartas[pi_sup2->topo].cor;
        tipo_simbolo naipe_d=pi_sup2->cartas[pi_sup2->topo].naipe;

        if(cmp_naipe(naipe_o,naipe_d))
        {
            if(cmp_cartas(num_o,cor_o,num_d,cor_d)==2)
            {
                push(pi_sup2,num_o,cor_o,pi_sup1->cartas[pi_sup1->topo].naipe);
                pop(pi_sup1);

                return 1;
            }
        }
    }

    return 0;
}

// mover carta de retenção para retenção (pilha retenção para pilha retenção)
int retencao_para_retencao(pilha pi_sup1, pilha pi_sup2)
{
    tipo_chave num_o=pi_sup1->cartas[pi_sup1->topo].numero,
               cor_o=pi_sup1->cartas[pi_sup1->topo].cor;

    if(pilha_vazia(pi_sup2))
    {
        push(pi_sup2,num_o,cor_o,pi_sup1->cartas[pi_sup1->topo].naipe);
        pop(pi_sup1);

        return 1;
    }

    return 0;
}

// compara duas "cartas"
int cmp_cartas(tipo_chave num_o, tipo_chave cor_o, tipo_chave num_d, tipo_chave cor_d)
{
    // movimento geral
    if(num_o==num_d-1 && cor_o!=cor_d)
        return 1;

    // movimento para pilha base
    if(num_o==num_d+1 && cor_o==cor_d)
        return 2;

    return 0;
}

// compara o naipe de duas "cartas"
int cmp_naipe(tipo_simbolo naipe_o, tipo_simbolo naipe_d)
{
    if(naipe_o==naipe_d)
        return 1;

    return 0;
}
