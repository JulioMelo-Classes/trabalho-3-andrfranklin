#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
#include "./Maze.h"

class Level
{
private:
     Maze maze; //<! labirinto para o level do jogo
     int qttFruits; //<! inteiro que representa quandidade de frutas no level
     std::pair<int, int> snakeInitialPosition;//<! par de inteiros que indica a posição inicial da cobra no level

public:
    /**
    * @brief construtor para um level
    * @param Maze maze para o labirinto do level
    * @param int qttFruits para a quantidade de frutas do jogo
    * @param int pIL para a posição inicial da cobra na linha
    * @param int pIC para a posição inicial da cobra na coluna
    **/
    Level(Maze maze_, int qttFruits_, int pIL, int pIC);

    /**
    * @brief get para a quantidade de frutas do level
    * @return inteiro de quantidade de frutas no level
    **/
    int getQttFruits();

    /**
    * @brief get para o labirinto do level
    * @return objeto Maze do level
    **/
    Maze getMaze();

    /**
    * @brief get para a posição inicial da cobra no labirinto do level
    * @return pair de inteiros <linha, coluna>
    **/
    std::pair<int, int> getInitialPosition();
};

#endif