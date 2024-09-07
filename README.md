# so_long

`so_long` é um projeto simples em 2D desenvolvido como parte do currículo da 42 School. O objetivo do jogo é coletar todos os itens (coletáveis) no mapa e chegar à saída sem ser derrotado por inimigos ou ficar preso.

## Índice

- [Sobre o Projeto]
- [Requisitos]
- [Autoria](jmiguel)

## Sobre o Projeto

O jogo é inspirado em jogos clássicos de labirinto. O jogador controla um personagem que deve se mover em um mapa, coletando itens e procurando a saída, tudo isso evitando armadilhas ou obstáculos. O mapa é definido em arquivos `.ber`, que são lidos pelo programa para gerar o cenário do jogo.

## Requisitos

- **MiniLibX**: Biblioteca gráfica usada para criar a janela do jogo e desenhar os gráficos. Certifique-se de ter a MiniLibX instalada e configurada corretamente no seu sistema.
- **GNU make**: Usado para compilar o projeto.
- **gcc**: Compilador C.

### Dependências

- Instale a MiniLibX e o X11, se ainda não estiverem instalados:
  ```bash
  sudo apt-get install libmlx-dev libxext-dev libx11-dev
Como Compilar:
-Clone o repositório para sua máquina local:
    git clone https://github.com/seu-usuario/so_long.git
  
