#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>
#include "../objects/Player.h"
#include "../objects/Inventario.h"
#include "../utils/utils.h"
#include "../chapters/CAPITULO.h"

#define NUM_OF_ELEMENTS 1
Player *carregar_salvamento()
{

    FILE *save_file = fopen("saves/player_save.bin", "rb");
    if (save_file == NULL)
    {
        // perror("Test Error: Erro ao ler arquivo de salvamento");
        return NULL;
    }

    Player *player = malloc(sizeof(Player));
    if (player == NULL)
    {
        // perror("Test Error: Erro ao alocar estrutura player");
        fclose(save_file);
        return NULL;
    }

    // ponteiro para os dados, tamanho de cada elemento, quantidade de elementos, arquivo
    if (fread(player, sizeof(Player), NUM_OF_ELEMENTS, save_file) != NUM_OF_ELEMENTS)
    {
        // perror("Test Error: Erro ao ler estrutura player do arquivo de salvamento");
        free(player);
        fclose(save_file);
        return NULL;
    }
    fclose(save_file);

    return player;
}

bool salvar_jogo(Player *player)
{
    FILE *save_file = fopen("saves/player_save.bin", "wb");
    if (save_file == NULL)
    {
        perror("Test Error: Erro ao criar arquivo de salvamento");
        return false;
    }

    // ponteiro para os dados, tamanho de cada elemento, quantidade de elementos, arquivo
    if (fwrite(player, sizeof(Player), NUM_OF_ELEMENTS, save_file) != NUM_OF_ELEMENTS)
    {
        perror("Test Error: Erro ao escrever estrutura player no arquivo de salvamento");
        fclose(save_file);
        return false;
    }
    fclose(save_file);
    return true;
}

void ponto_save(Player *player)
{
    WINDOW *ponto_save_window = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    keypad(ponto_save_window, TRUE);
    nodelay(ponto_save_window, TRUE);
    bool descansando = true;
    int tecla;

    while (descansando)
    {
        werase(ponto_save_window);
        box(ponto_save_window, 0, 0);
        desenhar_sprite(ponto_save_window, "assets/sprites/buildings/save_point.txt", 5, 5);

        tecla = wgetch(ponto_save_window);
        napms(500);
        switch (tecla)
        {
        case '1':

            descansar(player);
            salvar_jogo(player);

            mvwprintw(ponto_save_window, getmaxy(ponto_save_window) - 6, 3, "Você descansou e recuperou suas forças.");
            wattron(ponto_save_window, COLOR_PAIR(COR_DESTAQUE) | A_BOLD);
            mvwprintw(ponto_save_window, getmaxy(ponto_save_window) - 5, 5, "Progresso salvo com sucesso");
            wattroff(ponto_save_window, COLOR_PAIR(COR_DESTAQUE) | A_BOLD);
            wrefresh(ponto_save_window);
            napms(1000);

            break;

        case '2':
            
            descansar(player);;
            salvar_jogo(player);
            wattron(ponto_save_window, COLOR_PAIR(COR_DESTAQUE) | A_BOLD);
            mvwprintw(ponto_save_window, getmaxy(ponto_save_window) - 3, 5, "Progresso salvo com sucesso. Fechando jogo…");
            wattroff(ponto_save_window, COLOR_PAIR(COR_DESTAQUE) | A_BOLD);
            wrefresh(ponto_save_window);
            napms(1500);
            apagar_janela(ponto_save_window);
            endwin();
            free(player);
            exit(EXIT_SUCCESS);

            // Fala com vigia

        case '3':
            werase(ponto_save_window);
            desenhar_sprite(ponto_save_window, "assets/sprites/others/vigia.txt", 5, 5);
            char *opcoes_dialogo[8];
            char *respostas[8];
            int num_perguntas; // max 3, min 0
            int opcao;

            switch (player->NumeroAndar)
            {
            case Andar1: // depois do hollow knight
                num_perguntas = 5;

                opcoes_dialogo[0] = "O que é este lugar?";
                opcoes_dialogo[1] = "Quem é você?";
                opcoes_dialogo[2] = "O que é a Torre dos Ecos?";
                opcoes_dialogo[3] = "Quem era aquele guerreiro?";
                opcoes_dialogo[4] = "Aquele cavaleiro… ele parecia tão… indignado";

                respostas[0] = "Chamamos este lugar de Intervalo. Nem vida, nem morte. Apenas aquilo que restou depois que ambos passaram.";
                respostas[1] = "Sou apenas o Vigia. Observo os que chegam… e os que desaparecem.";
                respostas[2] = "A Torre não foi construída. Ela nasceu. Ela não é do inferno, nem do paraíso, nem do purgatório…";
                respostas[3] = "Mais uma alma que tentou vencer a Torre. O que restou dele ainda empunha a espada.";
                respostas[4] = "Ele tentou centenas de vezes chegar ao topo, sem sucesso. Acredito que ele não quer que sofram o mesmo destino dele, e por isso guarda a entrada";

                break;

            case Andar2: // depois do cruciator
                num_perguntas = 4;

                opcoes_dialogo[0] = "Existe algo ou alguém que nunca será esquecido?";
                opcoes_dialogo[1] = "O que são Ecos?";
                opcoes_dialogo[2] = "Por que sinto como se alguem estivesse me observando?";
                opcoes_dialogo[3] = "Quem era Cruciator?";

                respostas[0] = "Dentre os que não se esqueceram de tudo ainda, falam acerca do strogonoff do IM da UFRRJ.";
                respostas[1] = "Ecos são memórias que ecoam por todo o Intervalo, fazendo com que você seja lembrado por um longo tempo por aqui, mas não 'Ad Eternum'.";
                respostas[2] = "Porque está. Há olhos no Intervalo que permanecem abertos mesmo quando tudo ao redor adormece.";
                respostas[3] = "Seu nome completo é Cruciator ad Eternum. Ele foi considerado o Funcionário do Século por Lucifer e \n recebeu como prêmio a oportunidade de se 'entreter' com o sofrimento das almas do Intervalo que chegam até ele — e não o contrário.";
                break;

            case Andar3: // depois do Aphanos
                num_perguntas = 6;

                opcoes_dialogo[0] = "Por que eu continuo retornando? Porque não desapareço ao morrer?";
                opcoes_dialogo[1] = "Já houve alguém como eu aqui?";
                opcoes_dialogo[2] = "Por que Aphanos tinha uma visão tão melancólica do destino?";
                opcoes_dialogo[3] = "Por que Aphanos se envolveu com as Moiras?";
                opcoes_dialogo[4] = "O quanto você acredita no destino, que as cosias estão pré-determinadas? ";
                opcoes_dialogo[5] = "Por que o nome dele é Aphanos?";

                respostas[0] = "Porque seu medidor de memórias ainda não esvaziou… Você não tem mais pra onde ir, então volta pra cá.";
                respostas[1] = "Mais do que você imagina. Menos do que a Torre gostaria.";
                respostas[2] = "Aphanos fez um acordo com as Moiras, propositalmente impossível de ser realizado.";
                respostas[3] = "Sua esposa adquiriu uma doença terminal, então ele, sem ouvir todo o acordo, curou a esposa em troca de Aphanos assassinar o próprio pai.";
                respostas[4] = "Não o bastante, ou talvez não o necessário. Gosto de pensar que possuo livre-arbítrio.";
                respostas[5] = "Aphanos significa invisível, desde o nascimento ele era condenado a invisibilidade, a ver sua esposa e família esquecendo dele…";

                break;

            case Andar4: // depois do Cerberus, bixo de estimação do rei caido
                num_perguntas = 5;

                opcoes_dialogo[0] = "Por que sinto minhas memórias voltando?";
                opcoes_dialogo[1] = "Quem eu fui antes de chegar aqui?";
                opcoes_dialogo[2] = "Como um Cerberus foi parar aqui?";
                opcoes_dialogo[3] = "Os seres que estão morando na torre já viveram na Terra?";
                opcoes_dialogo[4] = "Você sabe como isso termina?";

                respostas[0] = "Porque algumas lembranças despertam apenas quando encontram aquilo que as feriu.";
                respostas[1] = "Seus ecos ainda perduram. Mas eles continuam distantes… como um eco atrás de uma porta fechada."; // valida aqui PMI
                respostas[2] = "Uma indagação válida… Não tenho conhecimento o bastante para soluciona-la, mas é engraçado, não eres o primeiro a fazer tal";
                respostas[3] = "Bom… Existem exceções, afinal, você viu um demônio nessa torre, mas, teoricamente, sim.";
                respostas[4] = "Em tese sei, mas apenas em tese, nunca lutei contra o Intervalo, eu faço parte dele.";

                break;

            case Andar5: // depois do Iowa
                num_perguntas = 6;

                opcoes_dialogo[0] = "O que existe no topo?";
                opcoes_dialogo[1] = "Você já chegou perto do topo?";
                opcoes_dialogo[2] = "O que acontece quando alguém sai daqui?";
                opcoes_dialogo[3] = "Por que você me ajuda?";
                opcoes_dialogo[4] = "Ainda existe algo me esperando fora daqui?";
                opcoes_dialogo[5] = "E se eu não gostar do que encontrar?";

                respostas[0] = "O que você mais sonha, teoricamente.";
                respostas[1] = "Perto o bastante para ouvir o chamado. Longe o bastante para nunca alcançá-lo.";
                respostas[2] = "Em tese, seria o retorno ao mundo… Em tese";
                respostas[3] = "Eu ajudo todos que passam por aqui, vejo que o potencial das almas aumenta quando recebe apoio.";
                respostas[4] = "Talvez. Um lugar. Uma voz. Ou alguém que ainda se recuse a esquecer você.";
                respostas[5] = "Então finalmente verá a verdade sem desejar tê-la encontrado.";

                break;
            }
            bool conversando = true;
            int ja_realizou_pergunta[8] = {0};

            while (conversando)
            {
                werase(ponto_save_window);
                box(ponto_save_window, 0, 0);
                desenhar_sprite(ponto_save_window, "assets/sprites/others/vigia.txt", 5, 5);
                mvwprintw(ponto_save_window, 28, 6, "[Vigia]");

                for (int i = 0; i < num_perguntas; i++)
                {
                    if (ja_realizou_pergunta[i])
                        wattron(ponto_save_window, COLOR_PAIR(COR_OPCAO_INVALIDA));
                    mvwprintw(ponto_save_window, 30 + i, 6, "%d. %s", i + 1, opcoes_dialogo[i]);
                    wattrset(ponto_save_window, A_NORMAL);
                }
                wattron(ponto_save_window, COLOR_PAIR(COR_DESTAQUE));
                mvwprintw(ponto_save_window, getmaxy(ponto_save_window) - 3, 4, "Pressione ENTER para se despedir");
                wattroff(ponto_save_window, COLOR_PAIR(COR_DESTAQUE));
                wrefresh(ponto_save_window);

                opcao = wgetch(ponto_save_window);
                if (opcao == KEY_ENTER || opcao == '\n' || opcao == 10)
                {
                    conversando = false;
                    break;
                }
                if (opcao < '1' || opcao > ('0' + num_perguntas))
                    continue;

                int opcao_selecionada = opcao - '1';

                if (ja_realizou_pergunta[opcao_selecionada])
                    continue;

                ja_realizou_pergunta[opcao_selecionada] = 1;
                werase(ponto_save_window);
                box(ponto_save_window, 0, 0);
                desenhar_sprite(ponto_save_window, "assets/sprites/others/vigia.txt", 5, 5);

                mvwprintw(ponto_save_window, 28, 6, "[%s]", player->nome);
                slow_mvwprintw(ponto_save_window, opcoes_dialogo[opcao_selecionada], 29, 6, 30);

                wrefresh(ponto_save_window);
                napms(1200);
                mvwprintw(ponto_save_window, 30, 6, "[Vigia]");
                slow_mvwprintw(ponto_save_window, respostas[opcao_selecionada], 31, 6, 30);

                wrefresh(ponto_save_window);
                napms(1200);

                if (opcao == KEY_ENTER || opcao == '\n' || opcao == 10)
                {
                    conversando = false;
                    break;
                }
            }

            werase(ponto_save_window);
            box(ponto_save_window, 0, 0);
            desenhar_sprite(ponto_save_window, "assets/sprites/others/vigia.txt", 5, 5);
            mvwprintw(ponto_save_window, 28, 6, "[%s]", player->nome);
            wrefresh(ponto_save_window);

            slow_mvwprintw(ponto_save_window, "Bem, vou voltar a Torre… Até", 29, 6, 40);
            napms(1000);
            break;

            // Fala com vigia

        case '4':
            slow_mvwprintw(ponto_save_window, "Você levanta e volta a Torre", getmaxy(ponto_save_window) - 3, 5, 30);
            descansando = false;
            break;
        }
    }
}

void flashbacks(Player* player)
{
    WINDOW* tela_flashback = newwin(0, 0, getmaxx(stdscr), getmaxy(stdscr));
    int start_text = getmaxx(tela_flashback)/3+10;
    box(tela_flashback, 0, 0);
    int y = 5;

    switch(player->NumeroAndar)
    {
        case Andar1:

            slow_mvwprintw(tela_flashback, "O cansaço pós-batalha recai sobre teu corpo, e enquanto sua visão obscurece lentamente,", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "sua visão começa a voltar a uns acontecimentos passados.", y + 1, start_text, 20);
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);

            slow_mvwprintw(tela_flashback, "As ruas centrais estavam cheias. Mercadores vinham de terras distantes, trazendo tecidos,", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "especiarias, metais raros e novidades que fariam a elite sorrir por uma noite e esquecer o resto do mundo.", y + 1, start_text, 20);
            slow_mvwprintw(tela_flashback, "Carroças cruzavam as avenidas movimentadas. Guardas patrulhavam cada esquina com a postura de quem", y + 2, start_text, 20);
            slow_mvwprintw(tela_flashback, "não servia ao povo, mas ao medo. Você finalmente se lembrou de como era o mundo.", y + 3, start_text, 20);
            napms(800);

            slow_mvwprintw(tela_flashback, "Mas, à medida que se aproximava da oficina que alugara antes de chegar à capital, a cidade mudava", y + 4, start_text, 20);
            slow_mvwprintw(tela_flashback, "de rosto. As fachadas bem cuidadas davam lugar a muros gastos, poças escuras, cheiros de umidade", y + 5, start_text, 20);
            slow_mvwprintw(tela_flashback, "e ferrugem. O barulho das lojas diminuía, e o som dos próprios passos se tornava mais nítido.", y + 6, start_text, 20);
            slow_mvwprintw(tela_flashback, "Foi então que você os viu.", y + 11, 2, 20);
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);

            slow_mvwprintw(tela_flashback, "Pessoas sentadas no chão. Corpos curvados sob trapos, cobertores rasgados e roupas que já tinham", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "perdido a cor há muito tempo. Crianças com olhos fundos estendiam as mãos para implorar por moedas.", y + 1, start_text, 20);
            slow_mvwprintw(tela_flashback, "Velhos se amontoavam contra paredes rachadas, sem força sequer para pedir. Algumas dessas pessoas", y + 2, start_text, 20);
            slow_mvwprintw(tela_flashback, "ainda tentavam sorrir; outras já tinham desistido de qualquer forma de esperança.", y + 3, start_text, 20);
            slow_mvwprintw(tela_flashback, "Você passou por elas e percebeu que a fome ali não era uma exceção. Era uma regra.", y + 4, start_text, 20);

            napms(800);

            wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_flashback, "Naquele dia, algo começou a incomodar de um jeito difícil de ignorar.", y + 8, start_text, 20);
            slow_mvwprintw(tela_flashback, "Não era apenas estranhamento. Era a percepção de que havia algo profundamente errado naquele reino.", y + 9, start_text, 20);
            wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            napms(800);

            slow_mvwprintw(tela_flashback, "Você, que era hábil com a forja, passou a entender que uma lâmina nunca é apenas uma lâmina.", y + 10, start_text, 20);
            slow_mvwprintw(tela_flashback, "Uma espada podia ser instrumento de proteção, símbolo de poder ou sentença de morte.", y + 11, start_text, 20);

            slow_mvwprintw(tela_flashback, "E uma boa arma, em tempos de ruína, sempre encontraria mãos dispostas a segurá - la.", y + 12, start_text, 20);

            wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_flashback, "Foi assim que sua oficina começou a chamar atenção.", y + 15, start_text, 20);
            wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);

            napms(800);

            slow_mvwprintw(tela_flashback, "Você trabalhava com precisão.Sabia equilibrar peso, resistência e corte.Sabia transformar ferro", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "bruto em algo digno de respeito.Espadas, adagas, lanças curtas, reforços de aço, encaixes de guarda,", y + 1, start_text, 20);
            slow_mvwprintw(tela_flashback, "detalhes que outros ferreiros ignoravam e que para você faziam toda a diferença.", y + 2, start_text, 20);
            slow_mvwprintw(tela_flashback, "Logo, seus trabalhos começaram a circular entre patrulhas, mercenários, cavaleiros e até", y + 3, start_text, 20);
            slow_mvwprintw(tela_flashback, "mensageiros da corte.E, no meio disso tudo, surgiram as primeiras amizades.", y + 4, start_text, 20);

            napms(800);

            slow_mvwprintw(tela_flashback, "Não eram amizades nobres.Eram vínculos de sobrevivência.Um aprendiz que dividia pão velho com", y + 5, start_text, 20);
            slow_mvwprintw(tela_flashback, "você no fim do expediente.Uma mulher do bairro baixo que trazia informações e recebia proteção", y + 6, start_text, 20);
            slow_mvwprintw(tela_flashback, "em troca.Um soldado cansado que preferia sua companhia à dos colegas de quartel.", y + 7, start_text, 20);
            slow_mvwprintw(tela_flashback, "Gente simples, com sonhos pequenos demais para o palácio notar, mas grandes o suficiente para", y + 8, start_text, 20);
            slow_mvwprintw(tela_flashback, "manter um mundo em pé e mostrar que ", y + 9, start_text, 20);

            slow_mvwprintw(tela_flashback, player->nome, y + 9, start_text + 36, 20);
            slow_mvwprintw(tela_flashback, " estava realmente vivo.", y + 11, start_text + 36 + strlen(player->nome), 20);

            wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_flashback, "E foi nesse mundo rachado que a história de ", y + 19, start_text, 20);
            slow_mvwprintw(tela_flashback, player->nome, y + 19, start_text + 44, 20);
            slow_mvwprintw(tela_flashback, " foi escrita.", y + 19, start_text + 44 + strlen(player->nome), 20);
            wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            wrefresh(tela_flashback);

            break;

        case Andar2:
            slow_mvwprintw(tela_flashback, "Conforme você coloca seus pés sobre as escadas, mais uma vez ecos do seu passado", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "percorrem por sua mente.", y + 1, start_text, 20);
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);

            slow_mvwprintw(tela_flashback, "Um cavaleiro chegou até sua estadia, imponente, blindado, com a postura de quem já entrava", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "esperando obediência. Não veio sozinho. Trouxe consigo a autoridade de um nome,", y + 1, start_text, 20);
            slow_mvwprintw(tela_flashback, "o peso de uma insígnia e a promessa de uma oportunidade \"irrecusável\".", y + 2, start_text, 20);
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);
            slow_mvwprintw(tela_flashback, "Ele falou de dever. Falou de honra. Falou de estabilidade. Disse que o reino precisava de homens", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "úteis, não de sonhadores. Dissera que o rei havia percebido seu talento, que sua habilidade", y + 1, start_text, 20);
            slow_mvwprintw(tela_flashback, "poderia finalmente ser reconhecida, e que haveria lugar para você entre os que", y + 2, start_text, 20);
            slow_mvwprintw(tela_flashback, "\"faziam a diferença\".", y + 3, start_text, 20);
            napms(800);
            wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_flashback, "Mas o que ele realmente oferecia não era reconhecimento. Era uma amarra.", y + 6, start_text, 20);
            wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            napms(800);
            slow_mvwprintw(tela_flashback, "O cavaleiro tinha olhos treinados para ver utilidade, não valor. Naquele instante,", y + 8, start_text, 20);
            slow_mvwprintw(tela_flashback, "você entendeu que o palácio só se interessava por você enquanto sua habilidade servisse", y + 9, start_text, 20);
            slow_mvwprintw(tela_flashback, "para fortalecer os mesmos muros que esmagavam o povo. O convite era uma coleira dourada.", y + 10, start_text, 20);
            slow_mvwprintw(tela_flashback, "Uma promoção para alguém que jamais seria tratado como igual.", y + 11, start_text, 20);
            napms(800);
            werase(tela_flashback);
            box(tela_flashback, 0, 0);
            wrefresh(tela_flashback);
            slow_mvwprintw(tela_flashback, "Mesmo assim, o encontro mudou algo. Porque foi ali que você ouviu, pela primeira vez com clareza,", y, start_text, 20);
            slow_mvwprintw(tela_flashback, "o nome de Atlas, um revolucionário que queria mais atenção para seu povo.", y + 1, start_text, 20);
            napms(800);
            slow_mvwprintw(tela_flashback, "Atlas não apareceu de imediato. Veio como uma sombra ao redor da conversa, alguém mencionado", y + 4, start_text, 20);
            slow_mvwprintw(tela_flashback, "em voz baixa por homens influentes, um nome que circulava entre os descontentes,", y + 5, start_text, 20);
            slow_mvwprintw(tela_flashback, "os exilados, os revoltados e os que já tinham perdido demais para continuar calados.", y + 6, start_text, 20);
            slow_mvwprintw(tela_flashback, "Diziam que ele via o que o reino escondia. Diziam que ele entendia a dor do povo.", y + 7, start_text, 20);
            slow_mvwprintw(tela_flashback, "Diziam que ele queria derrubar o rei.", y + 8, start_text, 20);
            napms(800);
            wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            slow_mvwprintw(tela_flashback, "", y + 12, start_text, 20);
            slow_mvwprintw(tela_flashback, player->nome, y + 12, start_text, 20);
            slow_mvwprintw(tela_flashback, " sentiu uma oportunidade e se agarrou a ela...", y + 12, start_text + strlen(player->nome), 20);
            wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
            wrefresh(tela_flashback);
            break;

        case Andar3:
            break;

        case Andar4:
            break;

        case Andar5:
            break;

        default:
            break;
    }
}