#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define FALHA 1
#define PONTEIRO_INVALIDO -1

// Escreva um programa que armazene alunos de uma faculdade, juntamente com sua nota final em uma disciplina, usando a estrutura abaixo.
// Faça um programa principal que contenha um menu com as seguintes opções:
// Cadastrar aluno;
// Remover aluno;
// Listar alunos cadastrados;
// Mostrar dados do aluno com maior nota;
// Remover todos os alunos;
// Sair.
// Considere que os alunos devem ser armazenados em ordem crescente de matrícula.
typedef struct
{
    char nome[30];
    int matricula;
    float nota;
} Aluno;

typedef struct no
{
    Aluno estudante;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct
{
    No *inicio;
} Lista;

Lista * criar()
{
    Lista *nova_lista = (Lista *) malloc(sizeof(Lista));
    nova_lista->inicio = NULL;
    return nova_lista;
}

int inserir_inicio(Lista *lista, Aluno aluno)
{
    if (lista == NULL)
        return PONTEIRO_INVALIDO;

    No *no = (No *) malloc(sizeof(No));

    no->estudante = aluno;

    no->proximo = lista->inicio;
    no->anterior = NULL;
    if (lista->inicio != NULL)
        lista->inicio->anterior = no;
    
    lista->inicio = no;

    return SUCESSO;
}

void adicionar_struct(Aluno *aluno, char *nome, int matricula, float nota)
{
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->nota = nota;
}

int mostrar_lista(Lista *lista)
{
    if ((lista == NULL) || (lista->inicio == NULL))
        return FALHA;
    
    No *no = lista->inicio;
    while (no != NULL)
    {
        printf("[ %s, %d, %g ] ", no->estudante.nome, no->estudante.matricula, no->estudante.nota);
        no = no->proximo;
    }
    printf("\n");
    return SUCESSO;
}

int inserir_fim(Lista *lista, Aluno aluno)
{
    if (lista == NULL)
        return PONTEIRO_INVALIDO;
    
    if (lista->inicio == NULL)
        return inserir_inicio(lista, aluno);
    
    No *aux = lista->inicio;

    while (aux->proximo != NULL)
        aux = aux->proximo;
    
    No *no = (No *) malloc(sizeof(No));

    no->estudante = aluno;
    no->proximo = aux->proximo;
    no->anterior = aux;
    aux->proximo = no;

    return SUCESSO;
}

int remover_inicio(Lista *lista)
{
    if ((lista == NULL) || (lista->inicio == NULL))
        return PONTEIRO_INVALIDO;
    
    No *aux = lista->inicio;

    lista->inicio = lista->inicio->proximo;
    lista->inicio->anterior = NULL;

    free(aux);

    return SUCESSO;
}

int remover_fim(Lista *lista)
{
    if ((lista == NULL) || (lista->inicio == NULL))
        return PONTEIRO_INVALIDO;
    
    No *no = lista->inicio;
   
    while (no->proximo != NULL)
        no = no->proximo;
    
    No *aux = no;
    
    no = no->anterior;
    no->proximo = NULL;
    free(aux);

    return SUCESSO;
}

int tamanho(Lista *lista)
{
    if ((lista == NULL))
        return PONTEIRO_INVALIDO;
    
    if (lista->inicio == NULL)
        return 0;


    No *no = lista->inicio;
    int contador = 0;

    while (no != NULL)
    {
        no = no->proximo;
        contador++;
    }
    
    return contador;
}

int remover_posicao(Lista *lista, int posicao)
{
    if ((lista == NULL) || (lista->inicio == NULL))
        return PONTEIRO_INVALIDO;

    if (posicao <= 0)
        return FALHA;
    
    No *no = lista->inicio;
    No *aux = NULL;
    int contador = 1;
    while ((contador < posicao) && (no->proximo != NULL))
    {
        contador++;
        aux = no;
        no = no->proximo;
    }
    aux->proximo = no->proximo;
    no->proximo->anterior = aux;

    free(no);

    return SUCESSO;
}

int inserir_posicao(Lista *lista, Aluno aluno, int posicao)
{
    if (lista == NULL)
        return PONTEIRO_INVALIDO;
    
    if (posicao == 0)
        inserir_inicio(lista, aluno);
    
    No *aux = lista->inicio;
    int contador = 1;

    while ((aux->proximo != NULL) && (contador < posicao))
    {
        contador++;
        aux = aux->proximo;
    }

    No *no = (No *) malloc(sizeof(No));
    no->estudante = aluno;

    no->proximo = aux->proximo;
    no->anterior = aux;
    aux->proximo = no;
    no->proximo->anterior = no;
    
    
    return SUCESSO;
}

int buscar_item(Lista *lista, int matricula)
{   
    if ((lista == NULL) || (lista->inicio == NULL))
        return PONTEIRO_INVALIDO;

    No *aux = lista->inicio;
    int contador = 1;

    while (aux->estudante.matricula != matricula && aux != NULL)
    {
        aux = aux->proximo;
        contador++;
    }

    if (aux == NULL)
        return 0;
    
    return contador;
}

int buscar_posicao(Lista *lista, Aluno *aluno, int posicao)
{
    No *no = lista->inicio;
    int contador = 1;

    while ((contador < posicao) && (no != NULL))
    {
        contador++;
        no = no->proximo;
    }
    
    if (no == NULL)
        return FALHA;
    
    *aluno = no->estudante;

    return SUCESSO;
}

int lista_vazia(Lista *lista)
{
    if (lista == NULL)
        return 2;
    
    if (lista->inicio != NULL)
        return 1;
    
    return 0;
}

int limpar_lista(Lista *lista)
{
    if (lista == NULL || lista->inicio == NULL)
        return PONTEIRO_INVALIDO;
    
    while (lista_vazia(lista) != 0)
        remover_inicio(lista);
    
    free(lista);
    
    return SUCESSO;
}


int
main()
{
    Lista *lista = NULL;
    Aluno aluno;

    lista = criar();

    if (lista == NULL)
        printf("A lista nao pode ser alocada!\n");

    
    printf("Adicionando 3 no inicio:\n");
    adicionar_struct(&aluno, "AlbanaqueNey", 100, 10);
    inserir_inicio(lista, aluno);
    printf("teste\n");
    adicionar_struct(&aluno, "BigBrainNey", 150, 13);
    inserir_inicio(lista, aluno);

    adicionar_struct(&aluno, "ClauClau", 170, 500);
    inserir_inicio(lista, aluno);

    mostrar_lista(lista);


    printf("Adicionando 2 no fim:\n");
    adicionar_struct(&aluno, "Didi", 180, 27);
    inserir_fim(lista, aluno);

    adicionar_struct(&aluno, "EstiloNey", 90, 67.7);
    inserir_fim(lista, aluno);

    mostrar_lista(lista);

    printf("Removendo Inicio:\n");
    remover_inicio(lista);
    mostrar_lista(lista);


    printf("Removendo fim:\n");
    remover_fim(lista);
    mostrar_lista(lista);

    printf("O tamanho da lista eh: %d\n", tamanho(lista));


    printf("Removendo Posicao 2:\n");
    remover_posicao(lista, 2);
    mostrar_lista(lista);

    printf("Adicionando Posicao 1:\n");
    adicionar_struct(&aluno, "FabulosoNey", 450, 18.9);
    inserir_posicao(lista, aluno, 1);
    mostrar_lista(lista);

    printf("A posicao do aluno com matricula 450 eh: %d\n", buscar_item(lista, 450));

    buscar_posicao(lista, &aluno, 3);
    printf("Aluno encontrado: [ %s, %d, %g ] \n", aluno.nome, aluno.matricula, aluno.nota);

    printf("Limpar lista:\n");
    limpar_lista(lista);

    mostrar_lista(lista);
    
    return 0;
}