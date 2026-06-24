#include <ncurses.h>
#include "CAPITULO.h"
#include "../objects/Player.h"
#include "../utils/utils.h"


void flashbacks(Player *player)
{
    WINDOW *tela_flashback = newwin(0, 0, getmaxy(stdscr), getmaxx(stdscr));
    int start_text = getmaxx(tela_flashback) / 3 + 10;
    box(tela_flashback, 0, 0);
    int y = 5;

    switch (player->NumeroAndar)
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
        napms(2000);
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
        napms(2000);

        break;

    case Andar3:
        slow_mvwprintw(tela_flashback, "O olhar sob a maça que Alphanos carregava o leva a recordar de seus momentos em sua", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "forja na oficina, o calor, a força de cada martelada, voltando à sua mente...", y + 1, start_text, 20);
        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você estava forjando em sua oficina, espadas com o emblema do reino dispostas", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "em fileiras sobre a bancada. O fogo da fornalha iluminava a parede com um", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "laranja tremulante. O som do metal ecoava seco, ritmado, quase como um coração", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "mecânico. Cada peça recebe acabamento com atenção meticulosa, como se, ao", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "produzir armas, você também estivesse moldando o futuro.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Apesar de que, infelizmente,", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, player->nome, y + 7, start_text + 28, 20);
        slow_mvwprintw(tela_flashback, " via suas incríveis produções", y + 7, start_text + 28 + strlen(player->nome), 20);
        slow_mvwprintw(tela_flashback, "manchadas de sangue nas mãos dos guardas, guardas que utilizavam as suas armas", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "contra o próprio povo que defendia, em nome da \"paz\".", y + 9, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Foi então que Atlas chegou à sua porta.", y, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Sua presença era diferente da dos nobres e diferente da dos guardas. Atlas não", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "entrava como um senhor. Entrava como alguém que parecia conhecer a dor debaixo", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "da pele alheia. Sua voz era serena, calculada, quase íntima. Ele não precisava", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "elevar o tom para ser ouvido. Dizia as coisas como quem já tinha pensado nelas", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "muitas vezes antes.", y + 6, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Falou da fome nas periferias. Da repressão. Das execuções escondidas sob o nome", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "de justiça. Falou dos que se curvavam para sobreviver e dos que eram esmagados", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "por ousar erguer a cabeça. Falou do rei como um cadáver sentado, sustentado por", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "mentira, violência e medo.", y + 11, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você ouviu. E, pela primeira vez, sentiu que alguém estava nomeando exatamente", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "aquilo que você via.", y + 1, start_text, 20);

        slow_mvwprintw(tela_flashback, "Atlas sabia ouvir. Sabia escolher palavras. Sabia transformar indignação em", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "direção. Dizia que o povo precisava de um símbolo, de uma mudança, de uma força", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "capaz de romper a estrutura apodrecida do reino. E também dizia que essa força", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "precisaria de braços, recursos, armas e homens capazes de agir.", y + 6, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Você ouve passos, e ao olhar ao redor, vê que o Rei se aproxima, então, com a", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "preocupação de Atlas ser flagrado,", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, player->nome, y + 9, start_text + 33, 20);
        slow_mvwprintw(tela_flashback, " olha pro lado para alertá-lo,", y + 9, start_text + 33 + strlen(player->nome), 20);
        slow_mvwprintw(tela_flashback, "e... de repente, Atlas não está mais lá, ele desapareceu em um piscar de olhos.", y + 10, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Ao entrar, o Rei, acompanhado de seus melhores guardas, elogia", y, start_text, 20);
        slow_mvwprintw(tela_flashback, player->nome, y, start_text + 60, 20);
        slow_mvwprintw(tela_flashback, " e suas armas impecáveis,", y, start_text + 60 + strlen(player->nome), 20);

        slow_mvwprintw(tela_flashback, "e fala que, se você continuar fazendo um bom trabalho, ele se certificará de", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "que o nome de sua família será imortalizado para sempre por suas exímias armas", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "e lembrado pra sempre, assim como você prometeu para sua mãe antes do", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "falecimento dela, tal qual a dúvida de seu pai quando você abandonou a opressão", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "dele para arrumar algo na cidade.", y + 5, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Mas... Como o rei sabia disso? Afinal, antes de aprender tudo sobre criação de", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "armas com sua mãe nos momentos em que o pai estava trabalhando fora, só eles", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "alimentavam esse desejo de uma mudança positiva no mundo que levaria o nome", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "deles para a eternidade...", y + 10, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, player->nome, y, start_text, 20);
        slow_mvwprintw(tela_flashback, " se questiona se isso foi um elogio, ou uma ameaça por parte do Rei.", y, start_text + strlen(player->nome), 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

        napms(800);

        slow_mvwprintw(tela_flashback, "O Rei responde que, enquanto ele estiver fazendo o certo e mantendo a Província", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "próspera, merecedora, Emerita, as suas palavras serão consideradas elogios.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "O Rei se retira, e então você vê de uma sombra próxima, a figura de Atlas saindo", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "de lá e argumentando sobre a necessidade do fim dessa repressão.", y + 8, start_text, 20);

        napms(800);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Você tinha as armas. Atlas tinha a chama.", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "Então a aliança começou.", y + 13, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

        wrefresh(tela_flashback);
        napms(2000);

        break;

    case Andar4:
        break;

    case Andar5:
        break;

    default:
        break;
    }
    apagar_janela(tela_flashback);
}