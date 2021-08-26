#include "../include/Player.h"
#include "../include/Snake.h"

#include "vector"

using namespace std;

/**
* @brief construtor padrão para um jogador
**/
Player::Player(){}

/**
* @brief método que encontra um caminho para que a cobra encontre a comida
* @param pair_intL_intC de inteiros para a posição da cabeça da cobra
* @param vector de inteiros do labirinto do jogo
**/
bool Player::findSolution(pair<int, pair<int, int>> head_, vector<vector<int>> labirinto){
    hasSolution = false;
    return false;
}

/**
* @brief método que realiza o próximo movimento da cobra
* @param Snake objeto para realizar a ação da cobra
**/
void Player::nextMove(Snake &s){
    if (directions.size() < 1)
    {
        s.move(1);
    }else{

    }
    
}


/**
* @brief método que retorna se uma solução já existe armazenada na memória do jogador
**/
bool Player::getHasSolution(){
    return hasSolution;
}