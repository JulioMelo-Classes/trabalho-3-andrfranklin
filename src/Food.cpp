#include "../include/Food.h"

#include <vector>

using namespace std;

    /**
     * @brief construtor padrão da classe food
     **/
    Food::Food(){
        wasEaten = false;
    }

    /**
     * @brief construtor padrão da classe food
     **/
    Food::Food(pair<int, int> position_){
        wasEaten = false;
        position = position_;
    }

    /**
     * @brief get para a posição da fruta
     * @return pair de interios <linha, coluna>
     **/
    pair<int, int> Food::getPosition(){
        return position;
    }

    /**
     * @brief set para o estado da fruta
     **/
    void Food::setState(){
        wasEaten = true;
    }

    /**
     * @brief get para o estado da fruta
     * @return bool para o estado da fruta
     **/
    bool Food::getState(){
        return wasEaten;
    }