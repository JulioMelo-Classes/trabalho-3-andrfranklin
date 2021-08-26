#include <iostream>
#include <fstream>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    SnakeGame game(file);
    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}