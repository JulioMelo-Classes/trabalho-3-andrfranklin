#include "../include/Level.h"
#include "../include/Maze.h"

#include <vector>

using namespace std;

    /**
    * @brief construtor para um level
    * @param Maze maze para o labirinto do level
    * @param int qttFruits para a quantidade de frutas do jogo
    * @param int pIL para a posição inicial da cobra na linha
    * @param int pIC para a posição inicial da cobra na coluna
    **/
    Level::Level(Maze maze_, int qttFruits_, int pIL, int pIC){
        maze = maze_;
        qttFruits = qttFruits_;
        snakeInitialPosition.first = pIL;
        snakeInitialPosition.second = pIC; 
    }

    /**
    * @brief get para a quantidade de frutas do level
    * @return inteiro de quantidade de frutas no level
    **/
    int Level::getQttFruits(){
        return qttFruits;
    }

    /**
    * @brief get para o labirinto do level
    * @return objeto Maze do level
    **/
    Maze Level::getMaze(){
        return maze;
    }


    /**
    * @brief get para a posição inicial da cobra no labirinto do level
    * @return pair de inteiros <linha, coluna>
    **/
    pair<int,int> Level::getInitialPosition(){
        return snakeInitialPosition;
    }