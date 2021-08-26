#include "../include/Maze.h"

using namespace std;

/**
* @brief construtor para um labirinto
**/
Maze::Maze(){}

/**
* @brief construtor para um labirinto
* @param int width para a largura do labirinto
* @param int height para a altura do labirinto
* @param vetor maze para o labirinto
**/
Maze::Maze(int width_,int height_, vector<string> maze_){
    dimensions.first = width_;
    dimensions.second = height_;

    for (int l = 0; l < maze_.size(); l++)
    {
        for (int c = 0; c < maze_[l].size(); c++)
        {
            if (maze_[l][c] == '*')
            {
                maze_[l][c] = ' ';
            }
        }    
        walls.push_back(maze_[l]);
    }

    for (int l = 0; l < maze_.size(); l++)
    {
        vector<int> tempLine;
        for (int c = 0; c < maze_[l].size(); c++)
        {
            if (maze_[l][c] == '#' || maze_[l][c] == '.')
            {
                tempLine.push_back(0);
            }else{
                tempLine.push_back(1);
            }
        }
        binaryWalls.push_back(tempLine);
    }
    
}

/**
* @brief get para as dimenções do labirinto
* @return pair com inteiros para a <largura, altura>
**/
pair<int, int> Maze::getDimensions(){
    return dimensions;
}

/**
* @brief get para o labirinto em formato de string
* @return vetor de string
**/
vector<string> Maze::getWalls(){
    return walls;
}

/**
* @brief get para o labirinto em formato de inteiros binários
* @return vetor de inteiros
**/
vector<vector<int>> Maze::getBinaryWalls(){
    return binaryWalls;
}