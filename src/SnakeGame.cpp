#include "SnakeGame.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(ifstream &file)
{
    choice = "";
    frameCount = 0;
    initialize_game(file);
}

void SnakeGame::initialize_game(ifstream &levelFile)
{
    int lineCount = 0;
    level = 1;
    vector<int> startlevel;
    string line;

    int width = 0, height = 0, apples = 0, pIX = 0, pIY = 0;
    vector<string> tempMaze;

    if (levelFile.is_open())
    {
        while (getline(levelFile, line))
        { //pega cada linha do arquivo
            if (line[0] != '#' && line[0] != '.' && line[0] != ' ' && line[0] != '\0')
            {
                stringstream s(line);
                string world;
                vector<string> data;
                while (s >> world)
                {
                    data.push_back(world);
                }

                width = stoi(data[0]);
                height = stoi(data[1]);
                apples = stoi(data[2]);

                int findX = 0;
                while (getline(levelFile, line))
                {
                    if (line[0] != '#' && line[0] != '.')
                    {
                        break;
                    }

                    findX++;
                    for (int p = 0; p < line.size(); p++)
                    {
                        if (line[p] == '*')
                        {
                            pIY = p;
                            pIX = findX - 1;
                        }
                    }
                    tempMaze.push_back(line);
                    lineCount++;
                }

                levelFile.clear();
                levelFile.seekg((lineCount - 1), ios::beg);
                Maze m(width, height, tempMaze);
                Level l(m, apples, pIX, pIY);
                levels.push_back(l);
                tempMaze.clear();
            }
            lineCount++;
        }
    }

    //gera uma nova comida no labirinto
    this->newFood();

    state = RUNNING;
}

void SnakeGame::process_actions()
{
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch (state)
    {
    case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
        cin >> std::ws >> choice;
        break;
    case RUNNING: //
        if (!snake.getMovedState())
        {
            pair<int, int> lC = levels[level - 1].getInitialPosition();
            pair<int, pair<int, int>> toHead;
            toHead.first = 1;
            toHead.second = lC;
            Snake s(toHead, 5);
            snake = s;
        }

        // if (playerS.getHasSolution() == false)
        // {
        //     playerS.findSolution(snake.getHeadLocal(), levels[level-1].getMaze().getBinaryWalls());
        // }else{
        // }
        break;
    default:
        //nada pra fazer aqui
        break;
    }
}

void SnakeGame::update()
{
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch (state)
    {
    case RUNNING:
        //if (frameCount > 0 && frameCount % 10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
        //    state = WAITING_USER;

        //move a cobra pelo labirinto
        snake.move(playerS.nextMove(snake, levels[level-1].getMaze()));

        //valida se a cobra bateu no muro
        this->isOver();

        //verifica se a cobra comeu a comida
        if(snake.getHeadLocal().second.first == food.getPosition().first && snake.getHeadLocal().second.second == food.getPosition().second){
            food.setState();
            score = score + 10;
        }

        //valida se tem comida no mapa
        if (food.getState())
        {
            this->newFood();
        }
        break;
    case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
        if (choice == "n")
        {
            state = GAME_OVER;
            game_over();
        }
        else
        {
            //pode fazer alguma coisa antes de fazer isso aqui
            state = RUNNING;
        }
        break;
    default:
        //nada pra fazer aqui
        break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen()
{
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render()
{
    clearScreen();
    int width = levels[level - 1].getMaze().getDimensions().first;
    int height = levels[level - 1].getMaze().getDimensions().second;
    switch (state)
    {
    case RUNNING:
        cout<<"Life: ";
        for (int i = 0; i < snake.getLife(); i++)
        {
            cout<<"♥";
        }
        cout<<" | ";
        cout<<"Score: " << score;
        cout<<" | ";
        cout<<endl;

        //desenha todas as linhas do labirinto
        for (int l = 0; l < width - 1; l++)
        {

            for (int c = 0; c < height; c++)
            {
                //verifica se há paredes invisíveis e imprime um espaço no local
                char mazeToPrint = levels[level - 1].getMaze().getWalls()[l][c];
                if (mazeToPrint == '.')
                {
                    cout << ' ';
                }
                else if (snake.getHeadLocal().second.first == l && snake.getHeadLocal().second.second == c)
                {
                    switch (snake.getHeadLocal().first)
                    {
                    case 1:
                        cout << "v";
                        break;
                    case 2:
                        cout << ">";
                        break;
                    case 3:
                        cout << "<";
                        break;
                    case 4:
                        cout << "^";
                        break;
                    }
                }
                else if (food.getPosition().first == l && food.getPosition().second == c)
                {
                    cout <<"•";
                }
                else
                {
                     cout<<mazeToPrint;
                }
            }
            cout << endl;
        }

        break;
    case WAITING_USER:
        cout << "Você quer continuar com o jogo? (s/n)" << endl;
        break;
    case GAME_OVER:
        cout << "O jogo terminou da seguinte maneira:" << endl;
        cout<<"Life: ";
        for (int i = 0; i < snake.getLife(); i++)
        {
            cout<<"♥";
        }
        cout<<" | ";
        cout<<"Score: " << score;
        cout<<" | ";
        cout<<endl;
        break;
    }
    frameCount++;
}

void SnakeGame::game_over()
{
    Player p;
    playerS = p;
    pair<int, pair<int, int>> s;
    s.first = 1;
    s.second.first = 0;
    s.second.second = 0;
    snake.newDefault(s, snake.getLife());
    Food f;
    food = f;
    frameCount = 0;

    for (int i = 0; i < levels.size(); i++)
    {
        levels.pop_back();
    }
    

    // level = 0;
    // score = 0;
}

void SnakeGame::loop()
{
    while (state != GAME_OVER)
    {
        process_actions();
        update();
        render();
        wait(1000); // espera 1 segundo entre cada frame
    }
}

/**
* @brief gera uma nova posição para a comida
**/
void SnakeGame::newFood()
{
    int l = food.getPosition().first || 0;
    int c = food.getPosition().second || 0;

    while (true)
    {
        int tempL = rand() % levels[level - 1].getMaze().getDimensions().first;
        int tempC = rand() % levels[level - 1].getMaze().getDimensions().second;

        if (tempL != l && tempC != c)
        {
            char tempPL = levels[level - 1].getMaze().getWalls()[tempL][tempC];
            if (tempPL != '#' && tempPL != '.')
            {
                pair<int, int> newLocal;
                newLocal.first = tempL;
                newLocal.second = tempC;
                Food f(newLocal);
                food = f;
                break;
            }
        }
    }
}

/**
* @brief valida se a cobra bateu no labirinto
**/
void SnakeGame::isOver(){
    int l = snake.getHeadLocal().second.first;
    int c = snake.getHeadLocal().second.second;

    if (levels[level-1].getMaze().getWalls()[l][c] == '#')
    {
        snake.die();

        if (snake.getLife() == 0)
        {
            state = GAME_OVER;
        }else{
            pair<int, pair<int, int>> newRound;
            newRound.first = 1;
            newRound.second = levels[level-1].getInitialPosition();
            snake.newDefault(newRound, snake.getLife());
        }
    }
}