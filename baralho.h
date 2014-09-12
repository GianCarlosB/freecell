#ifndef BARALHO_H_INCLUDED
#define BARALHO_H_INCLUDED

#include <allegro5/allegro.h> // Inclui o cabeçalho da bibilioteca Allegro 5
#include <allegro5/allegro_image.h> // Inclui o cabeçalho do add-on para uso de imagens

#define NUM_CARTAS  52
#define NUMEROS 13
#define NAIPES 4
#define NUM_PILHAS 8

typedef int tipo_chave;
typedef char tipo_simbolo;

typedef struct
{
    // parâmetros da carta
    tipo_chave numero,cor;
    tipo_simbolo naipe;

    // referênte a imagem da carta
    ALLEGRO_BITMAP *imagem;
    int px,py;
}tipo_carta;

typedef struct
{
    tipo_carta cartas[NUM_CARTAS];
    int topo;
}tipo_pilha;

typedef tipo_pilha *pilha;


#endif // BARALHO_H_INCLUDED
