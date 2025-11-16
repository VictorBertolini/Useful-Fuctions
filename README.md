# Useful-Fuctions

Este repositório contém dois pequenos programas escritos em C durante o início da minha graduação.  
Eles não representam código avançado, mas estão aqui para manter o repositório organizado e registrar parte da minha evolução com a linguagem.

---

## 1. Criador e Destruidor de Arquivos (`FileCreator.c`)

Este programa permite:

### Criar arquivos sequenciais
Ele gera arquivos no formato:
Ex_1.c
Ex_2.c
Ex_3.c
....


Cada arquivo é criado já com um **template básico em C**, contendo:

```c
#include <stdio.h>

int main() {
    return 0;
}
```
 
### E excluir vários arquivos de uma vez

Pode informar um índice inicial (Ex_10.c) definir quantos arquivos deletar a partir dele 

O programa cuida de formatar os nomes e remover os arquivos automaticamente.


### Problema solucionado
No início da faculdade, eu recebia inúmeras listas de exercícios para fazer, e era muito chato criar 50/60/70 exercícios por lista na mão, então eu criei esse software para me auxiliar a criar todos já com uma parte base de `int main()` para programar mais rapidamente sem essa criação sem precedentes de arquivos. E adicionei um função de remover arquivos no caso de caso o usuário crie mais arquivos que precise, há um meio fácil de apagar todos sem excluir um a um ou mesmo ter que abrir o gerenciador de arquivos na pasta exata para fazer a operação. 


--- 
## 2. Medidor de Tempo de Execução (TimeMeasure.c)

Pequeno utilitário que mede o tempo de execução de um trecho de código usando clock().

Basta escrever seu algoritmo dentro da área indicada e ao final o programa escreve na tela o tempo medido em milissegundos


--- 
### Autor

Victor Bertolini de Sousa
Estudante de Ciência da Computação















