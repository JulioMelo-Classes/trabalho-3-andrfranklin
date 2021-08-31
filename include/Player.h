#ifndef Player_h
#define Player_h

#include "Snake.h"
#include "Maze.h"

#include "vector"

class Player
{
private:
    int lastDirection;
    bool hasSolution;
    std::vector<std::pair<int, int>> directions;

public:
    /**
    * @brief construtor padrão para um jogador
    **/
    Player();

    /**
    * @brief método que encontra um caminho para que a cobra encontre a comida
    * @param pair_intL_intC de inteiros para a posição da cabeça da cobra
    * @param vector de inteiros do labirinto do jogo
    **/
    bool findSolution(std::pair<int, std::pair<int, int>> head_, std::vector<std::vector<int>> labirinto );

    /**
    * @brief método que realiza o próximo movimento da cobra
    * @param Snake objeto para realizar a ação da cobra
    **/
    int nextMove(Snake &s, Maze labirinto);

    /**
    * @brief método que retorna se uma solução já existe armazenada na memória do jogador
    **/
    bool getHasSolution();

    };

#endif