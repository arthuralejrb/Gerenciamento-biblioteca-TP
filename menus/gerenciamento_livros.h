#ifndef GERENCIAMENTO_LIVROS_H
#define GERENCIAMENTO_LIVROS_H

//importa a struct livro
#include "../registros/biblioteca.h"

//importa as funções para gerenciamento dos livros
#include "../funcoes/livros/adicionar_livro.h"
#include "../funcoes/livros/buscar_livro.h"
#include "../funcoes/livros/listar_livros.h"
#include "../funcoes/livros/buscar_idl.h"
#include "../funcoes/livros/atualizar_livro.h"
#include "../funcoes/livros/remover_livro.h"
#include "../funcoes/utils/menu.h"
#include "../funcoes/utils/limpar_buffer.h"
#include "../funcoes/utils/escrever.h"
#include "../funcoes/utils/remover_linha.h"

#include <stdlib.h>


void gerenciamento_livros(tBiblioteca *biblioteca) {

    char opcao;

    while(scanf(" %c", &opcao)){ 

        //variaveis para busca nos vetores
        char busca[100];
        int busca_id;
        int posicao; 
        
        switch (opcao) {
            case '1':
                /*Adicionar novo livro*/

                //limpa a tela e adiciona um livro ao vetor de livros
                limpar_tela();
                adicionar_livro(biblioteca);

                //incrementa a contadora de livros e aumenta o espaço alocado pelo vetor de livros
                biblioteca->total_livros++; 
                biblioteca->livros = (tLivro *)realloc(biblioteca->livros, (biblioteca->total_livros + 1) * sizeof(tLivro));

                escrever_livros("livros.csv", biblioteca);

            break;

            
            case '2':
                /*Buscar livros*/
                
                //limpa a tela e lê a string busca 
                limpar_tela();

                printf("Digite o título do livro ou nome do autor: \n");
                limpar_buffer();
                fgets(busca, sizeof(busca), stdin);
                remover_linha(busca);

                //busca um livro no vetor de livros
                buscar_livro(biblioteca, busca);

            break;
            
            case '3':
                /*listar todos os livros*/
                
                //limpa a tela e lista todos os livros no vetor
                limpar_tela();
                listar_livros(biblioteca);
                printf("%d\n", biblioteca->total_livros);

            break;

            case '4':
                /*Atualizar dados de um livro*/
                
                //limpa a tela e lê o ID do livro a ser atualizado
                limpar_tela();
                printf("Informe o ID do livro: \n");
                scanf("%d", &busca_id);

                //usa o id do livro para encontrar sua posição no vetor de livros
                posicao = buscar_idl(biblioteca, busca_id);

                //atualiza os dados do livro
                atualizar_livro(biblioteca, posicao);
                escrever_livros("livros.csv", biblioteca);

            break;

            case '5':
                /*Remover um livro*/
                
                //limpa a tela e lê o ID do livro a ser removido do vetor
                limpar_tela();
                printf("Informe o ID do livro a ser removido: \n"); 
                scanf("%d", &busca_id);

                //usa o ID do livro para encontrar sua posição na biblioteca
                posicao = buscar_idl(biblioteca, busca_id);
                
                //remove o livro do vetor de livros
                remover_livro(biblioteca, posicao);

                //decrementa o total de livros armazenados e diminui o espaço alocado no vetor de livros
                biblioteca->total_livros--;
                biblioteca->livros = (tLivro *)realloc(biblioteca->livros, (biblioteca->total_livros + 1)*sizeof(tLivro));
                
                escrever_livros("livros.csv", biblioteca);
            
            break;

            case '0':
                /*Retorna para o menu principal*/    

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();
                return;

            break;

            default:

                printf("Opção inválida!\n");

            break;

        }

        //printa o menu de opções de gerenciamento de livros após cada iteração
        menu_de_livros();

    }
}


#endif