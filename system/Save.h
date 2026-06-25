#ifndef SAVE_H
#define SAVE_H

#include <stdbool.h>
#include <ncurses.h>
#include "../objects/Player.h"
#include "../chapters/CAPITULO.h"

typedef struct entradaRanking_{
    char pl_nome[50];
    int num_mortes;
    FinalRealizado final;
} EntradaRanking;

Player* carregar_salvamento();
bool salvar_jogo(Player* player);
void ponto_save(Player *player);
void adicionar_ao_ranking(Player *pl);
void visualizar_ranking(WINDOW* win);
void testando_ranking();

#endif