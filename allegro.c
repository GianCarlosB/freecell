#include "funcoes.h"

// cria uma janela
ALLEGRO_DISPLAY * ini_allegro()
{
    ALLEGRO_DISPLAY *janela=NULL; // variável representando a janela principal

    // inicializa o Allegro e o add-on para utilização de imagens
    al_init();
    al_init_image_addon();

    // configura a janela
    janela=al_create_display(800,600);

    return janela;
}

// finaliza uma janela
void fin_allegro(ALLEGRO_DISPLAY *janela)
{
    // finaliza a janela
    al_destroy_display(janela);
}

// carrega a imagem do baralho
void carrega_baralho(pilha pi_inf, pilha pi_sup, int num_pilha, ALLEGRO_BITMAP *baralho)
{
    int i,x=coordenada_x(num_pilha), // o valor de x referente a janela é definido
        y=150; // o valor de y referente a janela é definido

    // adiciona a imagem do verso da carta na posição -1 da pilha
    verifica_carta(pi_inf,0,'0',x,y,-1,baralho);

    for(i=0;i<=pi_inf->topo;i++)
    {
        verifica_carta(pi_inf,pi_inf->cartas[i].numero,pi_inf->cartas[i].naipe,x,y,i,baralho);
        y+=25;
    }

    y=25; // o valor de y referente a janela é definido
    x=coordenada_x(num_pilha); // o valor de x referente a janela é definido

    // adiciona a imagem do verso da carta na posição -1 da pilha
    verifica_carta(pi_sup,0,'0',x,y,-1,baralho);

    for(i=0;i<=pi_sup->topo;i++)
        verifica_carta(pi_sup,pi_sup->cartas[i].numero,pi_sup->cartas[i].naipe,x,y,i,baralho);
}

// verifica a posição da carta
void verifica_carta(pilha pi, tipo_chave numero, tipo_simbolo naipe, int px, int py, int indice, ALLEGRO_BITMAP *baralho)
{
    int const z=67,w=95; // tamanho da carta em pixels

    // a função salva_img é chamada passando os parâmetros da respectiva carta no sprite
    switch(naipe)
    {
    case 'c':
        switch(numero)
        {
        case 1:salva_img(pi,408,288,z,w,px,py,indice,baralho);
            break;
        case 2:salva_img(pi,476,384,z,w,px,py,indice,baralho);
            break;
        case 3:salva_img(pi,408,384,z,w,px,py,indice,baralho);
            break;
        case 4:salva_img(pi,340,384,z,w,px,py,indice,baralho);
            break;
        case 5:salva_img(pi,272,384,z,w,px,py,indice,baralho);
            break;
        case 6:salva_img(pi,204,384,z,w,px,py,indice,baralho);
            break;
        case 7:salva_img(pi,136,384,z,w,px,py,indice,baralho);
            break;
        case 8:salva_img(pi,68,384,z,w,px,py,indice,baralho);
            break;
        case 9:salva_img(pi,0,384,z,w,px,py,indice,baralho);
            break;
        case 10:salva_img(pi,680,288,z,w,px,py,indice,baralho);
            break;
        case 11:salva_img(pi,612,288,z,w,px,py,indice,baralho);
            break;
        case 12:salva_img(pi,544,288,z,w,px,py,indice,baralho);
            break;
        case 13:salva_img(pi,476,288,z,w,px,py,indice,baralho);
            break;
        }
        break;
    case 'o':
        switch(numero)
        {
        case 1:salva_img(pi,272,192,z,w,px,py,indice,baralho);
            break;
        case 2:salva_img(pi,340,288,z,w,px,py,indice,baralho);
            break;
        case 3:salva_img(pi,272,288,z,w,px,py,indice,baralho);
            break;
        case 4:salva_img(pi,204,288,z,w,px,py,indice,baralho);
            break;
        case 5:salva_img(pi,136,288,z,w,px,py,indice,baralho);
            break;
        case 6:salva_img(pi,68,288,z,w,px,py,indice,baralho);
            break;
        case 7:salva_img(pi,0,288,z,w,px,py,indice,baralho);
            break;
        case 8:salva_img(pi,680,192,z,w,px,py,indice,baralho);
            break;
        case 9:salva_img(pi,612,192,z,w,px,py,indice,baralho);
            break;
        case 10:salva_img(pi,544,192,z,w,px,py,indice,baralho);
            break;
        case 11:salva_img(pi,476,192,z,w,px,py,indice,baralho);
            break;
        case 12:salva_img(pi,408,192,z,w,px,py,indice,baralho);
            break;
        case 13:salva_img(pi,340,192,z,w,px,py,indice,baralho);
            break;
        }
        break;
    case 'e':
        switch(numero)
        {
        case 1:salva_img(pi,136,96,z,w,px,py,indice,baralho);
            break;
        case 2:salva_img(pi,204,192,z,w,px,py,indice,baralho);
            break;
        case 3:salva_img(pi,136,192,z,w,px,py,indice,baralho);
            break;
        case 4:salva_img(pi,68,192,z,w,px,py,indice,baralho);
            break;
        case 5:salva_img(pi,0,192,z,w,px,py,indice,baralho);
            break;
        case 6:salva_img(pi,680,96,z,w,px,py,indice,baralho);
            break;
        case 7:salva_img(pi,612,96,z,w,px,py,indice,baralho);
            break;
        case 8:salva_img(pi,544,96,z,w,px,py,indice,baralho);
            break;
        case 9:salva_img(pi,476,96,z,w,px,py,indice,baralho);
            break;
        case 10:salva_img(pi,408,96,z,w,px,py,indice,baralho);
            break;
        case 11:salva_img(pi,340,96,z,w,px,py,indice,baralho);
            break;
        case 12:salva_img(pi,272,96,z,w,px,py,indice,baralho);
            break;
        case 13:salva_img(pi,204,96,z,w,px,py,indice,baralho);
            break;
        }
        break;
    case 'p':
        switch(numero)
        {
        case 1:salva_img(pi,0,0,z,w,px,py,indice,baralho);
            break;
        case 2:salva_img(pi,68,96,z,w,px,py,indice,baralho);
            break;
        case 3:salva_img(pi,0,96,z,w,px,py,indice,baralho);
            break;
        case 4:salva_img(pi,680,0,z,w,px,py,indice,baralho);
            break;
        case 5:salva_img(pi,612,0,z,w,px,py,indice,baralho);
            break;
        case 6:salva_img(pi,544,0,z,w,px,py,indice,baralho);
            break;
        case 7:salva_img(pi,476,0,z,w,px,py,indice,baralho);
            break;
        case 8:salva_img(pi,408,0,z,w,px,py,indice,baralho);
            break;
        case 9:salva_img(pi,340,0,z,w,px,py,indice,baralho);
            break;
        case 10:salva_img(pi,272,0,z,w,px,py,indice,baralho);
            break;
        case 11:salva_img(pi,204,0,z,w,px,py,indice,baralho);
            break;
        case 12:salva_img(pi,136,0,z,w,px,py,indice,baralho);
            break;
        case 13:salva_img(pi,68,0,z,w,px,py,indice,baralho);
            break;
        }
        break;
    // verso da carta
    default:salva_img(pi,544,384,z,w,px,py,indice,baralho);
        break;
    }
}

// salva a imagem da respectiva carta
int salva_img(pilha pi, int x, int y, int z, int w, int px, int py, int indice, ALLEGRO_BITMAP *baralho)
{
    if(pilha_cheia(pi))
        return 0;

    pi->cartas[indice].px=px;
    pi->cartas[indice].py=py;
    pi->cartas[indice].imagem=al_create_sub_bitmap(baralho,x,y,z,w);

    return 1;
}

// define a coordenada do eixo x
int coordenada_x(int num_pilha)
{
    int x;

    switch(num_pilha)
    {
    case 1:x=75;
        break;
    case 2:x=150;
        break;
    case 3:x=225;
        break;
    case 4:x=300;
        break;
    case 5:x=415;
        break;
    case 6:x=490;
        break;
    case 7:x=565;
        break;
    case 8:x=640;
        break;
    }

    return x;
}

// exibe o tabuleiro
void exibe_tabuleiro(pilha *pi_inf, pilha *pi_sup)
{
    ALLEGRO_BITMAP *tabuleiro=NULL,*baralho=NULL; // variáveis representando as imagens
    int i,j;

    // Carrega as imagens
    tabuleiro=al_load_bitmap("tabuleiro.jpg");
    baralho=al_load_bitmap("baralho.png");

    // desenha as imagens na tela
    al_draw_bitmap(tabuleiro,0,0,0);

    for(i=0;i<NUM_PILHAS;i++)
    {
        // desenha as imagens na tela
        al_draw_bitmap(pi_sup[i]->cartas[pi_sup[i]->topo].imagem,
                       pi_sup[i]->cartas[pi_sup[i]->topo].px,
                       pi_sup[i]->cartas[pi_sup[i]->topo].py,0);

        if(pilha_vazia(pi_inf[i]))
            al_draw_bitmap(pi_inf[i]->cartas[-1].imagem,
                            pi_inf[i]->cartas[-1].px,
                            pi_inf[i]->cartas[-1].py,0);

        else
            for(j=0;j<=pi_inf[i]->topo;j++)
                al_draw_bitmap(pi_inf[i]->cartas[j].imagem,
                               pi_inf[i]->cartas[j].px,
                               pi_inf[i]->cartas[j].py,0);
    }

    // atualiza a tela
    al_flip_display();

    // finaliza as imagens
    al_destroy_bitmap(tabuleiro);
    al_destroy_bitmap(baralho);
}

// imagem da vitória \o/
void vitoria_img()
{
    ALLEGRO_BITMAP *vitoria=NULL; // variável representando a imagem

    // Carrega a imagem;
    vitoria=al_load_bitmap("vitoria.png");

    // Desenha a imagem na tela
    al_draw_bitmap(vitoria,0,0,0);

    // Atualiza a tela
    al_flip_display();

    // Segura a execução por 5 segundos
    al_rest(7.0);

    // finaliza as imagens
    al_destroy_bitmap(vitoria);
}
