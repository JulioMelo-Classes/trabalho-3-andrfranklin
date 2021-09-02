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

## Avaliação CP1

1. Snake/Pacman: O jogo deveria conter o modo snake/pacman. 50% Apenas o modo pacman foi entregue.
2. Render.ui: O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score. OK 
3. Render.mapa: O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok
4. Render.snake: O jogo deveria desenhar a snake corretamente. Ok
5. Transição de mapas: O jogo deve ter transição de mapa uma vez que um mapa é terminado. Não implementado.
6. Interação com o usuário: O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada
transição de mapa. Não feito 0%.
7. Classe Level ou similar: O software deve encapsular as funcionalidades do nível em uma classe. OK
8. Classe Player ou similar: O software deve encapsular as decisões do jogo em uma classe. OK
9. Classe Snake ou similar: O software deve encapsular as funcionalidades relacionadas à snake em uma classe. OK

## Comentários gerais CP1

- Faltou documentar alguns atributos, além disso não colocamos documentação nos .cpp. A tabulação nos .cpp está errada. Imagino que vc tenha colocado o tab por causa do `using namespace ...` mas esse tab não existe.
- Acho que a divisão de tarefas entre as classes ficou muito boa, porém eu colocaria ainda o carregamento do arquivo pra ficar em Level, de alguma forma e não dentro de SnakeGame.