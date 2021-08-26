#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>

#include "../include/Level.h"
#include "../include/Snake.h"
#include "../include/Food.h"
#include "../include/Player.h"

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        //<! atributos adicione outros se quiser
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        int score; //<! contador de pontos que a cobra fez no jogo
        int level; //<! indicador do level atual do jogo
        std::vector<Level> levels; //<! vetor de levels do jogo
        Snake snake; //<! objeto da cobra do jogo
        Food food; //<! objeto comida do jogo
        Player playerS; //<! objeto player IA da cobra do jogo


    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(std::ifstream &file);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game(std::ifstream &file);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();

        /**
        * @brief gera uma nova posição para a comida
        **/
        void newFood();

        /**
        * @brief valida se a cobra bateu no labirinto
        **/
        void isOver();
};

#endif //SnakeGame_h