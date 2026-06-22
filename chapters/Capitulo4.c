#include <stdbool.h>
#include <ncurses.h>
#include <string.h>
#include "CAPITULO.h"
#include "../objects/Player.h"
#include "../objects/Inimigo.h"
#include "../objects/Inventario.h"
#include "../system/Combate.h"
#include "../utils/utils.h"
#include "../system/Save.h"

bool Capitulo4(Player *player)
{
    WINDOW *tela_capitulo4 = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    box(tela_capitulo4, 0, 0);
    wrefresh(tela_capitulo4);

    // -------------------------- Descrição do Cenário
    slow_mvwprintw(tela_capitulo4, "Você abre a penúltima porta antes da chegada ao topo, um cheiro forte penetra suas narinas, e uma nuvem de cinzas levanta no ar.", 10, 6, 20);
    slow_mvwprintw(tela_capitulo4, "A parede desse andar está danificada, e queimando com chamas incessantes", 11, 6, 20);
    slow_mvwprintw(tela_capitulo4, "que parecem que não se extinguem a séculos e impossibilitam qualquer passagem ou atalho", 12, 6, 20);
    slow_mvwprintw(tela_capitulo4, "no meio do salão em meio a uma pilha de moedas repousa um dragão dormindo,", 13, 6, 20);
    slow_mvwprintw(tela_capitulo4, "", 14, 6, 20);

    napms(2500);

    werase(tela_capitulo4);
    box(tela_capitulo4, 0, 0);

    // Renderiza o sprite do Dragão
    desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon_sleeping.txt", 1, 5);

    slow_mvwprintw(tela_capitulo4, "Conforme você dá seu próximo passo parece que o ar se torna mais tenso e pesado e o chão treme levemente.", 31, 6, 20);
    slow_mvwprintw(tela_capitulo4, "e ele desperta.", 32, 6, 20);

    napms(2000);

    // -------------------------- Diálogo Condicional
    if (player->medidor_lembranca[Iowa] < 1)
    {
        const char *opcoes_dialogo[3] = {
            "1. Um dragão?? O que te trouxe até o alto da torre?",
            "2. Você também deseja sair? Ser lembrado",
            "3. Eu ainda preciso subir."
        };

        int ja_realizou_pergunta[3] = {0};
        int opcao = 0;

        while (true)
        {
            werase(tela_capitulo4);
            box(tela_capitulo4, 0, 0);
            desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon.txt", 1, 5);

            // Menu de Opções
            for (int i = 0; i < 3; i++)
            {
                if (ja_realizou_pergunta[i])
                    wattron(tela_capitulo4, COLOR_PAIR(COR_OPCAO_INVALIDA));

                mvwprintw(tela_capitulo4, 31 + i, 6, opcoes_dialogo[i]);

                wattrset(tela_capitulo4, A_NORMAL);
            }

            wattron(tela_capitulo4, COLOR_PAIR(COR_DESTAQUE));
            mvwprintw(tela_capitulo4, getmaxy(tela_capitulo4) - 3, 4, "Pressione ENTER para iniciar o combate");
            wattroff(tela_capitulo4, COLOR_PAIR(COR_DESTAQUE));

            wrefresh(tela_capitulo4);

            int tecla = wgetch(tela_capitulo4);

            if (tecla == '1')
                opcao = 0;
            if (tecla == '2')
                opcao = 1;
            if (tecla == '3')
                opcao = 2;

            if (tecla == KEY_ENTER || tecla == '\n' || tecla == 10)
            {
                opcao = 2; // Força a opção de combate/passagem direta
            }

            if (!ja_realizou_pergunta[opcao])
            {
                ja_realizou_pergunta[opcao] = 1;

                werase(tela_capitulo4);
                box(tela_capitulo4, 0, 0);
                desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon.txt", 1, 5);

                mvwprintw(tela_capitulo4, 29, 6, "[Iowa]");

                if (opcao == 0)
                {
                    slow_mvwprintw(tela_capitulo4, "Sou Iowa, uma entidade primordial do Intervalo.", 30, 6, 20);
                    slow_mvwprintw(tela_capitulo4, "Em verdade, já não me recordo os caminhos que me trouxeram a este lugar.",31,6,20);
                    slow_mvwprintw(tela_capitulo4, "Contudo, recordo-me de ti,",32,6,20);
                    slow_mvwprintw(tela_capitulo4, player->nome, 32, 33, 20);
                    slow_mvwprintw(tela_capitulo4, ", assim como de inúmeras almas que vagaram por este espaço ao longo das eras.", 32, 33+strlen(player->nome), 20);
                }
                else if (opcao == 1)
                {
                    slow_mvwprintw(tela_capitulo4, "Outrora contemplei a possibilidade de atravessar outros reinos e horizontes.", 30, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "Entretanto, com o passar dos milênios, encontrei contentamento neste lugar.", 31, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "Quando se testemunha o transcurso de incontáveis eras, aprende-se que a solitude nem sempre é uma maldição,", 32, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "e o repouso torna-se um conforto raro.", 33, 6, 30);
                    napms(2000);
                }
                else if (opcao == 2)
                {
                    slow_mvwprintw(tela_capitulo4, "Então prossiga em tua ascensão. Contudo, não te concederei passagem sem provação", 30, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "Estas chamas não se curvam aos fracos; apenas aqueles dotados da força necessária podem atravessá-las.", 31, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "Quando se testemunha o transcurso de incontáveis eras, aprende-se que a solitude nem sempre é uma maldição,", 32, 6, 30);
                    slow_mvwprintw(tela_capitulo4, "E, se tu não fores capaz de superar este obstáculo, tampouco resistirás ao desafio que te aguarda adiante.", 33, 6, 30);                    
                    napms(2000);
                    break; // Sai do loop para iniciar a luta
                }

                wrefresh(tela_capitulo4);
                napms(2500);
            }
        }
    }
    else
    {
        // Caso o Player já tenha enfrentado ele antes
        werase(tela_capitulo4);
        box(tela_capitulo4, 0, 0);
        desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon.txt", 1, 5);

        mvwprintw(tela_capitulo4, 28, 6, "[Iowa]");
        slow_mvwprintw(tela_capitulo4, "Vejo que retornaste… curioso. Poucos escolhem desafiar o fogo uma segunda vez.", 29, 6, 20);

        wrefresh(tela_capitulo4);
        napms(2500);
    }

    // -------------------------- Configuração do Combate
    AtaqueInimigo ataques[] = {
        criar_ataque(BULLET, 8, "🔥", 1, VERTICAL, CIMA_BAIXO, 2, 25),
        criar_ataque(BULLET, 8, "🔥", 1, VERTICAL, BAIXO_CIMA, 2, 25),
        criar_ataque(LINHA, 13, "🔥🔥🔥", 1, HORIZONTAL, ESQUERDA_DIREITA, 2, 25),
        criar_ataque(LASER, 12, "▽", 0, VERTICAL, NAO_IMPORTA, 80, 60),
        criar_ataque(PAREDE, 8, "†", 1, HORIZONTAL, BAIXO_CIMA, 8, 110),
        criar_ataque_area(7, "Λ", 1, 4, 4, 90, 30),
    };

    Sprite_size size;
    size.x = 54;
    size.y = 17;

    Inimigo *iowa = criar_inimigo(305, "Iowa", "assets/sprites/bosses/dragon.txt", size, 35, 23, Iowa);


    // Diálogos de Ataque recebido
    iowa->dialogos_ataque[0] = "Teu golpe carrega força… mas ainda não suficiente.";
    iowa->dialogos_ataque[1] = "Mostra-me mais.";
    iowa->dialogos_ataque[2] = "Mesmo as chamas respeitam aqueles que persistem.";
    iowa->dialogos_ataque[3] = "…Interessantissímo";
    iowa->dialogos_ataque[4] = "Você carrega determinação, não permita que ela se extingua… Prossiga!";

    // Diálogos de Mercy (Piedade)
    iowa->dialogos_mercy[0] = "Recusas o combate… diante de mim?";
    iowa->dialogos_mercy[1] = "Curioso… há força também naquele que escolhe não ferir.";
    iowa->dialogos_mercy[2] = "Talvez tua verdadeira determinação não esteja em tua espada.";

    iowa->numero_ataques = len(ataques);
    for (int i = 0; i < iowa->numero_ataques; i++)
        iowa->ataques[i] = ataques[i];

    werase(tela_capitulo4);
    wrefresh(tela_capitulo4);

    // Execução da luta
    EstadoRodada resultado_combate = iniciar_combate(player, iowa);
    player->medidor_lembranca[Iowa] += 1;
    free_inimigo(iowa);

    // -------------------------- Pós-Combate
    werase(tela_capitulo4);
    box(tela_capitulo4, 0, 0);
    wrefresh(tela_capitulo4);

    if (resultado_combate == VITORIA && iowa->vida <= 0)
    {
        // Roteiro: Derrotado por Ataque
        desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon_defeated.txt", 1, 5);
        mvwprintw(tela_capitulo4, 24, 6, "[Iowa]");
        napms(500);
        slow_mvwprintw(tela_capitulo4, "Então… até mesmo minhas chamas chegaram ao fim…", 25, 6, 35);
        napms(1000);
        slow_mvwprintw(tela_capitulo4, "Vá… sobe enquanto ainda és lembrado.", 26, 6, 35);
        napms(1000);
        adicionar_consumivel(player);
        mvwprintw(tela_capitulo4, 27, 6, "Você ganhou mais um Estus Flask! (%d/%d)", player->consumiveis_max, 5);
        wrefresh(tela_capitulo4);
        napms(1000);
        player->NumeroAndar = Andar5;
    }
    else if (resultado_combate == VITORIA && iowa->vida >= 0)
    {
        // Roteiro: Derrotado por Mercy
        desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon_defeated.txt", 1, 5);
        mvwprintw(tela_capitulo4, 24, 6, "[Iowa]");
        napms(500);
        slow_mvwprintw(tela_capitulo4, "Tu venceste… e ainda assim escolheste poupar-me.", 25, 6, 20);
        napms(1000);
        slow_mvwprintw(tela_capitulo4, "Passe. O caminho ao topo está aberto… minhas chamas não mais te impedirão.", 26, 6, 20);
        napms(1000);
        adicionar_consumivel(player);
        mvwprintw(tela_capitulo4, 27, 6, "Você ganhou mais um Estus Flask! (%d/%d)", player->consumiveis_max, 5);
        wrefresh(tela_capitulo4);
        napms(1000);
        
        player->karma += 1;
        player->NumeroAndar = Andar5;
    }
    else
    {
        // Derrota do Player
        desenhar_sprite(tela_capitulo4, "assets/sprites/bosses/dragon.txt", 1, 5);
        mvwprintw(tela_capitulo4, 24, 6, "[Iowa]");
        napms(500);
        slow_mvwprintw(tela_capitulo4, "Se seu espírito deseja completar a Torre, então se prepare, e tente novamente! Você só passará quando merecer.", 25, 6, 20);
        napms(2000);
        player->vida = vida_max_total(player);
        salvar_jogo(player);
        mostrar_tela_morte(player);
    }

    wrefresh(tela_capitulo4);
    napms(2500);
    apagar_janela(tela_capitulo4);

    return true;
}