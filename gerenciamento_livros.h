//importa a struct livro
#include "./registros/livro.h"

//importa as funções para gerenciamento dos livros
#include "./funcoes/livros/adicionar_livro.h"
#include "./funcoes/livros/buscar_livro.h"
#include "./funcoes/livros/listar_livros.h"
#include "./funcoes/livros/buscar_idl.h"
#include "./funcoes/livros/atualizar_livro.h"
#include "./funcoes/livros/remover_livro.h"
#include "./funcoes/menu.h"

#include <stdlib.h>

int gerenciamento_livros(livro *livros, int total_livros) {

    int opcao;

    while(scanf("%d", &opcao)){ 

        //variaveis para busca nos vetores
        char busca[100];
        int busca_id;
        int posicao; 
        
        switch (opcao) {
            case 1:
                /*Adicionar novo livro*/

                //adiciona um livro ao vetor de livros
                adicionar_livro(livros, total_livros);

                //incrementa a contadora de livros e aumenta o espaço alocado pelo vetor de livros
                total_livros++; 
                livros = (livro *)realloc(livros, (total_livros + 1) * sizeof(livro));

            break;

            case 2:
                /*Buscar livros*/
                
                //lê a string busca 
                printf("Digite o título do livro ou nome do autor: \n");
                scanf("%s", busca);

                //busca um livro no vetor de livros
                buscar_livro(livros, total_livros, busca);

            break;
            
            case 3:
                /*listar todos os livros*/

                //lista todos os livros no vetor
                listar_livros(livros, total_livros);
                
            break;

            case 4:
                /*Atualizar dados de um livro*/

                //lê o ID do livro a ser atualizado
                printf("Informe o ID do livro: \n");
                scanf("%d", &busca_id);

                //usa o id do livro para encontrar sua posição no vetor de livros
                posicao = buscar_idl(livros, busca_id, total_livros);

                //atualiza os dados do livro
                atualizar_livro(livros, posicao);

            break;

            case 5:
                /*Remover um livro*/

                //lê o ID do livro a ser removido do vetor
                printf("Informe o ID do livro a ser removido: \n"); 
                scanf("%d", &busca_id);

                //usa o ID do livro para encontrar sua posição no vetor de livros
                posicao = buscar_idl(livros, busca_id, total_livros);
                
                //remove o livro do vetor de livros
                remover_livro(livros, posicao, total_livros);

                //decrementa o total de livros armazenados e diminui o espaço alocado no vetor de livros
                total_livros--;
                livros = (livro *)realloc(livros, (total_livros)*sizeof(livro));
                
            break;

            case 0:
                /*Retorna para o menu principal*/    

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();

                //Retorna o novo total de livros para o main.c
                return total_livros;

            break;

        }

        //printa o menu de opções de gerenciamento de livros após cada iteração
        menu_de_livros();

    }
}