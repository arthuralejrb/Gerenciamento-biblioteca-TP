#ifndef ATUALIZAR_LIVRO_H
#define ATUALIZAR_LIVRO_H


#include <stdio.h>
#include <string.h>


//importa a struct livro
#include "../../registros/biblioteca.h"
#include "../utils/menu.h"
#include "../utils/limpar_buffer.h"


void atualizar_livro(tBiblioteca *biblioteca, int posicao) {
    /*
    Altera os dados de um livro no vetor
    usa o inteiro posicao para acessar o livro no vetor
    */

    char opcao;
    limpar_buffer();

    printf("====Dados do livro====\n");
    printf("Título: %s\n",biblioteca->livros[posicao].titulo);
    printf("Autor: %s\n",biblioteca->livros[posicao].autor);
    printf("Publicação: %d\n",biblioteca->livros[posicao].publicacao);
    printf("ID: %d\n",biblioteca->livros[posicao].idLivro);

    //printa o menu com as opções para atualização do livro
    menu_atualizacao();
    scanf(" %c", &opcao);

    switch(opcao) {

        case '1':
            //atualiza o título do livro
            
            printf("Informe o novo título: \n");
            fgets( biblioteca->livros[posicao].titulo, 100, stdin);

        break;

        case '2':
            //atualiza o autor do livro

            printf("Informe o novo autor: \n");
            fgets( biblioteca->livros[posicao].autor, 100, stdin);

        break;

        case '3':
            //atualiza o ano de publicação do livro

            printf("Informe o novo ano de publicação: \n");
            scanf("%d", &biblioteca->livros[posicao].publicacao);

        break;

        default:

            printf("Opção desconhecida!\n");
        
        break;
    }
    
    limpar_tela();

}


#endif