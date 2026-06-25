#define _XOPEN_SOURCE_EXTENDED 1
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ncursesw/ncurses.h>
#include "utils.h"
#include "../objects/Player.h"
#include "../objects/Inventario.h"
#include "../system/Combate.h"
#include "../system/Save.h"
#include <string.h>

char* get_error_message(Exceptions ex)
{
    switch(ex)
    {
        case Exception_AllocationError: return "Falha ao alocar recurso com malloc ou calloc";
        case Exception_KeyError: return "Falha ao acessar chave em um hashmap";
        case Exception_NotImplementedError: return "Falha, função não implementada";
        case Exception_FileReadWriteError: return "Falha, erro ao ler arquivo do sprite";
        case Exception_IndexError: return "Falha ao acessar indice de array";
        case Exception_OverflowError: return "Falha ao realizar operação aritmitica, acontecimento de Overflow";
        default: return "Aconteceu um erro:";break;
    }
}

int gerar_rolagem_dano()
{

    return (rand()%20 + 1);
}

int gerar_rolagem_mercy()
{
    //return 100;
    return (rand()%5 + 10);
}
int escolher_ataque()
{
    return rand() % 5;
}
int gerar_chance_de_evasao_do_inimigo()
{

    return (rand() % 100 + 1);
}

void exit_with_error(Exceptions ex)
{
    perror(get_error_message(ex));
    exit(1);
}

void iniciar_cores()
{
    const int STANDARD_BACKGROUND = -1;
    short COLOR_GREY = 17;
    init_color(COLOR_GREY, 500, 500, 500);
    init_pair(COR_TEXTO_MORTE, COLOR_RED, STANDARD_BACKGROUND);
    init_pair(COR_OPCAO_SELECIONADA, COLOR_YELLOW, STANDARD_BACKGROUND);
    init_pair(COR_VIDA, COLOR_RED, STANDARD_BACKGROUND);
    init_pair(COR_NOME_BOSS, COLOR_WHITE, STANDARD_BACKGROUND);
    init_pair(COR_DESTAQUE, COLOR_CYAN, STANDARD_BACKGROUND);
    init_pair(COR_OPCAO_INVALIDA, COLOR_GREY, STANDARD_BACKGROUND);
    init_pair(COR_ATIVO, COLOR_CYAN, STANDARD_BACKGROUND);
}

void desenhar_sprite(WINDOW *win, const char *nome_arquivo, int y_inicial, int x_inicial)
{
    FILE *f = fopen(nome_arquivo, "r");
    if(f==NULL)
        perror(get_error_message(Exception_FileReadWriteError));

    char linha[200];
    int i =0;

    while(fgets(linha, sizeof(linha), f))
    {
        linha[strcspn(linha, "\n")] = '\0';

        mvwprintw(win,y_inicial+i,x_inicial,"%s", linha);
        i+=1;
    }
    fclose(f);
}

void slow_mvwprintw(WINDOW* win, char* fala, const int y, int x, int delay_ms)
{
    wchar_t buffer[1024]={0};
    mbstowcs(buffer, fala, 1024);

    wchar_t temp[2];
    temp[1] = L'\0';

    for(int i=0;fala[i]!=L'\0';i++)
    {
        temp[0] = buffer[i];
        mvwaddwstr(win, y, x + i, temp);
        wrefresh(win);
        napms(delay_ms);
    }
}

void mostrar_tela_morte(Player* player)
{
    WINDOW* tela_morte = newwin(getmaxy(stdscr), getmaxx(stdscr),0,0);

    napms(800);
    tocar_sound_effect("assets/sound_effect/death.wav");
    wattron(tela_morte, COLOR_PAIR(COR_TEXTO_MORTE));
    mvwprintw(tela_morte, 16, 70, "██    ██  ██████  ██    ██     ██████  ██ ███████ ██████  ");
    mvwprintw(tela_morte, 17, 70, " ██  ██  ██    ██ ██    ██     ██   ██ ██ ██      ██   ██");
    mvwprintw(tela_morte, 18, 70, "  ████   ██    ██ ██    ██     ██   ██ ██ █████   ██   ██");
    mvwprintw(tela_morte, 19, 70, "   ██    ██    ██ ██    ██     ██   ██ ██ ██      ██   ██ ");
    mvwprintw(tela_morte, 20, 70, "   ██     ██████   ██████      ██████  ██ ███████ ██████ ");

    wattroff(tela_morte, COLOR_PAIR(COR_TEXTO_MORTE));
    wrefresh(tela_morte);
    napms(6000);

    werase(tela_morte);

    int medida_lembrancas = player->medidor_lembranca[Reaper], indice_dialogo;
    player->medidor_lembranca[Reaper]+=1;

    char *dialogos[] = {
        "Mais um falhando… Terei de te levar de volta ao inicio.",
        "Vejo que falhou de novo. Pretende continuar tentando?",
        "De novo? Você realmente não desiste.",
        "Outra queda… A Torre deve gostar de você.",
        "Você continua voltando. Interessante.",
        "Quantas vezes pretende cair antes de chegar ao topo?",
        "Você já parece diferente de quando chegou aqui.",
        "A maioria teria desistido.",
        "A Torre tira algo de você a cada retorno.",
        "Ainda consegue lembrar por que está subindo?",
        "Olá de novo, %s… Voltando para baixo?"
    };

    if (medida_lembrancas == 0)
        indice_dialogo = 0;
    else if (medida_lembrancas == 1)
        indice_dialogo = 1;
    else if (medida_lembrancas == 2)
        indice_dialogo = 2;
    else if (medida_lembrancas == 3)
        indice_dialogo = 3;
    else if (medida_lembrancas == 4)
        indice_dialogo = 4;
    else if (medida_lembrancas == 5)
        indice_dialogo = 5;
    else if (medida_lembrancas == 6)
        indice_dialogo = 6;
    else if (medida_lembrancas == 7)
        indice_dialogo = 7;
    else if (medida_lembrancas == 8)
        indice_dialogo = 8;
    else if (medida_lembrancas == 9)
        indice_dialogo = 9;
    else
        indice_dialogo = 10;
    desenhar_sprite(tela_morte, "assets/sprites/bosses/reaper.txt",5,15);
    wrefresh(tela_morte);
    napms(1000);
    slow_mvwprintw(tela_morte, dialogos[indice_dialogo], 10, 70, 30);
    wrefresh(tela_morte);
    napms(4000);
    apagar_janela(tela_morte);
    tocar_musica(-1);
    ponto_save(player);
    parar_musica();
}

int calcular_largura_sprite(const char *caminho)
{
    FILE *file = fopen(caminho, "r");
    if (file==NULL) return 0;

    char linha[256];
    int maior = 0;

    while (fgets(linha, sizeof(linha), file))
    {
        int len = strlen(linha);

        // remove o '\n' do final se existir
        if (len > 0 && linha[len - 1] == '\n')
            len--;

        if (len > maior)
            maior = len;
    }

    fclose(file);
    return maior;
}

void apagar_janela(WINDOW* win)
{
    werase(win);
    wrefresh(win);
    delwin(win);
    win=NULL;
}

void gerar_loot(Player* player)
{
    int arma_atual=0;
    int tecla;
    Arma arma1 = gerar_arma_aleatoria(player->NumeroAndar);

    Arma arma2;
    do {
        arma2 = gerar_arma_aleatoria(player->NumeroAndar);
    } while(strcmp(arma1.nome, arma2.nome) == 0);

    Arma arma3;
    do {
        arma3 = gerar_arma_aleatoria(player->NumeroAndar);
    } while(strcmp(arma3.nome, arma1.nome) == 0 || strcmp(arma3.nome, arma2.nome) == 0);

    WINDOW* tela_loot = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    keypad(tela_loot, TRUE);
    wtimeout(tela_loot, 33);
    box(tela_loot, 0, 0);
    desenhar_sprite(tela_loot, "assets/sprites/loot/chest.txt", 5, 1);
    napms(3000);
    tocar_sound_effect("assets/sound_effect/get_item.wav");

    Arma armas[3] = {arma1, arma2, arma3};
    while(true)
    {
        werase(tela_loot);
        box(tela_loot, 0, 0);
        desenhar_sprite(tela_loot, "assets/sprites/loot/chest.txt", 5,1);


        for(int i=0;i<3;i++)
        {
            if(arma_atual==i)
                wattron(tela_loot, COLOR_PAIR(COR_OPCAO_SELECIONADA));

            desenhar_sprite(tela_loot, armas[i].sprite,5,22+31*i);
            wattroff(tela_loot, COLOR_PAIR(COR_OPCAO_SELECIONADA));

            mvwprintw(tela_loot, getmaxy(tela_loot) - 8, 22 + 35 * i, "Dano: %d", armas[i].dano);
            mvwprintw(tela_loot, getmaxy(tela_loot) - 7, 22 + 35 * i, "Defesa: %d", armas[i].atributosarma.defesa);
            mvwprintw(tela_loot, getmaxy(tela_loot) - 6, 22 + 35 * i, "Força: %d", armas[i].atributosarma.forca);
            mvwprintw(tela_loot, getmaxy(tela_loot) - 5, 22 + 35 * i, "Sorte: %d", armas[i].atributosarma.sorte);
            mvwprintw(tela_loot, getmaxy(tela_loot) - 4, 22 + 35 * i, "Vida: %d", armas[i].vida);
            wattron(tela_loot, COLOR_PAIR(COR_DESTAQUE));

            mvwprintw(tela_loot, getmaxy(tela_loot) - 3, 6, "Aperte BACKSPACE para manter a arma atual");
            wattroff(tela_loot, COLOR_PAIR(COR_DESTAQUE));
        }
        wrefresh(tela_loot);

        tecla = wgetch(tela_loot);
        if(tecla==KEY_ENTER || tecla == '\n' || tecla==10)
        {

            player->inventario.arma=armas[arma_atual];
            break;
        }
        else if(tecla==KEY_BACKSPACE)
            break;

        if(tecla=='1') arma_atual=0;
        else if(tecla=='2')arma_atual=1;
        else if(tecla=='3')arma_atual=2;
    }
    apagar_janela(tela_loot);
}
void swap(EntradaRanking *a, EntradaRanking *b)
{
    EntradaRanking temp = *a;
    *a = *b;
    *b=temp;
}

void selection_sort(EntradaRanking entries[], int len)
{
  for(int i=0;i<len;i++)
  {
    int min_idx=i;
    for(int j=i+1;j<len;j++)
    {
        if(entries[j].num_mortes<entries[min_idx].num_mortes)
            min_idx=j;
    }
    swap(&entries[i],&entries[min_idx]);
  }  
}