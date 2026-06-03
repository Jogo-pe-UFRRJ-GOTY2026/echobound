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

bool Capitulo3(Player *player)
{
    WINDOW *tela_capitulo3 = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    box(tela_capitulo3, 0, 0);
    wrefresh(tela_capitulo3);

    // -------------------------- Descrição do Cenário
    slow_mvwprintw(tela_capitulo3, "Você sobe mais uma sequência de escadas, as gramíneas e vinhas que", 10, 6, 20);
    slow_mvwprintw(tela_capitulo3, "se estendiam do segundo andar até as escadas agora estão aos poucos", 11, 6, 20);
    slow_mvwprintw(tela_capitulo3, "ganhando um tom mais pálido e morto. Conforme você continua sua", 12, 6, 20);
    slow_mvwprintw(tela_capitulo3, "ascensão a ouvir sons animalescos em baixo volume.", 13, 6, 20);

    napms(2500);

    werase(tela_capitulo3);
    box(tela_capitulo3, 0, 0);

    mvwprintw(tela_capitulo3, 10,6,"[???]");
    slow_mvwprintw(tela_capitulo3, "aarff… aua…", 11, 6, 20);

    desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus_with_bone.txt", 1, 5);

    slow_mvwprintw(tela_capitulo3, "No salão do terceiro andar, você se depara com um cão de três", 31, 6, 20);
    slow_mvwprintw(tela_capitulo3, "cabeças, inquieto tentando chegar ao tutano de um longo pedaço de osso", 32, 6, 20);

    napms(2000);

    // -------------------------- Diálogo Condicional
    if (player->medidor_lembranca[Cerberus] < 1)
    {
        const char *opcoes_dialogo[3] = {
            "1. Estender a mão",
            "2. Chamá-lo",
            "3. Levantar sua arma"};

        int ja_realizou_pergunta[3] = {0};
        int opcao = 0;

        while (true)
        {
            werase(tela_capitulo3);
            box(tela_capitulo3, 0, 0);
            desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus.txt", 1, 5);

            // Menu de Opções
            for (int i = 0; i < 3; i++)
            {
                if (ja_realizou_pergunta[i])
                    wattron(tela_capitulo3, COLOR_PAIR(COR_OPCAO_INVALIDA));

                mvwprintw(tela_capitulo3, 31 + i, 6, opcoes_dialogo[i]);

                wattrset(tela_capitulo3, A_NORMAL);
            }

            wattron(tela_capitulo3, COLOR_PAIR(COR_DESTAQUE));
            mvwprintw(tela_capitulo3, getmaxy(tela_capitulo3) - 3, 4, "Pressione ENTER para iniciar o combate");
            wattroff(tela_capitulo3, COLOR_PAIR(COR_DESTAQUE));

            wrefresh(tela_capitulo3);

            int tecla = wgetch(tela_capitulo3);

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

                werase(tela_capitulo3);
                box(tela_capitulo3, 0, 0);
                desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus.txt", 1, 5);

                mvwprintw(tela_capitulo3, 29, 6, "[Cerberus]");

                if (opcao == 0)
                {
                    slow_mvwprintw(tela_capitulo3, "GRRRR… (Cerberus rosna baixo, mas não avança. Seu olhar permanece fixo em você.)", 30, 6, 20);
                    napms(800);
                }
                else if (opcao == 1)
                {
                    slow_mvwprintw(tela_capitulo3, "(Ele ergue a cabeça ao ouvir sua voz. O rosnado diminui por um instante… mas ele não sai do caminho)", 30, 6, 30);
                    napms(800);
                }
                else if (opcao == 2)
                {
                    slow_mvwprintw(tela_capitulo3, "“GRRRR… AUUUF!” (Ele avança para cima de você)", 30, 6, 30);
                    napms(800);
                    break; // Sai do loop para iniciar a luta
                }

                wrefresh(tela_capitulo3);
                napms(2500);
            }
        }
    }
    else
    {
        // Caso o Player já tenha enfrentado ele antes
        werase(tela_capitulo3);
        box(tela_capitulo3, 0, 0);
        desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus.txt", 1, 5);

        mvwprintw(tela_capitulo3, 28, 6, "[Cerberus]");
        slow_mvwprintw(tela_capitulo3, "sniff… sniff… Au… rrr… auuf… Cerberus reconhece seu cheiro. Ele rosna, mas há dúvida em seus movimentos.", 29, 6, 20);

        wrefresh(tela_capitulo3);
        napms(2500);
    }

    // -------------------------- Configuração do Combate
    AtaqueInimigo ataques[] = {
        criar_ataque(BULLET, 8, "🔥", 1, VERTICAL, CIMA_BAIXO, 2, 25),
        criar_ataque(PAREDE, 8, "†", 1, HORIZONTAL, BAIXO_CIMA, 8, 110),
        criar_ataque_area(5, "⮟", 1, 0, 0, 80, 15),
        criar_ataque_area(7, "⮟", 1, 4, 4, 90, 60),
    };

    Sprite_size size;
    size.x = 26;
    size.y = 12;

    Inimigo *cerberus = criar_inimigo(200, "Cerberus", "assets/sprites/bosses/cerberus.txt", size, 35, 23, Cerberus);

    // Diálogos de Ataque recebido
    cerberus->dialogos_ataque[0] = "GRAAAAUF!";
    cerberus->dialogos_ataque[1] = "AUAUAUAU!";
    cerberus->dialogos_ataque[2] = "GRRRR……";
    cerberus->dialogos_ataque[3] = "AUUUF!";
    cerberus->dialogos_ataque[4] = "ROOOARRGH!";

    // Diálogos de Mercy (Piedade)
    cerberus->dialogos_mercy[0] = "Au…";
    cerberus->dialogos_mercy[1] = "Rrr… au au…";
    cerberus->dialogos_mercy[2] = "Whine…";

    cerberus->numero_ataques = len(ataques);
    for (int i = 0; i < cerberus->numero_ataques; i++)
        cerberus->ataques[i] = ataques[i];

    werase(tela_capitulo3);
    wrefresh(tela_capitulo3);

    // Execução da luta
    EstadoRodada resultado_combate = iniciar_combate(player, cerberus);
    player->medidor_lembranca[Cerberus] += 1;

    // -------------------------- Pós-Combate
    werase(tela_capitulo3);
    box(tela_capitulo3, 0, 0);
    wrefresh(tela_capitulo3);

    if (resultado_combate == VITORIA && cerberus->vida <= 0)
    {
        // Roteiro: Derrotado por Ataque
        desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus_defeated.txt", 1, 5);
        mvwprintw(tela_capitulo3, 24, 6, "[Cerberus]");

        slow_mvwprintw(tela_capitulo3, "Auu… rrgh…", 25, 6, 35);
        napms(1500);
        slow_mvwprintw(tela_capitulo3, "O Cerberus cai no chão", 26, 6, 35);
        napms(1500);

        player->NumeroAndar = Andar4;
    }
    else if (resultado_combate == VITORIA && cerberus->vida >= 0)
    {
        // Roteiro: Derrotado por Mercy
        desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus_defeated.txt", 1, 5);
        mvwprintw(tela_capitulo3, 24, 6, "[Cerberus]");

        slow_mvwprintw(tela_capitulo3, "GRRRR…", 25, 6, 20);

        player->karma += 1;
        player->NumeroAndar = Andar4;
    }
    else
    {
        // Derrota do Player
        desenhar_sprite(tela_capitulo3, "assets/sprites/bosses/cerberus.txt", 1, 5);
        mvwprintw(tela_capitulo3, 24, 6, "[Cerberus]");

        slow_mvwprintw(tela_capitulo3, "whine…", 25, 6, 20);

        player->vida = vida_max_total(player);
        salvar_jogo(player);
        mostrar_tela_morte(player);
    }

    wrefresh(tela_capitulo3);
    napms(2500);
    apagar_janela(tela_capitulo3);

    return true;
}