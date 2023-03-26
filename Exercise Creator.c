#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * !@author Victor Bertolini de Sousa
 * @date 25/03/2023
 * @brief Criador de arquivos .c em ordem e destruidor de arquivos
*/




void
__escreverNoArquivo__(int count);

void
__lerNoArquivo__(char *nome);

void
__criarArquivoExercicio__(char *nome);


int 
main(void)
{
    int quantidade;//Quantidade de exercícios que se deseja abrir
    char nome[10];//Variável para guardar o nome do arquivo
    int verificaOpcao;//Verifica a opção digitada pelo usuário para ler apenas valores válidos
    int opcao;//A opção escolhida pelo usuário, seja criar ou posicaoInicioDestruir arquivos

    int posicaoInicioDestruir;//Variável que vai guardar a posição do primeiro arquivo que será destruído
    int quantidadeDestruir;//Armazena a quantidade de arquivos que serão destruídos

    //Loop de verificação 
    do
    {
        verificaOpcao = 0;
        //MENU para o usuário escolher a opcção que lhe apetece, seja criar ou destruir arquivos
        printf("Selecione uma opção:\n(1) Criar Arquivos\n(2) Destruir Arquivos\n");
        scanf("%d", &opcao);

        //Parte da verificação
        if (opcao < 1 || opcao > 2)
        {
            printf("## OPCAO INVALIDA, FAVOR DIGITAR UM VALOR VALIDO ##");
            verificaOpcao = 1;
        }

    } while (verificaOpcao);

    //Switch para pegar a opção escolhida e encaminhar para as ações corretas
    switch (opcao)
    {
    //Escolha de criar arquivos
    case 1:
        //Loop de verificação
        do
        {
            verificaOpcao = 0;
            //Captar a quantidade de arquivos que se deseja abrir 
            printf("Digite a quantidade de exercicios que deseja abrir: ");
            scanf("%d", &quantidade);

            //verificação
            if (quantidade < 1)
            {
                verificaOpcao = 1;
                printf("\n## DIGITO INVALIDO, FAVOR COLOCAR UM VALOR MAIOR QUE 0 ##\n");
            }
        } while (verificaOpcao);
        
        //Loop para criar a quantidade de arquivos a partir de 3 funções 
        //Cada função é explicada profundamente no local de código respectivo
        for (int count = 1; count <= quantidade; count++)
        {
            //Cria um outro arquivo de texto e escreve o nome do arquivo de exercício
            __escreverNoArquivo__(count);

            //Abre o arquivo texto, lê o nome do arquivo, e coloca em 'nome'
            __lerNoArquivo__(nome);
            
            //Pega o nome do arquivo (que está em 'nome') e cria o arquivo de exercício
            __criarArquivoExercicio__(nome);
        }
        //Remove o arquivo auxiliar para criação e formatação dos arquivos de exercício
        remove("ArquivoTemporario.txt");
        break;
    
    //Escolha de destruir arquivos
    case 2:
        //Loop de verificação (aceita apenas informações acima de 0)
        do
        {
            verificaOpcao = 0;
            //Pega a posição do primeiro arquivo que será destruído
            printf("Qual arquivo sera o primeiro a ser destruido?\n");
            scanf("%d", &posicaoInicioDestruir);

            //parte da verificação
            if (posicaoInicioDestruir < 1)
            {
                printf("\n## O valor deve ser maior que 1 ##\n");
                verificaOpcao = 1;
            }
        } while (verificaOpcao);
        
        //Loop de verificação (aceita apenas informações acima de 0)
        do
        {
            verificaOpcao = 0;
            //pega quantos arquivos serão excluídos ( arquivos excluídos = 'quantidadeDestruir' + 1)
            printf("Quantos arquivos voce quer posicaoInicioDestruir (sem contar com o digitado anteriormente)?");
            scanf("%d", &quantidadeDestruir);
            
            //parte da verificação
            if (quantidadeDestruir < 1)
            {
                printf("\n## O valor deve ser maior que 1 ##\n");
                verificaOpcao = 1;
            }
        } while (verificaOpcao);


        //Pega a posição inicial do arquivo e vai matando um por um seguindo a quantidade informada pelo usuário
        for (int count = posicaoInicioDestruir; count <= (posicaoInicioDestruir + quantidadeDestruir); count++)
        {
            //Escreve o nome formatado do arquivo em um arquivo auxiliar
            __escreverNoArquivo__(count);

            //Lê o nome formatado dentro do arquivo auxiliar e coloca em 'nome'
            __lerNoArquivo__(nome);

            //Com o nome do arquivo, é pego e removido 
            remove(nome);
        }
        break;
    default:
        break;
    }
    
    return 0;
}
/**
 * @brief __escreverNoArquivo__
 * ENTRADA: um número produzido por um 'for' para criar arquivos sequenciais
 * PROCESSAMENTO: escreve no arquivo temporário o nome formatado do arquivo de exercício
 * SAIDA: Não há saída
 *  
*/
void
__escreverNoArquivo__(int count)
{
    FILE *arquivoDeNome;

    //Abrir aquivo
    arquivoDeNome = fopen("ArquivoTemporario.txt", "w");

    //testar se o abrir obteve sucesso
    if (arquivoDeNome == NULL)
    {
        printf("O arquivo 'ArquivoTemporario.txt' não pode ser aberto!\n");
        exit(1);
    }
    
    //Escrevendo dentro dele o texto Ex_1.c , que é o nome dos arquivos de exercícios já tratados
    fprintf(arquivoDeNome, "Ex_%d.c\n", count);

    //fechando arquivo
    fclose(arquivoDeNome);
}

/**
 * @brief __lerNoArquivo__
 * ENTRADA: Um vetor de nome 
 * PROCESSAMENTO: Abrir o arquivo com o nome formatado (do arquivo de exercício)
 *                e armazenar na variável de entrada 'nome'
 * SAIDA: Não há saída
*/
void
__lerNoArquivo__(char *nome)
{
    FILE *arquivoDeNome;
    char parte1[10];//Variável auxiliar para pegar o texto gravado dentro do arquivo e dar para 'nome'
    
    //abrindo arquivo
    arquivoDeNome = fopen("ArquivoTemporario.txt", "r");

    //testando se obteve sucesso
    if (arquivoDeNome == NULL)
    {
        printf("O arquivo 'ArquivoTemporario.txt' não pode ser aberto!\n");
        exit(1);
    }

    //Lendo dentro do arquivo o nome tratado e gravando dentro de 'parte1'
    fscanf(arquivoDeNome, "%s", parte1);

    //copiando o texto armazenado em 'parte1' e colocando em 'nome'
    strcpy(nome, parte1);

    //fechando arquivo
    fclose(arquivoDeNome);
}

/**
 * @brief __criarArquivoExercicio__
 * ENTRADA: Um vetor com o nome formatado para criação do arquivo de exercício
 * PROCESSAMENTO: Vai criar um arquivo com utilizando o nome recebido por parãmetro 
 *                e escrever um programa básico de C dentro dele
 * SAIDA: Não há saída
*/

void
__criarArquivoExercicio__(char *nome)
{
    FILE *arquivoExercicio;
    char str[10];

    //Pegando o texto armazenado em 'nome' e colocando dentro de 'str'
    strcpy(str, nome);
    
    //abrindo um arquivo com o nome tratado (para os arquivos de exercícios)
    arquivoExercicio = fopen(str, "w");

    //testando se obteve sucesso ao abrir o arquivo
    if (arquivoExercicio == NULL)
    {
        printf("O arquivo '%s' não pode ser aberto!\n", str);
        exit(1);
    }

    //escrevendo um programa básico dentro do arquivo para facilitar o manusear do C
    fprintf(arquivoExercicio,"#include <stdio.h>\n\nint\nmain()\n{\n\n\n\treturn 0;\n}");

    //fechando arquivo
    fclose(arquivoExercicio);
}
