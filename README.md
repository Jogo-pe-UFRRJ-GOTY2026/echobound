# Echobound

 
## 💬 Sobre
Este repositório foi criado para conter o código fonte do jogo que denominados **Echobound** feito como avaliação para disciplina de *programação estruturada* na Universidade Federal Rural do Rio de Janeiro.

O jogo visa reproduzir um combate semelhante a Undertale enquanto ainda possui sua história original.

## 🛠️ Tecnologias Utilizadas
- <img alt="C" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" height="20" width="30" /> [C](hhttps://devdocs.io/c/)  
- <img alt="Docker" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/docker/docker-original.svg" height="30" width="40" />[Docker](https://www.docker.com/products/docker-desktop/)



## ✨ Funcionalidades:
- Criação de personagem.
- Salvamento e carregamento de progresso.
- Combate e colisões.
- Escolhas de diferentes diálogos.
- 3 diferentes finais.

## 🚀 Compilação Execução:
Sob um sistema com a instalação da biblioteca `ncurses` disponível:
```sh
git clone https://github.com/Jogo-pe-UFRRJ-GOTY2026/echobound.git
cd Echobound
make
make run
```

A biblioteca ncurses pode ser instalada em sistemas Linux com o comando `apt install -y libncurses-dev` 


## 👥 Colaborações e desenvolvedores
| CARGO | PESSOA |
| ------ | ------ |
| DESENVOLVEDOR | [Pedro Lucas de Oliveira Alves](https://github.com/pedrolucasalvesdev) |
| DESENVOLVEDOR | [Gustavo Luiz da Silva Procópio](https://github.com/GustavoProcopio27) |
| DESENVOLVEDOR | [Pablo Torres Santos da Silva](https://github.com/pabloufrrj)  |

## 🎵 Música:
A música utilizada está armazenada em arquivos `.wav` e funciona em sistemas *Linux* sob a existencia do pacote `aplay`
As faixas utilizados são dos artistas **Matheus de Melo Gomes**, **Laine Chinensy** e **Shadow of Io**.
Os sprites utilizados podem ser encontrados nos repositórios de arte ASCII [ascii.co.uk](https://ascii.co.uk/art) e [asciiart.eu](https://www.asciiart.eu/), sob propriedade dos usuários que os criaram, alguns dos sprites são propriedades do discente Gustavo Luiz.
 

## Árvore do Projeto

```
Trabalho-PE
├─ .devcontainer
│  └─ devcontainer.json
├─ assets
│  ├─ Class_Diagram.asta
│  ├─ diagrama_structs.png
│  ├─ history.md
│  ├─ music
│  │  ├─ aphanos.wav
│  │  ├─ cruciator.wav
│  │  ├─ fallen.wav
│  │  ├─ hollow.wav
│  │  └─ iowa.wav
│  └─ sprites
│     ├─ bosses
│     │  ├─ centaur.txt
│     │  ├─ centaur_admiring_flowers.txt
│     │  ├─ centaur_defeated.txt
│     │  ├─ cerberus.txt
│     │  ├─ cerberus_defeated.txt
│     │  ├─ cerberus_with_bone.txt
│     │  ├─ demon.txt
│     │  ├─ demon_dancing.txt
│     │  ├─ demon_defeated.txt
│     │  ├─ dragon.txt
│     │  ├─ dragon_defeated.txt
│     │  ├─ dragon_sleeping.txt
│     │  ├─ fallen_king.txt
│     │  ├─ hollow.txt
│     │  ├─ hollow_defeated.txt
│     │  ├─ mage.txt
│     │  └─ reaper.txt
│     ├─ buildings
│     │  ├─ save_point.txt
│     │  ├─ terreo.txt
│     │  ├─ topo.txt
│     │  └─ tower.txt
│     ├─ loot
│     │  ├─ axe.txt
│     │  ├─ bow.txt
│     │  ├─ chesplate1.txt
│     │  ├─ chest.txt
│     │  ├─ crossbow.txt
│     │  ├─ flask.txt
│     │  ├─ hammer.txt
│     │  ├─ mace.txt
│     │  ├─ magic_staff.txt
│     │  ├─ magic_staff2.txt
│     │  ├─ magic_wand.txt
│     │  ├─ magic_wand2.txt
│     │  ├─ sabre.txt
│     │  ├─ shield1.txt
│     │  ├─ shield2.txt
│     │  ├─ shield3.txt
│     │  ├─ spear.txt
│     │  ├─ sword1.txt
│     │  ├─ sword2.txt
│     │  └─ trident.txt
│     ├─ others
│     │  ├─ bat.txt
│     │  ├─ boat.txt
│     │  ├─ book.txt
│     │  ├─ bookshelf.txt
│     │  ├─ building1.txt
│     │  ├─ building2.txt
│     │  ├─ sala_vigia.txt
│     │  └─ vigia.txt
│     └─ player
│        ├─ sprite_feminino.txt
│        ├─ sprite_feminino_terminalfix.txt
│        ├─ sprite_masculino.txt
│        └─ sprite_masculino_terminalfix.txt
├─ chapters
│  ├─ CAPITULO.h
│  ├─ Capitulo1.c
│  ├─ Capitulo2.c
│  ├─ Capitulo3.c
│  ├─ Capitulo4.c
│  ├─ Capitulo5.c
│  ├─ Prologo_pt1.c
│  └─ Prologo_pt2.c
├─ dockerfile
├─ Echobound
├─ main.c
├─ makefile
├─ objects
│  ├─ Atributos.h
│  ├─ Inimigo.c
│  ├─ Inimigo.h
│  ├─ Inventario.c
│  ├─ Inventario.h
│  ├─ Player.c
│  └─ Player.h
├─ README.md
├─ Relatorio.md
├─ saves
├─ system
│  ├─ Ataques.c
│  ├─ Combate.c
│  ├─ Combate.h
│  ├─ Save.c
│  └─ Save.h
├─ tests
│  ├─ tests.h
│  ├─ tests_main.c
│  └─ test_systems.c
└─ utils
   ├─ utils.c
   └─ utils.h

```


<!--
sudo apt install mingw-w64
x86_64-w64-mingw32-gcc -o program.exe main.c
-->