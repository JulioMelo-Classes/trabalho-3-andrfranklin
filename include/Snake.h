#ifndef Snake_h
#define Snake_h

#include <vector>

class Snake
{

private:
    enum HeadPosition {
        UP = 1,
        LEFT,
        RIGHT,
        DOWN,
    };
    enum Movements {
        CONTINUE = 1,
        TURN_L,
        TURN_R,
    };
    int life; //<! inteiro para quantidade de vida da cobra
    bool moved;
    std::pair<int, std::pair<int,int>> head; //<! pair para a posição da cabeça da cobra, <linha, coluna>
    std::vector<std::pair<int,int>> tail; //<! vetor de pares para a posição da calda da cobra, [<linha, coluna>]
    
public:
    /**
    * @brief construtor padrão para um objeto Snake
    **/
    Snake();

    /**
    * @brief construtor padrão para um objeto Snake
    * @param pair_intL_intC de inteiros para a posição inicial da cabeça da cobra
    * @param int com a quantidade de vidas da cobra
    **/
    Snake(std::pair<int, std::pair<int,int>> head_, int life_ );

    /**
    * @brief método que adiciona um novo anel a calda da cobra
    **/
    void eat();

    /**
    * @brief método que remove uma vida da cobra
    **/
    void die();

   /**
    * @brief método que muda o objeto para novos valores padrão para o level
    * @param pair_intL_intC de inteiros para a nova posição inicial da cabeça da cobra
    * @param int com a nova quantidade de vidas da cobra
    **/
    void newDefault(std::pair<int, std::pair<int,int>> head_, int life_ );

    /**
    * @brief método que realiza os movimentos da cobra
    * @param int para a próxima ação da cobra
    **/
    void move(int action);

    /**
    * @brief método que retorna se a cobra já se moveu no labirinto ou não
    **/
    bool getMovedState();

    /**
    * @brief método que retorna um par de <int, par<int,int> de valores inteiros para a posição da cabeça da cobra
    * @return pair <int, pair<int,int>> de inteiros
    **/
    std::pair<int, std::pair<int,int>> getHeadLocal();

    /**
    * @brief método que retorna um par de valores inteiros para a posição da cabeça da cobra
    * @return pair de inteiros
    **/
    std::vector<std::pair<int,int>> getTailLocal();

    /**
    * @brief método que retorna um inteiro da quantidade de vida da cobra
    * @return inteiro da quantidade de vida da cobra
    **/
    int getLife();
};


#endif