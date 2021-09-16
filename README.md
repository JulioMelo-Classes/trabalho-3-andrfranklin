# Trabalho 3: Snaze game

### trabalho final da disciplina de linguagem de Programação 1
#### IMD(UFRN) - professor Júlio Melo
#### Aluno - André Franklin de Oliveira Lima
----
**Para compilar e executar siga as instruções abaixo:**

**Para compilar:**


Na raiz do projeto, via terminal, digite:
```
mkdir build
cd build
cmake ../
make
```

**Para executar os testes:**

Na pasta build, via terminal, digite:
```
./snaze ../data/maze1.txt
```

Teste existentes:

O `maze1.txt` possui um caso de teste de impressão para paredes invisíveis, como também para validar a movimentação da cobra no labirinto, e sua morte caso não possua alternativa.

# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

não implementado

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

não implementado

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

não implementado

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

70%, os casos de teste providos realmente não são relevantes...

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

70% não foram documentados os casos de teste relevantes
