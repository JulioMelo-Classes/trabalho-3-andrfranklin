#include "../include/Snake.h"

#include "iostream"
#include "vector"
#include "string"

using namespace std;
/**
* @brief construtor padrão para um objeto Snake
**/
Snake::Snake(){
    moved = false;
}

/**
* @brief construtor padrão para um objeto Snake
* @param pair_intL_intC de inteiros para a posição inicial da cabeça da cobra
* @param int com a quantidade de vidas da cobra
**/
Snake::Snake(pair<int, pair<int,int>> head_, int life_ ){
    head = head_;
    life = life_;
    moved = false;
}

/**
* @brief método que adiciona um novo anel a calda da cobra
**/
void Snake::eat(){
    
}

/**
* @brief método que remove uma vida da cobra
**/
void Snake::die(){
    life -= 1;
}

/**
* @brief método que muda o objeto para novos valores padrão para o level
* @param pair_intL_intC de inteiros para a nova posição inicial da cabeça da cobra
* @param int com a nova quantidade de vidas da cobra
**/
void Snake::newDefault(std::pair<int, std::pair<int,int>> head_, int life_ ){
    head = head_;
    life = life_;
}

/**
* @brief método que realiza os movimentos da cobra
* @param int para a próxima ação da cobra
**/
void Snake::move(int action){

    cout<<action<<endl;

    switch (action)
    {
    case CONTINUE:
        moved = true;



        switch (head.first)
        {
        case UP:
            cout<<"subindo"<<endl;
            cout<<"linha: "<< head.second.first <<", coluna: " << head.second.second << endl;
            // this->head.second.first -= 1;
            head.second.first -= 1;
            break;
        
        case DOWN:
            head.second.first += 1;
            break;

        case LEFT:
            head.second.second -= 1;
            break;

        case RIGHT:
            head.second.second += 1;
            break;
        }
        break;
    
    case TURN_L:
        
        break;

    case TURN_R:
        
        break;
    }
}


/**
* @brief método que retorna se a cobra já se moveu no labirinto ou não
**/
bool Snake::getMovedState(){
    return moved;
}

/**
* @brief método que retorna um par de <int, par<int,int> de valores inteiros para a posição da cabeça da cobra
* @return pair <int, pair<int,int>> de inteiros
**/
pair<int, pair<int,int>> Snake::getHeadLocal(){
    return head;
}

/**
* @brief método que retorna um par de valores inteiros para a posição da cabeça da cobra
* @return pair de inteiros
**/
std::vector<std::pair<int,int>> Snake::getTailLocal(){
    return tail;
}

/**
* @brief método que retorna um inteiro da quantidade de vida da cobra
* @return inteiro da quantidade de vida da cobra
**/
int Snake::getLife(){
    return life;
}