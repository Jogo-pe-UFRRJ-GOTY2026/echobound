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

bool Capitulo5(Player *player)
{
    WINDOW *tela_capitulo5 = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    box(tela_capitulo5, 0, 0);
    wrefresh(tela_capitulo5);

    // -------------------------- Descrição do Cenário
    slow_mvwprintw(tela_capitulo5, "O topo assemelha se a uma catedral, há partes das paredes e do teto danificados que permitem a vista do resto Intervalo.", 10, 6, 20);
    slow_mvwprintw(tela_capitulo5, "O vento deste espaço flui pelas frestas e permitem uma brisa agradável, olhando por meio de um pequeno buraco na parede encontra-se uma figura esquelética,", 11, 6, 20);
    slow_mvwprintw(tela_capitulo5, "Suas roupas conferem um ar majestoso, mas ainda assim, suavemente sujas", 12, 6, 20);
    slow_mvwprintw(tela_capitulo5, "Ele olha com um olhar nostálgico e reflexivo para paisagem e exclama com certo conforto e calmaria na voz mesmo sem se virar em sua direção", 13, 6, 20);

    napms(2500);

    werase(tela_capitulo5);
    box(tela_capitulo5, 0, 0);

    // Renderiza o sprite do Dragão
    desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king.txt", 1, 5);
    mvwprintw(tela_capitulo5, 30, 6, "[Rei Caido]");
    slow_mvwprintw(tela_capitulo5, "Hmm… Acho que você é o primeiro que eu vejo a chegar aqui tão alto, seja bem-vindo", 31, 6, 20);
    slow_mvwprintw(tela_capitulo5, "Você já sabe o que fará daqui pra frente?", 32, 6, 20);
    mvwprintw(tela_capitulo5, 33, 6, "[%s]", player->nome);
    slow_mvwprintw(tela_capitulo5, "Ainda não sei… só continuei subindo. Eu subi até aqui porque achei que no topo haveria uma saída.", 34, 6, 20);

    wattron(tela_capitulo5, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
    slow_mvwprintw(tela_capitulo5, "A aparência dele, ainda que esquelética e antiga, desperta um breve sentimento de déjà vu sobre você", 35, 6, 20);
    wattroff(tela_capitulo5, A_BOLD | COLOR_PAIR(COR_TEXTO_MORTE));
    slow_mvwprintw(tela_capitulo5, "Você chacoalha a cabeça ignorando o sentimento, e se aproxima", 35, 6, 20);

    napms(2000);

    // -------------------------- Diálogo Condicional
    if (player->medidor_lembranca[Rei_Caido] < 1)
    {
        const char *opcoes_dialogo[4] = {
            "Se eu chegar ao topo… eu realmente consigo sair daqui?",
            "Já estamos bem alto… Este é o último andar?",
            "E você? O que faz aqui sozinho?",
            "O que acontece se lutarmos? Se eu também passar por você? A torre responderá de alguma forma?"};

        int ja_realizou_pergunta[4] = {0};
        int opcao = 0;

        while (true)
        {
            werase(tela_capitulo5);
            box(tela_capitulo5, 0, 0);
            desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king.txt", 1, 5);

            // Menu de Opções
            for (int i = 0; i < 4; i++)
            {
                if (ja_realizou_pergunta[i])
                    wattron(tela_capitulo5, COLOR_PAIR(COR_OPCAO_INVALIDA));

                mvwprintw(tela_capitulo5, 31 + i, 6, "%d. %s", i + 1, opcoes_dialogo[i]);

                wattrset(tela_capitulo5, A_NORMAL);
            }

            wattron(tela_capitulo5, COLOR_PAIR(COR_DESTAQUE));
            mvwprintw(tela_capitulo5, getmaxy(tela_capitulo5) - 3, 4, "Pressione ENTER para iniciar o combate");
            wattroff(tela_capitulo5, COLOR_PAIR(COR_DESTAQUE));

            wrefresh(tela_capitulo5);

            int tecla = wgetch(tela_capitulo5);

            if (tecla == '1')
                opcao = 0;
            if (tecla == '2')
                opcao = 1;
            if (tecla == '3')
                opcao = 2;
            if (tecla == '4')
                opcao = 3;

            if (tecla == KEY_ENTER || tecla == '\n' || tecla == 10)
            {
                for (int i = 0; i < 6; i++)
                    mvwhline(tela_capitulo5, 29 + i, 1, ' ', getmaxx(tela_capitulo5) - 2);

                mvwprintw(tela_capitulo5, 29, 6, "[Rei Caido]");
                slow_mvwprintw(tela_capitulo5, "Percebo que está eufórico para continuar, responderei a tua espada com a minha", 30, 6, 20);
                slow_mvwprintw(tela_capitulo5, "…retomaremos o que foi iniciado uma vez antes, certo ", 31, 6, 20);
                slow_mvwprintw(tela_capitulo5, player->nome, 31, 53, 20);
                napms(800);
                break;
            }

            if (!ja_realizou_pergunta[opcao])
            {
                ja_realizou_pergunta[opcao] = 1;

                werase(tela_capitulo5);
                box(tela_capitulo5, 0, 0);
                desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king.txt", 1, 5);

                mvwprintw(tela_capitulo5, 29, 6, "[Rei Caido]");

                if (opcao == 0)
                {
                    slow_mvwprintw(tela_capitulo5, "Talvez. Muitos subiram acreditando nisso… poucos chegaram até aqui.", 30, 6, 20);
                    slow_mvwprintw(tela_capitulo5, "E mesmo entre os que alcançam o topo, nem todos encontram aquilo que vieram buscar", 31, 6, 20);
                    slow_mvwprintw(tela_capitulo5, "Às vezes a saída existe… mas não da forma que imaginamos.", 32, 6, 20);
                }
                else if (opcao == 1)
                {
                    slow_mvwprintw(tela_capitulo5, "Sim… este é o topo. Acima daqui, não há mais degraus… apenas a decisão que te trouxe até aqui.", 30, 6, 30);
                    slow_mvwprintw(tela_capitulo5, "Muitos acreditam que alcançar o último andar significa encontrar respostas.", 31, 6, 30);
                    slow_mvwprintw(tela_capitulo5, "Mas, às vezes… significa apenas perceber qual pergunta realmente carregavam consigo.", 32, 6, 30);
                }
                else if (opcao == 2)
                {
                    slow_mvwprintw(tela_capitulo5, "Eu? Observo. Recordo… ou pelo menos tento.", 30, 6, 30);
                    slow_mvwprintw(tela_capitulo5, "Houve um tempo em que eu tinha um reino, um nome que ecoava por muitos salões… mas o tempo e minhas ações passadas levaram quase tudo.", 31, 6, 30);
                    slow_mvwprintw(tela_capitulo5, "Restou apenas este lugar… e a vista. Então permaneço aqui.", 32, 6, 30);
                    slow_mvwprintw(tela_capitulo5, "Assistindo o Intervalo seguir em frente… mesmo quando eu já não pude.", 33, 6, 30);
                }
                else if (opcao == 3)
                {
                    slow_mvwprintw(tela_capitulo5, "Não sei responder essa indagação… Porque não testamos? (ele levanta sua espada)", 30, 6, 30);
                    napms(1500);
                    break;
                }

                wrefresh(tela_capitulo5);
                napms(2500);
            }
        }
    }
    else
    {
        // Caso o Player já tenha enfrentado ele antes
        werase(tela_capitulo5);
        box(tela_capitulo5, 0, 0);
        desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king.txt", 1, 5);

        mvwprintw(tela_capitulo5, 28, 6, "[Fallen King]");
        slow_mvwprintw(tela_capitulo5, "Vejo que retornaste… Pronto para uma revanche?", 29, 6, 20);

        wrefresh(tela_capitulo5);
        napms(2500);
    }

    // -------------------------- Configuração do Combate
    AtaqueInimigo ataques[] = {
        criar_ataque(LINHA, 8, "<::::::::::::}==()", 1, HORIZONTAL, DIREITA_ESQUERDA, 2, 25),
        criar_ataque(LINHA, 8, ")={:::::>", 1, HORIZONTAL, ESQUERDA_DIREITA, 2, 25),
        criar_ataque(BULLET, 8, "🗲", 1, VERTICAL, CIMA_BAIXO, 2, 25),
        criar_ataque(BULLET, 8, "🗲", 1, VERTICAL, BAIXO_CIMA, 2, 25),
        criar_ataque(LASER, 12, "𝄽", 0, VERTICAL, NAO_IMPORTA, 80, 60),
        criar_ataque(LASER, 12, "𝄽", 0, HORIZONTAL, NAO_IMPORTA, 80, 60),
        criar_ataque(PAREDE, 8, "⧷", 1, HORIZONTAL, BAIXO_CIMA, 7, 110), // 🞪
        criar_ataque_area(5, "𝄽", 1, 0, 0, 80, 5),
        criar_ataque_area(7, "𝄽", 1, 6, 6, 90, 90),
        criar_ataque(PAREDE, 8, "🦴", 1, VERTICAL, DIREITA_ESQUERDA, 7, 110), // 🞪
    };

    Sprite_size size;
    size.x = 42;
    size.y = 28;

    Inimigo *fallen_king = criar_inimigo(375, "Rei Caido", "assets/sprites/bosses/fallen_king.txt", size, 65, 38, Rei_Caido);

    // Diálogos apos Ataque recebido
    fallen_king->dialogos_ataque[0] = "Ora… Vejo que chegar até aqui não foi resultado de sorte.";
    fallen_king->dialogos_ataque[1] = "Continue. Quero ver até onde sua convicção o levará.";
    fallen_king->dialogos_ataque[2] = "Sabe, as vezes estender a mão é mais dificil que levantar a espada.";
    fallen_king->dialogos_ataque[3] = "Curioso… Antes eu exigia a lealdade. Agora respeito tal tipo determinação.";
    fallen_king->dialogos_ataque[4] = "Sua determinação transparece pelos seus golpes, prossiga";

    // Diálogos apos player oferecer Mercy (Piedade)
    fallen_king->dialogos_mercy[0] = "Poucos teriam me oferecido clemência quando eu não oferecia nenhuma, mas eu ainda tenho desejo de levar este embate até o final.";
    fallen_king->dialogos_mercy[1] = "Talvez você já tenha aprendido uma lição que me custou uma vida inteira… Mas ainda assim, você chegou até o topo, levante sua arma!.";
    fallen_king->dialogos_mercy[2] = "Ainda assim, palavras possuem valor apenas quando sustentadas por ações, continue.";

    fallen_king->numero_ataques = len(ataques);
    for (int i = 0; i < fallen_king->numero_ataques; i++)
        fallen_king->ataques[i] = ataques[i];

    werase(tela_capitulo5);
    wrefresh(tela_capitulo5);

    // Execução da luta
    EstadoRodada resultado_combate = iniciar_combate(player, fallen_king);
    player->medidor_lembranca[Rei_Caido] += 1;
    free_inimigo(fallen_king);

    // -------------------------- Pós-Combate
    werase(tela_capitulo5);
    box(tela_capitulo5, 0, 0);
    wrefresh(tela_capitulo5);

    if (resultado_combate == VITORIA)
    {
        desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king_defeated.txt", 1, 5);



        slow_mvwprintw(tela_capitulo5, "derruba a arma do rei caíde de suas mãos, e em um rápido golpe, o derruba de joelhos.", 34, 6, 100);

        mvwprintw(tela_capitulo5, 35, 6, "[Rei Caido]");

        
        slow_mvwprintw(tela_capitulo5, "(Ofegante)", 36, 6, 75);
        napms(1500);
        slow_mvwprintw(tela_capitulo5, "Vejo que…", 37, 6, 75);
        napms(1500);
        slow_mvwprintw(tela_capitulo5, "chegamos ao fim…", 38, 6, 75);
        napms(1500);

        slow_mvwprintw(tela_capitulo5, player->nome, 39, 6, 75);

        napms(1500);

        player->NumeroAndar = Epilogo;
        player->vida = vida_max_total(player);
    }
    else
    {
        // Derrota do Player
        desenhar_sprite(tela_capitulo5, "assets/sprites/bosses/fallen_king.txt", 1, 5);
        mvwprintw(tela_capitulo5, 24, 6, "[Rei Caido]");

        slow_mvwprintw(tela_capitulo5, "Vejo que ainda falta força para tornar seus desejos em realidade… Estarei esperando sua próxima tentativa.", 25, 6, 20);
        napms(1500);
        player->vida = vida_max_total(player);
        salvar_jogo(player);
        mostrar_tela_morte(player);
    }

    wrefresh(tela_capitulo5);
    napms(2500);
    apagar_janela(tela_capitulo5);

    return true;
}