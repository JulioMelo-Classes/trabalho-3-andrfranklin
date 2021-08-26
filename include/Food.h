#ifndef Food_h
#define Food_h

#include "vector"

class Food
{
private:
    std::pair<int, int> position;
    bool wasEaten;
public:
    /**
     * @brief construtor padrão da classe food
     **/
    Food();

    /**
     * @brief construtor padrão da classe food
     **/
    Food(std::pair<int, int> position_);

    /**
     * @brief get para a posição da fruta
     * @return pair de interios <linha, coluna>
     **/
    std::pair<int, int> getPosition();

    /**
     * @brief set para o estado da fruta
     **/
    void setState();

    /**
     * @brief get para o estado da fruta
     * @return bool para o estado da fruta
     **/
    bool getState();
};

#endif