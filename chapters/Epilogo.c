#include <stdbool.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include "CAPITULO.h"
#include "../objects/Player.h"
#include "../objects/Inimigo.h"
#include "../objects/Inventario.h"
#include "../utils/utils.h"
#include "../system/Save.h"

typedef enum selecao{
    MATAR,
    POUPAR
} selecao;

typedef enum estado_rei
{
    MORTO,
    VIVO
} estado_rei;

void Ver_Epilogo(Player *player)
{
    int max_y = getmaxy(stdscr);
    int max_x = getmaxx(stdscr);
    WINDOW* tela_epilogo = newwin(max_y, max_x, 0, 0);
    keypad(tela_epilogo, TRUE);
    wtimeout(tela_epilogo, 33);

    box(tela_epilogo,0,0);
    wrefresh(tela_epilogo);
    desenhar_sprite(tela_epilogo, "assets/sprites/bosses/fallen_king_defeated.txt", 1, max_x/2-20);

    mvwprintw(tela_epilogo, 35, max_x / 2 - 20, "E quanto a agora? Qual decisão pretende tomar?");


    int tecla;
    selecao atual=MATAR;
    estado_rei res=MORTO;
    while(true)
    {
        tecla = wgetch(tela_epilogo);

        if(atual==MATAR)
        {
            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));
            mvwprintw(tela_epilogo, 40, max_x / 2 - 20, "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜"); 
            mvwprintw(tela_epilogo, 41, max_x / 2 - 20, "▌   Eliminar   ▐"); 
            mvwprintw(tela_epilogo, 42, max_x / 2 - 20, "▌    o rei     ▐"); 
            mvwprintw(tela_epilogo, 43, max_x / 2 - 20, "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟");
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));
        }
        else
        {
            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));

            mvwprintw(tela_epilogo, 40, max_x / 2 + 13, "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜");
            mvwprintw(tela_epilogo, 41, max_x / 2 + 13, "▌    Prestar    ▐");
            mvwprintw(tela_epilogo, 42, max_x / 2 + 13, "▌   clemência   ▐");
            mvwprintw(tela_epilogo, 43, max_x / 2 + 13, "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟");
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));
        }

        if (tecla == '1') 
            atual=MATAR;
        else if(tecla=='2') 
            atual=POUPAR;
        else if(tecla == KEY_RIGHT || tecla == 'd')
        {
            if (atual == MATAR)
                atual = POUPAR;
            else
                atual = MATAR;
        }
        else if (tecla == KEY_LEFT || tecla == 'a')
        {
            if(atual==MATAR)
                atual=POUPAR;
            else
                atual = MATAR;
        }
        else if (tecla == KEY_ENTER || tecla == '\n' || tecla==10)
        {
            if(atual==POUPAR)
            {
                res=VIVO;
                player->karma+=1;
            }
        }
    }

    FinalRealizado fim;
    if(player->karma>5)
        fim=PACIFISTA;
    else if(player->karma>0)
        fim=NEUTRO;
    else
        fim=GENOCIDA;


    werase(tela_epilogo);
    box(tela_epilogo, 0, 0);
    wrefresh(tela_epilogo);

    int y=5;
    int mid = max_x / 2 - 20;

    switch(fim)
    {
        case PACIFISTA:
            slow_mvwprintw(tela_epilogo, "Vejo que seu coração é movido por algo além de puro desejo e ambição, carregando bondade que não tive em vida", y, mid, 40);
            slow_mvwprintw(tela_epilogo, "Notas algo diferente em si com isto?.", y+1, mid, 40);

            break;

        case NEUTRO:

            if(res==MORTO)
            {
                slow_mvwprintw(tela_epilogo, "Mantendo sua determinação, você empurra lentamente a espada do rei em direção a seu peito esquelético", y, mid, 40);
                slow_mvwprintw(tela_epilogo, "as runas gravadas em sua espada brilham em um fraco azul, conforme a forma atual do rei caído se desfaz lentamente.", y + 1, mid, 40);
                tocar_sound_effect("assets/sound_effect/boom.wav");

                slow_mvwprintw(tela_epilogo, "Como se a própria realidade se chocasse, parece que o Intervalo reage a sua voz,", y + 3, mid, 40);
                slow_mvwprintw(tela_epilogo, "os ecos que você criou com seus feitos se unem a miragem tornando ela em algo física.", y + 4, mid, 40);




                break;
            }

            break;

        case GENOCIDA:
            slow_mvwprintw(tela_epilogo, "Mantendo sua determinação, você empurra lentamente a espada do rei em direção a seu peito esquelético", y, mid, 40);
            slow_mvwprintw(tela_epilogo, "as runas gravadas em sua espada brilham em um fraco azul, conforme a forma atual do rei caído se desfaz lentamente.", y+1, mid, 40);
            tocar_sound_effect("assets/sound_effect/boom.wav");

            slow_mvwprintw(tela_epilogo, "Como se a própria realidade se chocasse, parece que o Intervalo reage a sua voz,", y + 3, mid, 40);
            slow_mvwprintw(tela_epilogo, "os ecos que você criou com seus feitos se unem a miragem tornando ela em algo física.", y + 4, mid, 40);

            break;
    }
    adicionar_ao_ranking(player);

}
