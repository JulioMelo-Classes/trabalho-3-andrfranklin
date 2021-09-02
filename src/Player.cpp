#include "../include/Player.h"
#include "../include/Snake.h"
#include "../include/Maze.h"

#include "vector"
#include "iostream"

using namespace std;

/**
* @brief construtor padrão para um jogador
**/
Player::Player() {}

/**
* @brief método que encontra um caminho para que a cobra encontre a comida
* @param pair_intL_intC de inteiros para a posição da cabeça da cobra
* @param vector de inteiros do labirinto do jogo
**/
bool Player::findSolution(pair<int, pair<int, int>> head_, vector<vector<int>> labirinto)
{
    hasSolution = false;
    return false;
}

/**
* @brief método que realiza o próximo movimento da cobra
* @param Snake objeto para realizar a ação da cobra
**/

/*
Como conversamos, acho que daria para otimizar um pouco esse método, mas está ok.

Encotrei um bug no mapa maze2.txt, a cobra nunca se move, como se ficasse girando para os lados e nunca movesse.
Nesse caso diz respeito à restrição da cobra nunca poder voltar, como você implementou ela, pode ser um bug.
*/
int Player::nextMove(Snake &s, Maze labirinto)
{
    // if (directions.size() < 1)
    // {
    //     s.move(1);
    // }else{

    // }

    vector<vector<int>> lab = labirinto.getBinaryWalls();
    int lH = s.getHeadLocal().second.first;
    int cH = s.getHeadLocal().second.second;
    switch (s.getHeadLocal().first)
    {
    case 1: //cobra olhando para cima
        if (lab[lH - 1][cH] != 0 && lab[lH][cH - 1] != 0 && lab[lH][cH + 1] != 0)
        { //se não existir parede a frente nem dos lados da cobra, escolha uma ação
            vector<int> choice = {1,2,3};
            return choice[rand() % 3];
        }
        else if (lab[lH - 1][cH] != 0) //se não existir parede a frente da cobra, siga em frente
        {
            return 1;
        }
        else if (lab[lH][cH - 1] != 0 && lab[lH][cH + 1] != 0) // se não existir parede dos lados, escolha entre virar para a esquerda ou direita
        {
            vector<int> choice = {2,3};
            return choice[rand() % 2];
        }
        else if (lab[lH][cH - 1] != 0) //se só existir caminho para a esquerda da cobra, vire a esquerda
        {
            return 2;
        }
        else if (lab[lH][cH + 1] != 0) //se só existir caminho para a direita da cobra, vire a direita
        {
            return 3;
        }
        break;

    case 2: //cobra olhando para a esquerda
        if (lab[lH][cH - 1] != 0 && lab[lH - 1][cH] != 0 && lab[lH + 1][cH] != 0)
        { //se não existir parede a frente nem dos lados da cobra, escolha uma ação
            vector<int> choice = {1,2,3};
            return choice[rand() % 3];
        }
        else if (lab[lH][cH - 1] != 0) //se não existir parede a frente da cobra, siga em frente
        {
            return 1;
        }
        else if (lab[lH - 1][cH] != 0 && lab[lH + 1][cH] != 0) // se não existir parede dos lados, escolha entre virar para a esquerda ou direita
        {
            vector<int> choice = {2,3};
            return choice[rand() % 2];
        }
        else if (lab[lH + 1][cH] != 0) //se só existir caminho para a esquerda da cobra, vire a esquerda
        {
            return 2;
        }
        else if (lab[lH - 1][cH] != 0) //se só existir caminho para a direita da cobra, vire a direita
        {
            return 3;
        }
        break;

    case 3: //cobra olhando para a direita
        if (lab[lH][cH + 1] != 0 && lab[lH - 1][cH] != 0 && lab[lH + 1][cH] != 0)
        { //se não existir parede a frente nem dos lados da cobra, escolha uma ação
            vector<int> choice = {1,2,3};
            return choice[rand() % 3];
        }
        else if (lab[lH][cH + 1] != 0) //se não existir parede a frente da cobra, siga em frente
        {
            return 1;
        }
        else if (lab[lH - 1][cH] != 0 && lab[lH + 1][cH] != 0) // se não existir parede dos lados, escolha entre virar para a esquerda ou direita
        {
            vector<int> choice = {2,3};
            return choice[rand() % 2];
        }
        else if (lab[lH - 1][cH] != 0) //se só existir caminho para a esquerda da cobra, vire a esquerda
        {
            return 2;
        }
        else if (lab[lH + 1][cH] != 0) //se só existir caminho para a direita da cobra, vire a direita
        {
            return 3;
        }
        break;

    case 4: //cobra olhando para baixo
        if (lab[lH + 1][cH] != 0 && lab[lH][cH + 1] != 0 && lab[lH][cH - 1] != 0)
        { //se não existir parede a frente nem dos lados da cobra, escolha uma ação
            vector<int> choice = {1,2,3};
            return choice[rand() % 3];
        }
        else if (lab[lH + 1][cH] != 0) //se não existir parede a frente da cobra, siga em frente
        {
            return 1;
        }
        else if (lab[lH][cH + 1] != 0 && lab[lH][cH - 1] != 0) // se não existir parede dos lados, escolha entre virar para a esquerda ou direita
        {
            vector<int> choice = {2,3};
            return choice[rand() % 2];
        }
        else if (lab[lH][cH + 1] != 0) //se só existir caminho para a esquerda da cobra, vire a esquerda
        {
            return 2;
        }
        else if (lab[lH][cH - 1] != 0) //se só existir caminho para a direita da cobra, vire a direita
        {
            return 3;
        }
        break;
    }
    return 1;
}

/**
* @brief método que retorna se uma solução já existe armazenada na memória do jogador
**/
bool Player::getHasSolution()
{
    return hasSolution;
}