#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include "CAPITULO.h"
#include "../objects/Player.h"
#include "../utils/utils.h"
#include "../system/Save.h"
#include "../system/Combate.h"

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

    mvwprintw(tela_epilogo, 32, max_x / 2 - 20, "E quanto a agora? Qual decisão pretende tomar?");

    int tecla;
    selecao atual=MATAR;
    estado_rei res=MORTO;
    while(true)
    {
        tecla = wgetch(tela_epilogo);

        if(atual==MATAR)
            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));
        mvwprintw(tela_epilogo, 34, max_x / 2 - 23, "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜"); 
        mvwprintw(tela_epilogo, 35, max_x / 2 - 23, "▌   Eliminar   ▐"); 
        mvwprintw(tela_epilogo, 36, max_x / 2 - 23, "▌    o rei     ▐"); 
        mvwprintw(tela_epilogo, 37, max_x / 2 - 23, "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟");
        if (atual == MATAR)
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));

        if (atual == POUPAR)
            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));

        mvwprintw(tela_epilogo, 34, max_x / 2 + 13, "▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜");
        mvwprintw(tela_epilogo, 35, max_x / 2 + 13, "▌    Prestar   ▐");
        mvwprintw(tela_epilogo, 36, max_x / 2 + 13, "▌   clemência  ▐");
        mvwprintw(tela_epilogo, 37, max_x / 2 + 13, "▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟");
        if (atual == POUPAR)
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_OPCAO_SELECIONADA));
        

        if (tecla == '1') 
            atual=MATAR;
        else if(tecla=='2') 
        {
            atual=POUPAR;
        }
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
            break;
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
    int mid = max_x / 2 - 40;

    char indicador_nome[50];
    char fala_rei[100];
    char fala_vigia[100];
    snprintf(indicador_nome, 50, "[%s]", player->nome);
    snprintf(fala_rei, 50, "Até mais, %s.", player->nome);
    snprintf(fala_vigia, 50, "%s? O que você ainda está fazendo aqui?", player->nome);

    switch(fim)
    {
        case PACIFISTA:

            slow_mvwprintw(tela_epilogo, "[Rei Caído]", y, mid, 40);
            slow_mvwprintw(tela_epilogo, "Vejo que seu coração é movido por algo além de puro desejo e ambição,", y + 1, mid, 40);
            slow_mvwprintw(tela_epilogo, "carregando bondade que não tive em vida.", y + 2, mid, 40);
            slow_mvwprintw(tela_epilogo, "Notas algo diferente em si com isto?", y + 3, mid, 40);

            slow_mvwprintw(tela_epilogo, indicador_nome, y + 5, mid, 40);
            slow_mvwprintw(tela_epilogo, "Acho que sim, me sinto mais... completo,", y + 6, mid, 40);
            slow_mvwprintw(tela_epilogo, "como se tivesse recuperado algo.", y + 7, mid, 40);

            slow_mvwprintw(tela_epilogo, "Você nota que, ao seu lado, como se o Intervalo respondesse", y + 9, mid, 40);
            slow_mvwprintw(tela_epilogo, "a seu esforço prévio, uma pequena fissura se abre no ar,", y + 10, mid, 40);
            slow_mvwprintw(tela_epilogo, "revelando partes do reino da Província Emerita.", y + 11, mid, 40);

            slow_mvwprintw(tela_epilogo, "[Rei Caído]", y + 13, mid, 40);
            slow_mvwprintw(tela_epilogo, "Bem, você deve ter marcado muitas pessoas por aqui com seus feitos.", y + 14, mid, 40);
            slow_mvwprintw(tela_epilogo, "Mas... essa fissura... isso é uma novidade...", y + 15, mid, 40);
            slow_mvwprintw(tela_epilogo, "Pretende tentar passar?", y + 16, mid, 40);

            slow_mvwprintw(tela_epilogo, indicador_nome, y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "Acho que não. Talvez eu possa ficar aqui...", y + 19, mid, 40);
            slow_mvwprintw(tela_epilogo, "Bem, acho que vou descer agora.", y + 20, mid, 40);
            slow_mvwprintw(tela_epilogo, "Se lembre de tomar conta do Cerberus,", y + 21, mid, 40);
            slow_mvwprintw(tela_epilogo, "ele sente sua falta!", y + 22, mid, 40);

            slow_mvwprintw(tela_epilogo, "Um sorriso transparece pelo rosto esquelético do Rei Caído.", y + 24, mid, 40);

            slow_mvwprintw(tela_epilogo, "[Rei Caído]", y + 26, mid, 40);
            slow_mvwprintw(tela_epilogo, fala_rei, y + 27, mid, 40);
            werase(tela_epilogo);
            napms(2500);

            slow_mvwprintw(tela_epilogo, "[Vigia]", y, mid, 40);
            slow_mvwprintw(tela_epilogo, fala_vigia, y + 1, mid, 40);
            slow_mvwprintw(tela_epilogo, "Recebi a informação da derrota do Rei Caído,", y + 2, mid, 40);
            slow_mvwprintw(tela_epilogo, "derrotado por você.", y + 3, mid, 40);
            slow_mvwprintw(tela_epilogo, "Por que você não voltou para a vida", y + 4, mid, 40);
            slow_mvwprintw(tela_epilogo, "que tanto queria recuperar?", y + 5, mid, 40);

            slow_mvwprintw(tela_epilogo, indicador_nome, y + 7, mid, 40);
            slow_mvwprintw(tela_epilogo, "Acho que talvez algumas coisas sejam melhores", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "do jeito que estão.", y + 9, mid, 40);
            slow_mvwprintw(tela_epilogo, "Depois de tanto tempo aqui,", y + 10, mid, 40);
            slow_mvwprintw(tela_epilogo, "talvez não seja necessário voltar.", y + 11, mid, 40);
            slow_mvwprintw(tela_epilogo, "Talvez eu possa ajudar outras almas por aqui...", y + 12, mid, 40);
            slow_mvwprintw(tela_epilogo, "Assim como você me ajudou.", y + 13, mid, 40);
            slow_mvwprintw(tela_epilogo, "Posso guiar os viajantes que desejam subir a Torre,", y + 14, mid, 40);
            slow_mvwprintw(tela_epilogo, "assim como você?", y + 15, mid, 40);

            slow_mvwprintw(tela_epilogo, "[Vigia]", y + 17, mid, 40);
            slow_mvwprintw(tela_epilogo, "Claro, por que não poderia?", y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "É mais divertido e interessante do que ficar", y + 19, mid, 40);
            slow_mvwprintw(tela_epilogo, "perambulando por aí,", y + 20, mid, 40);
            slow_mvwprintw(tela_epilogo, "e no fim você acaba trazendo conforto e companhia", y + 21, mid, 40);
            slow_mvwprintw(tela_epilogo, "para mais almas do que imagina.", y + 22, mid, 40);

            napms(1200);

            werase(tela_epilogo);
            wrefresh(tela_epilogo);
            napms(1700);

            mvwprintw(tela_epilogo, y+1, mid, "██████ ▄▄ ▄▄  ▄▄  ▄▄▄  ▄▄      █████▄  ▄▄▄   ▄▄▄▄ ▄▄ ▄▄▄▄▄ ▄▄  ▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄");
            mvwprintw(tela_epilogo, y+2, mid, "██▄▄   ██ ███▄██ ██▀██ ██      ██▄▄█▀ ██▀██ ██▀▀▀ ██ ██▄▄  ██ ███▄▄   ██  ██▀██");
            mvwprintw(tela_epilogo, y+3, mid, "██     ██ ██ ▀██ ██▀██ ██▄▄▄   ██     ██▀██ ▀████ ██ ██    ██ ▄▄██▀   ██  ██▀██");

            slow_mvwprintw(tela_epilogo, "Ao alcançar o topo da Torre, você decide não sair.", y + 5, mid, 40);
            slow_mvwprintw(tela_epilogo, "Seus atos ao longo da subida deixam marcas profundas", y + 6, mid, 40);
            slow_mvwprintw(tela_epilogo, "nas almas que encontrou pelo caminho.", y + 7, mid, 40);
            slow_mvwprintw(tela_epilogo, "Por ter sido lembrado por aqueles que poupou e ajudou,", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "você decide ajudar todos a completarem sua jornada.", y + 9, mid, 40);
            slow_mvwprintw(tela_epilogo, "Você desce as escadas e comunica essa decisão ao Vigia.", y + 10, mid, 40);

            napms(5000);

            break;

        case NEUTRO:

            if(res==MORTO) // por que tipo, o player pode ter matado  o rei e cair no final neutro
            {
                slow_mvwprintw(tela_epilogo, "Mantendo sua determinação, você empurra lentamente a espada do rei em direção a seu peito esquelético", y, mid, 40);
                slow_mvwprintw(tela_epilogo, "as runas gravadas em sua espada brilham em um fraco azul, conforme a forma atual do rei caído se desfaz lentamente.", y + 1, mid, 40);

                slow_mvwprintw(tela_epilogo, "O topo da Torre permanece em silêncio.", y + 3, mid, 40);
            }
            else // ou o jogador poupou o rei caido
            {
                mvwprintw(tela_epilogo, y, mid, "[Rei Caído]");
                slow_mvwprintw(tela_epilogo, "Vejo que seu coração é movido por algo além de puro desejo e ambição, carregando bondade que não tive em vida", y+1, mid, 40);
                slow_mvwprintw(tela_epilogo, "Notas algo diferente em si com isto?.", y + 2, mid, 40);
                slow_mvwprintw(tela_epilogo, "As paredes da Torre começam a tremer após o questionamento do Rei Caído.", y + 5, mid, 40);
            }


            slow_mvwprintw(tela_epilogo, "Fragmentos de lembranças escapam de seu corpo como pequenas partículas de luz.", y + 7, mid, 40);
            slow_mvwprintw(tela_epilogo, "Rostos de aliados, nomes de pessoas que encontrou pelo caminho", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "e momentos que moldaram sua jornada surgem diante de seus olhos uma última vez.", y + 9, mid, 40);

            napms(1200);

            slow_mvwprintw(tela_epilogo, "Um clarão atravessa o céu do Intervalo.", y + 12, mid, 40);

            slow_mvwprintw(tela_epilogo, "Por um breve instante, você consegue enxergar simultaneamente os dois mundos.", y + 14, mid, 40);
            slow_mvwprintw(tela_epilogo, "De um lado, a Província Emerita, marcada por anos de repressão e conformismo.", y + 15, mid, 40);
            slow_mvwprintw(tela_epilogo, "Do outro, a Terra, o lugar ao qual você pertence.", y + 16, mid, 40);

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_epilogo, "A fissura se abre.", y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "Você dá um passo à frente.", y + 19, mid, 40);
            slow_mvwprintw(tela_epilogo, "Mas algo fica para trás.", y + 20, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

            napms(1200);

            slow_mvwprintw(tela_epilogo, "As memórias que faltavam para completar sua travessia", y + 23, mid, 40);
            slow_mvwprintw(tela_epilogo, "são arrancadas de sua mente e absorvidas pela própria Torre.", y + 24, mid, 40);
            slow_mvwprintw(tela_epilogo, "As imagens diante de você se desfazem pouco a pouco,", y + 25, mid, 40);
            slow_mvwprintw(tela_epilogo, "até que restam apenas sensações impossíveis de explicar.", y + 26, mid, 40);

            slow_mvwprintw(tela_epilogo, "Então, tudo desaparece.", y + 28, mid, 40);
            werase(tela_epilogo);
            wrefresh(tela_epilogo);
            napms(2000);

            slow_mvwprintw(tela_epilogo, "Você desperta exatamente onde sua história havia terminado.", y, mid, 40);

            slow_mvwprintw(tela_epilogo, "O mundo continua seguindo seu curso, indiferente à sua ausência.", y + 2, mid, 40);
            slow_mvwprintw(tela_epilogo, "As lembranças da Torre são vagas, incompletas e fragmentadas.", y + 3, mid, 40);
            slow_mvwprintw(tela_epilogo, "Você sabe que esteve em algum lugar.", y + 4, mid, 40);
            slow_mvwprintw(tela_epilogo, "Sabe que lutou por algo, mas não consegue recordar os detalhes.", y + 5, mid, 40);

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_epilogo, "Ainda assim, existe uma certeza que nenhuma falha", y + 7, mid, 40);
            slow_mvwprintw(tela_epilogo, "em sua memória conseguiu apagar.", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "A Província Emerita precisa mudar.", y + 9, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

            napms(1200);

            slow_mvwprintw(tela_epilogo, "Movido por essa convicção inexplicável,", y + 10, mid, 40);
            slow_mvwprintw(tela_epilogo, "você une forças com aqueles que também desejam um futuro diferente.", y + 11, mid, 40);
            slow_mvwprintw(tela_epilogo, "Ideias antes esquecidas voltam a circular entre a população.", y + 12, mid, 40);
            slow_mvwprintw(tela_epilogo, "Pela primeira vez em muitos anos,", y + 13, mid, 40);
            slow_mvwprintw(tela_epilogo, "o povo volta a acreditar que pode desafiar aqueles que o governam.", y + 14, mid, 40);

            slow_mvwprintw(tela_epilogo, "A palavra \"revolução\" retorna aos sussurros das ruas.", y + 15, mid, 40);

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            slow_mvwprintw(tela_epilogo, "Você não se lembra de como aprendeu essa lição.", y + 16, mid, 40);
            slow_mvwprintw(tela_epilogo, "Mas uma parte de você ainda permanece no topo da Torre,", y + 17, mid, 40);
            slow_mvwprintw(tela_epilogo, "ecoando através do Intervalo,", y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "garantindo que jamais a esqueça por completo.", y + 19, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            
            napms(1500);

            werase(tela_epilogo);
            box(tela_epilogo, 0, 0);

            wrefresh(tela_epilogo);
            napms(1700);

            mvwprintw(tela_epilogo, y + 1, mid, "██████ ▄▄ ▄▄  ▄▄  ▄▄▄  ▄▄      ███  ██ ▄▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄▄▄ ▄▄▄▄   ▄▄▄");
            mvwprintw(tela_epilogo, y + 2, mid, "██▄▄   ██ ███▄██ ██▀██ ██      ██ ▀▄██ ██▄▄  ██ ██   ██   ██▄█▄ ██▀██");
            mvwprintw(tela_epilogo, y + 3, mid, "██     ██ ██ ▀██ ██▀██ ██▄▄▄   ██   ██ ██▄▄▄ ▀███▀   ██   ██ ██ ▀███▀");

            slow_mvwprintw(tela_epilogo, "Ao alcançar o topo da Torre, você consegue retornar à Terra,", y + 5, mid, 40);
            slow_mvwprintw(tela_epilogo, "despertando no mesmo lugar de sua morte.", y + 6, mid, 40);

            slow_mvwprintw(tela_epilogo, "Porém, sua travessia acontece de forma incompleta:", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "parte de suas lembranças permanecem presas no Intervalo.", y + 9, mid, 40);
            slow_mvwprintw(tela_epilogo, "Você volta ao mundo dos vivos carregando apenas fragmentos", y + 10, mid, 40);
            slow_mvwprintw(tela_epilogo, "daquilo que viveu, enquanto uma parte de sua existência", y + 11, mid, 40);
            slow_mvwprintw(tela_epilogo, "continua ecoando dentro da Torre.", y + 12, mid, 40);

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_epilogo, "Mas, se existe algo que continua vivo em você,", y + 14, mid, 40);
            slow_mvwprintw(tela_epilogo, "é a sua vontade de mudar positivamente o mundo,", y + 15, mid, 40);
            slow_mvwprintw(tela_epilogo, "contra toda a repressão.", y + 16, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

            napms(1200);

            slow_mvwprintw(tela_epilogo, "Você une forças para convencer a população a iniciar", y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "uma nova revolução, palavra esquecida há anos pelos", y + 19, mid, 40);
            slow_mvwprintw(tela_epilogo, "cidadãos da Província Emerita, contra o rei vigente Atlas,", y + 20, mid, 40);
            slow_mvwprintw(tela_epilogo, "do qual você não tem nenhuma memória do passado relacionada a ele.", y + 21, mid, 40);

            napms(5000);
            break;

        case GENOCIDA:
            slow_mvwprintw(tela_epilogo, "Mantendo sua determinação, você empurra lentamente a espada do rei em direção a seu peito esquelético", y, mid, 40);
            slow_mvwprintw(tela_epilogo, "as runas gravadas em sua espada brilham em um fraco azul, conforme a forma atual do rei caído se desfaz lentamente.", y+1, mid, 40);
            tocar_sound_effect("assets/sound_effect/boom.wav");
            napms(1200);
            slow_mvwprintw(tela_epilogo, "Como se a própria realidade se chocasse, parece que o Intervalo reage a sua voz,", y + 3, mid, 40);
            slow_mvwprintw(tela_epilogo, "os ecos que você criou com seus feitos se unem a miragem tornando ela em algo física.", y + 4, mid, 40);

            slow_mvwprintw(tela_epilogo, "Como num momento de claridade, suas memórias de vida se tornam mais claras, e num feixe de luz branca que irrompe do topo da Torre,", y + 5, mid, 40);
            slow_mvwprintw(tela_epilogo, "você consegue ver o seu mundo anterior e o reino da Província Emerita.", y + 6, mid, 40);
            slow_mvwprintw(tela_epilogo, "Você visualiza sua mãe, que olha em sua direção e sorri ao ver o filho,", y + 7, mid, 40);
            slow_mvwprintw(tela_epilogo, "e de forma abrupta, tanto seu corpo quanto o dessa pessoa se desfazem em luz…", y + 8, mid, 40);
            napms(1200);


            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_epilogo, "A posição de vocês troca, você consegue ver ela agora em seu lugar no Intervalo,", y + 10, mid, 40);
            slow_mvwprintw(tela_epilogo, "e a fissura na realidade se fecha, você está de volta, mas a que preço…", y + 11, mid, 40);

            slow_mvwprintw(tela_epilogo, "Você está de volta em casa, sua mãe está no Intervalo,", y + 12, mid, 40);
            slow_mvwprintw(tela_epilogo, "de onde dificilmente conseguiria sair…", y + 13, mid, 40);
            napms(1200);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            slow_mvwprintw(tela_epilogo, "O governo do reino ainda estaria na mesma situação, com uma troca de seis por meia dúzia,", y + 15, mid, 40);
            slow_mvwprintw(tela_epilogo, "e no fim, que influência positiva você realmente trouxe ao mundo?", y + 16, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            napms(1500);

            werase(tela_epilogo);
            box(tela_epilogo, 0, 0);
            wrefresh(tela_epilogo);
            napms(1700);

            mvwprintw(tela_epilogo, y+1, mid, "██████ ▄▄ ▄▄  ▄▄  ▄▄▄  ▄▄       ▄████  ▄▄▄▄▄ ▄▄  ▄▄  ▄▄▄   ▄▄▄▄ ▄▄ ▄▄▄▄   ▄▄▄");
            mvwprintw(tela_epilogo, y+2, mid, "██▄▄   ██ ███▄██ ██▀██ ██      ██  ▄▄▄ ██▄▄  ███▄██ ██▀██ ██▀▀▀ ██ ██▀██ ██▀██");
            mvwprintw(tela_epilogo, y+3, mid, "██     ██ ██ ▀██ ██▀██ ██▄▄▄    ▀███▀  ██▄▄▄ ██ ▀██ ▀███▀ ▀████ ██ ████▀ ██▀██");

            slow_mvwprintw(tela_epilogo, "Ao alcançar o topo da Torre, você consegue retornar à Terra,", y + 5, mid, 40);
            slow_mvwprintw(tela_epilogo, "despertando novamente em sua casa.", y + 6, mid, 40);

            slow_mvwprintw(tela_epilogo, "Porém, sua fuga exige um preço.", y + 8, mid, 40);
            slow_mvwprintw(tela_epilogo, "A única pessoa que ainda se lembrava de você,", y + 9, mid, 40);
            slow_mvwprintw(tela_epilogo, "sua mãe, é enviada ao Intervalo em seu lugar.", y + 10, mid, 40);

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_epilogo, "Você escapa, mas às custas de substituir", y + 12, mid, 40);
            slow_mvwprintw(tela_epilogo, "sua própria ausência pela de alguém", y + 13, mid, 40);
            slow_mvwprintw(tela_epilogo, "que nunca havia lhe esquecido.", y + 14, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

            napms(1200);

            wattron(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            slow_mvwprintw(tela_epilogo, "E no fim, você apenas contribuiu para", y + 16, mid, 40);
            slow_mvwprintw(tela_epilogo, "uma troca vazia de poder,", y + 17, mid, 40);
            slow_mvwprintw(tela_epilogo, "alimentando ainda mais guerra e conflito.", y + 18, mid, 40);
            slow_mvwprintw(tela_epilogo, "Que influência positiva você realmente trouxe ao mundo?", y + 20, mid, 40);
            wattroff(tela_epilogo, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
            napms(5000);
            break;
    }
    adicionar_ao_ranking(player);
    delwin(tela_epilogo);
}

