#ifndef ATUALIZAR_LIVRO_H
#define ATUALIZAR_LIVRO_H


#include <stdio.h>
#include <string.h>


//importa a struct livro
#include "../../registros/biblioteca.h"
#include "../menu.h"


void atualizar_livro(tBiblioteca *biblioteca, int posicao) {
    /*
    Altera os dados de um livro no vetor
    usa o inteiro posicao para acessar o livro no vetor
    */

    char opcao;

    //printa o menu com as opções para atualização do livro
    menu_atualizacao();
    scanf(" %c", &opcao);

    switch(opcao) {

        case '1':
            //atualiza o título do livro
            
            printf("Informe o novo título: \n");
            scanf("%s", biblioteca->livros[posicao].titulo);

        break;

        case '2':
            //atualiza o autor do livro

            printf("Informe o novo autor: \n");
            scanf("%s", biblioteca->livros[posicao].autor);

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
    
}


#endif