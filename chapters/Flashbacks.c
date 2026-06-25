#include <ncurses.h>
#include "CAPITULO.h"
#include "../objects/Player.h"
#include "../utils/utils.h"
#include "../system/Combate.h"

void flashbacks(Player *player)
{
    WINDOW *tela_flashback = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
    int start_text = getmaxx(tela_flashback) / 3 - 20;
    box(tela_flashback, 0, 0);
    int y = 5;

    switch (player->NumeroAndar)
    {
    case Andar1:

        slow_mvwprintw(tela_flashback, "O cansaço pós-batalha recai sobre teu corpo, e enquanto sua visão obscurece lentamente,", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "sua visão começa a voltar a uns acontecimentos passados.", y + 1, start_text, 20);
        napms(1200);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "As ruas centrais estavam cheias. Mercadores vinham de terras distantes, trazendo tecidos,", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "especiarias, metais raros e novidades que fariam a elite sorrir por uma noite e esquecer o resto do mundo.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "Carroças cruzavam as avenidas movimentadas. Guardas patrulhavam cada esquina com a postura de quem", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "não servia ao povo, mas ao medo. Você finalmente se lembrou de como era o mundo.", y + 3, start_text, 20);
        napms(1200);

        slow_mvwprintw(tela_flashback, "Mas, à medida que se aproximava da oficina que alugara antes de chegar à capital, a cidade mudava", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "de rosto. As fachadas bem cuidadas davam lugar a muros gastos, poças escuras, cheiros de umidade", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "e ferrugem. O barulho das lojas diminuía, e o som dos próprios passos se tornava mais nítido.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "Foi então que você os viu.", y + 11, start_text, 20);
        napms(2500);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Pessoas sentadas no chão. Corpos curvados sob trapos, cobertores rasgados e roupas que já tinham", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "perdido a cor há muito tempo. Crianças com olhos fundos estendiam as mãos para implorar por moedas.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "Velhos se amontoavam contra paredes rachadas, sem força sequer para pedir. Algumas dessas pessoas", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "ainda tentavam sorrir; outras já tinham desistido de qualquer forma de esperança.", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "Você passou por elas e percebeu que a fome ali não era uma exceção. Era uma regra.", y + 4, start_text, 20);

        napms(1200);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Naquele dia, algo começou a incomodar de um jeito difícil de ignorar.", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "Não era apenas estranhamento. Era a percepção de que havia algo profundamente errado naquele reino.", y + 9, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        napms(1200);

        slow_mvwprintw(tela_flashback, "Você, que era hábil com a forja, passou a entender que uma lâmina nunca é apenas uma lâmina.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "Uma espada podia ser instrumento de proteção, símbolo de poder ou sentença de morte.", y + 11, start_text, 20);

        slow_mvwprintw(tela_flashback, "E uma boa arma, em tempos de ruína, sempre encontraria mãos dispostas a segurá - la.", y + 12, start_text, 20);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Foi assim que sua oficina começou a chamar atenção.", y + 15, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        napms(2500);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        napms(1200);

        slow_mvwprintw(tela_flashback, "Você trabalhava com precisão. Sabia equilibrar peso, resistência e corte.Sabia transformar ferro", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "bruto em algo digno de respeito. Espadas, adagas, lanças curtas, reforços de aço, encaixes de guarda,", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "detalhes que outros ferreiros ignoravam e que para você faziam toda a diferença.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "Logo, seus trabalhos começaram a circular entre patrulhas, mercenários, cavaleiros e até", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "mensageiros da corte. E, no meio disso tudo, surgiram as primeiras amizades.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Não eram amizades nobres.Eram vínculos de sobrevivência. Um aprendiz que dividia pão velho com", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "você no fim do expediente. Uma mulher do bairro baixo que trazia informações e recebia proteção", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "em troca. Um soldado cansado que preferia sua companhia à dos colegas de quartel.", y + 7, start_text, 20);
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
        napms(2500);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Um cavaleiro chegou até sua estadia, imponente, blindado, com a postura de quem já entrava", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "esperando obediência. Não veio sozinho. Trouxe consigo a autoridade de um nome,", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "o peso de uma insígnia e a promessa de uma oportunidade \"irrecusável\".", y + 2, start_text, 20);
        napms(2500);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);
        slow_mvwprintw(tela_flashback, "Ele falou de dever. Falou de honra. Falou de estabilidade. Disse que o reino precisava de homens", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "úteis, não de sonhadores. Dissera que o rei havia percebido seu talento, que sua habilidade", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "poderia finalmente ser reconhecida, e que haveria lugar para você entre os que", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "\"faziam a diferença\".", y + 3, start_text, 20);
        napms(1200);
        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Mas o que ele realmente oferecia não era reconhecimento. Era uma amarra.", y + 6, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        napms(1200);
        slow_mvwprintw(tela_flashback, "O cavaleiro tinha olhos treinados para ver utilidade, não valor. Naquele instante,", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "você entendeu que o palácio só se interessava por você enquanto sua habilidade servisse", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "para fortalecer os mesmos muros que esmagavam o povo. O convite era uma coleira dourada.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "Uma promoção para alguém que jamais seria tratado como igual.", y + 11, start_text, 20);
        napms(2500);
        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);
        slow_mvwprintw(tela_flashback, "Mesmo assim, o encontro mudou algo. Porque foi ali que você ouviu, pela primeira vez com clareza,", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "o nome de Atlas, um revolucionário que queria mais atenção para seu povo.", y + 1, start_text, 20);
        napms(1200);
        slow_mvwprintw(tela_flashback, "Atlas não apareceu de imediato. Veio como uma sombra ao redor da conversa, alguém mencionado", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "em voz baixa por homens influentes, um nome que circulava entre os descontentes,", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "os exilados, os revoltados e os que já tinham perdido demais para continuar calados.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "Diziam que ele via o que o reino escondia. Diziam que ele entendia a dor do povo.", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "Diziam que ele queria derrubar o rei.", y + 8, start_text, 20);
        napms(1200);
        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, player->nome, y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, " sentiu uma oportunidade e se agarrou a ela…", y + 12, start_text + strlen(player->nome), 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        wrefresh(tela_flashback);
        napms(2000);

        break;

    case Andar3:
        tocar_sound_effect("assets/sound_effect/Blacksmithing.wav");

        slow_mvwprintw(tela_flashback, "O olhar sob a maça que Alphanos carregava o leva a recordar de seus momentos em sua", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "forja na oficina, o calor, a força de cada martelada, voltando à sua mente…", y + 1, start_text, 20);
        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você estava forjando em sua oficina, espadas com o emblema do reino dispostas", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "em fileiras sobre a bancada. O fogo da fornalha iluminava a parede com um", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "laranja tremulante. O som do metal ecoava seco, ritmado, quase como um coração", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "mecânico. Cada peça recebia acabamento com atenção meticulosa, como se, ao", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "produzir armas, você também estivesse moldando o futuro.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Apesar de que, infelizmente,", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, player->nome, y + 7, start_text + 28, 20);
        slow_mvwprintw(tela_flashback, " via suas incríveis produções", y + 7, start_text + 28 + strlen(player->nome), 20);
        slow_mvwprintw(tela_flashback, "manchadas de sangue nas mãos dos guardas, guardas que utilizavam as suas armas", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "contra o próprio povo que defendia, em nome da \"paz\".", y + 9, start_text, 20);

        napms(2500);

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

        napms(2000);

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
        slow_mvwprintw(tela_flashback, "e… de repente, Atlas não está mais lá, ele desapareceu em um piscar de olhos.", y + 10, start_text, 20);

        napms(2000);

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

        slow_mvwprintw(tela_flashback, "Mas… Como o rei sabia disso? Afinal, antes de aprender tudo sobre criação de", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "armas com sua mãe nos momentos em que o pai estava trabalhando fora, só eles", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "alimentavam esse desejo de uma mudança positiva no mundo que levaria o nome", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "deles para a eternidade…", y + 10, start_text, 20);

        napms(2000);

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

        slow_mvwprintw(tela_flashback, "Os sons de latidos abafados do Cerberus retornam à sua memória até uma certa manhã", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "na qual você havia acordado aos sons de altos latidos e rugidos soando na rua.", y + 1, start_text, 20);
        tocar_sound_effect("assets/sound_effect/barking.wav");
        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você havia passado a distribuir armas tanto para o reino quanto para a", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "revolução, e a diferença na qualidade entre elas era sutil demais para ser", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "acidental… e evidente demais para ser ignorada.", y + 2, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "As espadas destinadas aos soldados do rei eram confiáveis. Bem-forjadas,", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "firmes, consistentes. Armas feitas para manter uma estrutura funcionando,", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "sem excessos, sem luxo.", y + 7, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Já as armas que chegavam às mãos dos insurgentes carregavam outra atenção.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "Mais leves, mais refinadas, mais responsivas. Não era apenas técnica — era", y + 11, start_text, 20);
        slow_mvwprintw(tela_flashback, "intenção. Um tipo de cuidado que parecia responder diretamente às condições", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "de quem lutava do outro lado.", y + 13, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você não chamaria isso de escolha política. Chamava de equilíbrio.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Se o mundo já estava dividido, ao menos que cada lado recebesse aquilo que", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "realmente precisava para sobreviver.", y + 2, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "No meio disso, sua consciência se tornava cada vez mais dividida, mas ainda", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "funcional. Você se convencia de que não estava criando guerra — apenas", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "reagindo a ela.", y + 7, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Atlas reforçava essa visão.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Ele não falava como alguém que impunha ideias, mas como alguém que organizava", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "pensamentos que você já tinha.", y + 2, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "O reino estava doente.", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "A violência era estrutural.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "E uma mudança, para ser real, precisaria acontecer de forma inevitável.", y + 7, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Ele falava do futuro como quem acredita que ele pode ser moldado, mesmo que", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "o presente ainda não esteja pronto para isso.", y + 11, start_text, 20);
        slow_mvwprintw(tela_flashback, "E, de certa forma, isso fazia sentido.", y + 12, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Havia fome do lado de fora. Havia medo. Havia silêncio demais onde deveria", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "haver vida.", y + 1, start_text, 20);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "E você continuou.", y + 5, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

        wrefresh(tela_flashback);
        napms(2000);

        break;

    case Andar5:
        char indicador_fala[52];
        snprintf(indicador_fala, 52, "[%s]", player->nome);

        slow_mvwprintw(tela_flashback, "Conforme o som da vitória ecoava pelo Intervalo, algo começou a se desfazer", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "dentro da sua mente, não como lembrança contínua, mas como fragmentos fora", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "de ordem.", y + 2, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, indicador_fala, y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "-Espera… não!", y + 5, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Sua própria voz, distante, o puxão no braço.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "As algemas, o impacto no chão. E então a cela, manchada de sangue, com marcas de tentativas de fuga.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "Mas algo estava errado… A dor não era lembrança, era continuidade.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "Sua respiração falhava em padrões irregulares, como se o corpo já estivesse", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "ferido antes mesmo de você lembrar.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "O Rei estava ali, de pé, calmo, te encarando você no lado de fora… Ele abre a porta e entra", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Eu sempre reconheci seu valor — ele disse. — Suas armas foram impecáveis.", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "Consistentes. Úteis.", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "Ele deu um passo à frente.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "— É por isso que sua decepção é tão… pessoal.", y + 11, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "O silêncio ficou mais pesado.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Você avançou.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "As mãos fecharam no pescoço dele.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "O mundo perdeu o eixo e o ar começou a desaparecer.", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "E só então a memória começou a “revelar” o restante.", y + 4, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "O Rei também estava ferido, com a postura levemente quebrada, respiração", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "curta e marcas de sujeira sob a roupa.", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "E você também.", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "Sangue seco, dor espalhada, movimentos limitados. Nenhum dos dois estava", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "se sobressaindo no embate. ", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "As mãos sobre o pescoço do rei, o chão da cela… O aperto aumentou.", y + 11, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "O Rei tentou falar, ainda sufocado:", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Seu pai também foi útil.", y + 1, start_text, 20);
        napms(800);

        slow_mvwprintw(tela_flashback, "— Até o momento em que deixou de ser.", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "Um silêncio mais profundo.", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Eu ainda lembro da expressão dele quando percebeu que não havia mais espaço para erro.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "Ele inclinou levemente a cabeça.", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Você herdou isso dele. A hesitação antes da quebra.", y + 8, start_text, 20);

        napms(1200);

        slow_mvwprintw(tela_flashback, "A frase entrou como lâmina.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Ele morreu acreditando que ainda havia escolha.", y + 11, start_text, 20);
        slow_mvwprintw(tela_flashback, "Agora o ar já não era só físico.", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "Era mental.", y + 13, start_text, 20);
        slow_mvwprintw(tela_flashback, "E então veio o golpe final:", y + 14, start_text, 20);
        slow_mvwprintw(tela_flashback, "— E você ainda me decepcionou mesmo depois disso.", y + 15, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Isso quebrou algo.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Mas não de forma explosiva.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "De forma inevitável.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "Antes que o desfecho acontecesse, uma presença entrou na cela.", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "Atlas.", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "Sem pressa.", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "Sem surpresa.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "Como alguém que já esperava exatamente aquele instante.", y + 7, start_text, 20);

        napms(1200);

        slow_mvwprintw(tela_flashback, "Ele olhou a cena.", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "O Rei sendo enforcado.", y + 10, start_text, 20);
        slow_mvwprintw(tela_flashback, "Você ferido.", y + 11, start_text, 20);
        slow_mvwprintw(tela_flashback, "O espaço inteiro instável.", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "E disse, baixo:", y + 13, start_text, 20);

        slow_mvwprintw(tela_flashback, "[Atlas]", y + 15, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Isso já saiu do controle.", y + 16, start_text, 20);

        napms(2000);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Você tentou reagir.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Mas o corpo não obedecia como antes.", y + 1, start_text, 20);
        slow_mvwprintw(tela_flashback, "Atlas se aproximou.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "E então o evento mudou de direção.", y + 3, start_text, 20);
        slow_mvwprintw(tela_flashback, "O Rei caiu.", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "Não pela continuidade do seu gesto.", y + 5, start_text, 20);
        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Mas por uma intervenção final de Atlas.", y + 6, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

        slow_mvwprintw(tela_flashback, "Silêncio.", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "Pesado.", y + 9, start_text, 20);
        slow_mvwprintw(tela_flashback, "Definitivo.", y + 10, start_text, 20);

        napms(800);

        slow_mvwprintw(tela_flashback, "Atlas ficou olhando por alguns segundos.", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "Sem emoção.", y + 13, start_text, 20);
        slow_mvwprintw(tela_flashback, "Só leitura.", y + 14, start_text, 20);

        napms(800);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "[Atlas]", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "-Agora você entende o suficiente para ser útil… e não o bastante para ser perigoso sozinho.", y+1, start_text, 20);
        napms(800);

        slow_mvwprintw(tela_flashback, "Ele olhou para você.", y + 2, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Você vai ser acusado disso.", y + 4, start_text, 20);
        napms(1200);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "— Regicídio. Dentro da cela da masmorra. Com suas armas.", y + 5, start_text, 80);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        napms(1500);

        slow_mvwprintw(tela_flashback, "O ar ficou denso.", y + 6, start_text, 20);
        slow_mvwprintw(tela_flashback, "— E ninguém vai olhar duas vezes.", y + 7, start_text, 20);
        slow_mvwprintw(tela_flashback, "Ele se aproximou um pouco mais.", y + 8, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Porque você já perdeu credibilidade antes disso.", y + 9, start_text, 20);

        napms(1200);

        slow_mvwprintw(tela_flashback, "Silêncio.", y + 11, start_text, 20);
        slow_mvwprintw(tela_flashback, "E então a última peça.", y + 12, start_text, 20);
        slow_mvwprintw(tela_flashback, "— Seu pai foi executado pelo Rei porque deixou de ser funcional ao sistema.", y + 13, start_text, 20);
        napms(1500);
        slow_mvwprintw(tela_flashback, "— E agora você vai carregar o mesmo rótulo dele.", y + 15, start_text, 20);

        napms(1500);

        werase(tela_flashback);
        box(tela_flashback, 0, 0);
        wrefresh(tela_flashback);

        slow_mvwprintw(tela_flashback, "Ele virou levemente o rosto, como se já estivesse saindo da cena.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "— O mundo não vai lembrar de você como pessoa.", y + 1, start_text, 20);
        napms(1500);

        slow_mvwprintw(tela_flashback, "— Só como consequência.", y + 2, start_text, 20);
        napms(1500);

        slow_mvwprintw(tela_flashback, "— Vou me certificar que o mundo esqueça de você, eu vou ser um fundador de", y + 4, start_text, 20);
        slow_mvwprintw(tela_flashback, "uma nova PE, que obedeça somente a mim, e se esqueça das repressões e dos", y + 5, start_text, 20);
        slow_mvwprintw(tela_flashback, "revolucionários anteriores para um novo mundo que não saiba ir contra o sistema que eu vou governar.", y + 6, start_text, 20);

        napms(2500);
        werase(tela_flashback);
        wrefresh(tela_flashback);

        wattron(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));
        slow_mvwprintw(tela_flashback, "Após se lembrar desse momento, seu foco retorna às escadas à sua frente.", y, start_text, 20);
        slow_mvwprintw(tela_flashback, "Ao quinto andar.", y + 1, start_text, 20);
        wattroff(tela_flashback, A_BOLD | COLOR_PAIR(COR_DESTAQUE));

        wrefresh(tela_flashback);
        napms(2000);

        break;
        
    default:
        break;
    }
    apagar_janela(tela_flashback);
    return ;
}