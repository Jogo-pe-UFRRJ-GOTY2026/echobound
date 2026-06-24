#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "objects/Player.h"
#include "chapters/CAPITULO.h"
#include "system/Save.h"
#include "utils/utils.h"
#include "system/Combate.h"

#include <time.h>
#include <stdlib.h>

// make :  compila o codigo
// make run : roda o codigo
// make clean: exclui o executavel e limpa o terminal
Player *menu_inicial();

int main()
{
    setlocale(LC_ALL, ""); // Permite printar caracteres unicode
    srand(time(NULL)); //randomiza a seed do jogo.

    Player *player;
    int AndarSalvo;

    initscr();
    cbreak();               // le a tecla sem precisar do enter
    noecho();               // a tecla digitada é lida mas nao aparece no terminal
    keypad(stdscr, TRUE);   // libera as teclas especiais e as setinhas
    curs_set(0);            //
    nodelay(stdscr, FALSE); //  configura a tela padrão do ncurses (stdscr) para input nao bloqueante
    // timeout(50);              // Usar timeout(50) configura getch() para esperar 50 milisegundos. Se nenhuma tecla é apertada em 50ms, getch() returna ERR.
    start_color(); // iniciliaza cores para aplicação
    use_default_colors();

    iniciar_cores(); // Inicializa os pares de cores definidos na funcao

    
    tocar_musica(-1);
    player = menu_inicial();
    parar_musica();
    if(player==NULL)
    {
        endwin();
        perror("Jogo encerrado");
        return 1;
    }

    while(player->NumeroAndar!=Epilogo)
    {
        Andar andar_anterior = player->NumeroAndar;

        switch(player->NumeroAndar)
        {
            
            case Andar0:
                Prologo_pt2(player);
                break;

            case Andar1:
                Capitulo1(player);
                break;

            case Andar2:
                Capitulo2(player);
                break;

            case Andar3:
                Capitulo3(player);
                break;

            case Andar4:
                Capitulo4(player);
                break;

            case Andar5:
                Capitulo5(player);
                break;
                
            default:
                break;
        }
        // se ele avançou de andar, ele desce e vai pro ponto de save descansar
        // se não avançou, o capitulo faz save automatico e mostra a tela de morte
        // o loop continua no mesmo capitulo
        if(player->NumeroAndar > andar_anterior && player->NumeroAndar != Epilogo) 
        {
            flashbacks(player);
            gerar_loot(player);
            player->vida = vida_max_total(player);
            
            tocar_musica(-1);
            ponto_save(player);
            parar_musica();
        }

    }

    endwin();
    return 0;
}

Player* menu_inicial()
{
    Player *player;
    int tecla;
    int altura_tela, largura_tela;
    getmaxyx(stdscr, altura_tela, largura_tela); // retornam o comprimento e largura maxima do terminal no momento, respectivamente o maximo de linhas e colunas da matriz

    WINDOW *menu_win = newwin(altura_tela, largura_tela, 0, 0); // As duas ultimas coordenadas sao as de inicio, ou seja, o inicio da matriz[0][0]
    keypad(menu_win, TRUE);                                     // habilita as setinhas na tela do menu
    char *opcoes[TOTAL_OPCOES] = {"Iniciar Novo Jogo", "Continuar Jogo Salvo", "Abrir Ranking", "Créditos", "Fechar Jogo"};

    opcao_selecionada selecionada = INICIAR_JOGO_NOVO;

    const int MENU_Y = 12;
    const int ESPACAMENTO_ENTRE_OPCOES = 2;

    // Loop de atualização do estado do menu
    while (true)
    {
        werase(menu_win); // limpa a matriz para nao ficar poluida
        int titulo_largura = 70;
        int TITULO_X = (largura_tela - titulo_largura) / 2;

        mvwprintw(menu_win, 2, TITULO_X, "███████╗ ██████╗██╗  ██╗ ██████╗ ██████╗  ██████╗ ██╗   ██╗███╗   ██╗██████╗ ");
        mvwprintw(menu_win, 3, TITULO_X, "██╔════╝██╔════╝██║  ██║██╔═══██╗██╔══██╗██╔═══██╗██║   ██║████╗  ██║██╔══██╗");
        mvwprintw(menu_win, 4, TITULO_X, "█████╗  ██║     ███████║██║   ██║██████╔╝██║   ██║██║   ██║██╔██╗ ██║██║  ██║");
        mvwprintw(menu_win, 5, TITULO_X, "██╔══╝  ██║     ██╔══██║██║   ██║██╔══██╗██║   ██║██║   ██║██║╚██╗██║██║  ██║");
        mvwprintw(menu_win, 6, TITULO_X, "███████╗╚██████╗██║  ██║╚██████╔╝██████╔╝╚██████╔╝╚██████╔╝██║ ╚████║██████╔╝");
        mvwprintw(menu_win, 7, TITULO_X, "╚══════╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚═════╝ ");

        /* ============================= Imprimindo as opções ===============================================*/
        for (int opcao = 0; opcao < TOTAL_OPCOES; opcao++)
        {
            int y = MENU_Y + (opcao * ESPACAMENTO_ENTRE_OPCOES);
            int x = (largura_tela - strlen(opcoes[opcao])) / 2; // Pegando o centro da tela, relativo ao centro do texto, nao questione o calculo

            if (opcao == selecionada)
            {
                wattron(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD); // Ativa um atributo na janela passada, nesse caso, a cor e o negrito
                mvwprintw(menu_win, y, x - 6, "➢");                            // 6 Caracteres antes do texto
                mvwprintw(menu_win, y, x - 2, "⦗");                            // 2 Caracteres antes do texto
                mvwprintw(menu_win, y, x, "%s", opcoes[opcao]);
                mvwprintw(menu_win, y, x + strlen(opcoes[opcao]), " ⦘");                             // 2 Caracteres antes do texto
                wattroff(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD); // Desativa um atributo na janela passada, nesse caso, a cor e o negrito
            }
            else
            {
                mvwprintw(menu_win, y, x, "%s", opcoes[opcao]);
            }
        }
        wrefresh(menu_win); // Atualiza a tela com as opções

        tecla = wgetch(menu_win); // pega o caracter
        switch (tecla)
        {
        case KEY_UP:
            if (selecionada == INICIAR_JOGO_NOVO)
            {
                selecionada = FECHAR_JOGO;
            }
            else
            {
                selecionada -= 1;
            }
            break;

        case KEY_DOWN:
            if (selecionada == FECHAR_JOGO)
            {
                selecionada = INICIAR_JOGO_NOVO;
            }
            else
            {
                selecionada += 1;
            }
            break;

        case 10: // Dependendo do sistema ou teclado ou sla, o enter pode retornar 10
        case KEY_ENTER:
            switch (selecionada)
            {
            case INICIAR_JOGO_NOVO:
                delwin(menu_win);
                player = Prologo_pt1();

                return player;
            case CONTINUAR_JOGO:
                player = carregar_salvamento();
                if(player==NULL)
                {
                    char aviso_carregamento[] = "《 Arquivo de salvamento excluido, corrompido ou inexistente 》";
                    wattron(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);
                    mvwprintw(menu_win, altura_tela - 10, (largura_tela - strlen(aviso_carregamento)) / 2, "%s", aviso_carregamento);

                    wattroff(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);
                    wrefresh(menu_win);

                    napms(2000); // espera dois segundos
                    selecionada = INICIAR_JOGO_NOVO;
                    break;
                }
                else
                    return player;
            case RANKING:
                werase(menu_win);
                wrefresh(menu_win);
                visualizar_ranking(menu_win);

                break;
            case CREDITOS:
                char aviso_configuracoes[] = "《 Feito por: Pablo Torres, Gustavo Procopio e Pedro Lucas 》";
                char creditos_extras[] = "《 Música feita por: Matheus de Melo, Laine Chinensy, Shadow of Io 》";
                wattron(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);

                mvwprintw(menu_win, altura_tela - 12, largura_tela / 2 -20, "%s", aviso_configuracoes);
                mvwprintw(menu_win, altura_tela - 10, largura_tela / 2 -20, "%s", creditos_extras);

                wattroff(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);
                wrefresh(menu_win);

                napms(2000); // espera meio segundo
                selecionada = INICIAR_JOGO_NOVO;

                break;

            case FECHAR_JOGO:

                wattron(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);

                for (int i = 3; i >= 1; i--) {
                    char aviso_encerramento[50];
                    sprintf(aviso_encerramento, "《 Fechando jogo em %d segundos 》", i);

                    // limpa a linha anterior
                    wmove(menu_win, altura_tela - 10, 0); //reposiciona o cursor
                    wclrtoeol(menu_win);                  //apaga do cursor ate o fim da lina end of line

                    // imprime centralizado
                    mvwprintw(menu_win, altura_tela - 10, (largura_tela - strlen(aviso_encerramento)) / 2, "%s", aviso_encerramento);

                    wrefresh(menu_win);

                    napms(1000);
                }

                wattroff(menu_win, COLOR_PAIR(COR_OPCAO_SELECIONADA) | A_BOLD);

                delwin(menu_win);
                endwin();

                return NULL;
            default:
                break;
            }

            break;
        }
    }

    delwin(menu_win);
}