#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "baralho.h"


// funções da pilha
pilha cria_pilha();
void termina_pilha(pilha);
int pilha_vazia(pilha);
int pilha_cheia(pilha);
int push(pilha,tipo_chave,tipo_chave,tipo_simbolo);
int pop(pilha);
int maior_topo(pilha *);


// funções do baralho
pilha embaralha();
int verifica_sorteio(pilha,tipo_chave,tipo_simbolo);
void divide_baralho(pilha,pilha,int);
void tabuleiro();
void imprime_pilha_inf(pilha *,int);
void imprime_pilha_sup(pilha *);
char converte_num_simb(tipo_chave);
void vitoria_msg();


// funções da jogada
int verifica_jogada(int,int);
int computa_jogada(pilha *,pilha *,int,int);
int coluna_para_coluna(pilha,pilha);
int coluna_para_base(pilha,pilha);
int coluna_para_retencao(pilha,pilha);
int retencao_para_coluna(pilha,pilha);
int retencao_para_base(pilha,pilha);
int retencao_para_retencao(pilha,pilha);
int cmp_cartas(tipo_chave,tipo_chave,tipo_chave,tipo_chave);
int cmp_naipe(tipo_simbolo,tipo_simbolo);


//funções do allegro
ALLEGRO_DISPLAY *ini_allegro();
void fin_allegro(ALLEGRO_DISPLAY *);
void carrega_baralho(pilha,pilha,int,ALLEGRO_BITMAP *);
void verifica_carta(pilha,tipo_chave,tipo_simbolo,int,int,int,ALLEGRO_BITMAP *);
int salva_img(pilha,int,int,int,int,int,int,int,ALLEGRO_BITMAP *);
int coordenada_x(int);
void exibe_tabuleiro(pilha *,pilha *);
void vitoria_img();


// outras funções
void limpa_tela();
void prompt_universal();

#endif // FUNCOES_H_INCLUDED
