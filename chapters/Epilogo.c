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



void Ver_Epilogo(Player *player)
{
    FinalRealizado fim;

    if(player->karma>5)
        fim=PACIFISTA;
    else if(player->karma>0)
        fim=NEUTRO;
    else
        fim=GENOCIDA;



    switch(fim)
    {
        case PACIFISTA:

        break;

        case NEUTRO:

        break;

        case GENOCIDA:
        
        break;
    }
    adicionar_ao_ranking(player);

}
