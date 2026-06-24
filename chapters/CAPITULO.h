#ifndef CAPITULO_H
#define CAPITULO_H

#include "../objects/Player.h"
#include <stdbool.h>

typedef enum Finais
{
    GENOCIDA,
    PACIFISTA,
    NEUTRO
} FinalRealizado;

typedef enum Andar_
{
    Andar0,
    Andar1,
    Andar2,
    Andar3,
    Andar4,
    Andar5,
    Epilogo,
} Andar;

Player *Tela_criacao();
Player *Prologo_pt1();
void Prologo_pt2(Player *player);
bool Capitulo1(Player *player);
bool Capitulo2(Player *player);
bool Capitulo3(Player *player);
bool Capitulo4(Player *player);
bool Capitulo5(Player *player);
void Ver_Epilogo(Player *player);
void flashbacks(Player *player);



#endif