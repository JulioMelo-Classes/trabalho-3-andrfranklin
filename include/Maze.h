#ifndef Maze_h
#define Maze_h

#include <vector>
#include <string>

class Maze
{
private:
    std::pair<int, int> dimensions; //<! pair de inteiros que representam <altura, largura> do labirinto
    std::vector<std::string> walls; //<! vetor de string que representa as paredes do labirinto
    std::vector<std::vector<int>> binaryWalls; //<! vetor de inteiros que representa as paredes do labirinto de forma binária sendo 0 uma parede e 1 um local aberto
public:
    
    /**
    * @brief construtor para um labirinto
    **/
    Maze();

    /**
    * @brief construtor para um labirinto
    * @param int width para a largura do labirinto
    * @param int height para a altura do labirinto
    * @param vetor maze para o labirinto
    **/
    Maze(int width_,int height_, std::vector<std::string> maze_);

    /**
    * @brief get para as dimenções do labirinto
    * @return pair com inteiros para a <largura, altura>
    **/
    std::pair<int, int> getDimensions();

    /**
    * @brief get para o labirinto em formato de string
    * @return vetor de string
    **/
    std::vector<std::string> getWalls();

    /**
    * @brief get para o labirinto em formato de inteiros binários
    * @return vetor de inteiros
    **/
    std::vector<std::vector<int>> getBinaryWalls();
};

#endif