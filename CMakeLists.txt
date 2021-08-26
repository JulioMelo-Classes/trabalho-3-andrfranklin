cmake_minimum_required(VERSION 3.5)
project(snazeGame VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .h
include_directories( include )

# Cria um executável com nome "snaze", adiciona neste executável os arquivos ...
add_executable( snaze
                src/Food.cpp 
                src/Maze.cpp 
                src/Level.cpp 
                src/Snake.cpp 
                src/Player.cpp
                src/SnakeGame.cpp 
                src/Snaze.cpp )

# The end
