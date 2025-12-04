#ifndef LISTAR_LIVROS_H
#define LISTAR_LIVROS_H


#include <stdio.h>


//importa a struct livro
#include "../../registros/livro.h"


void listar_livros(livro *livros, int total_livros) {
    /*
        Lista todos os livros armazenados
    */
   
    printf("\n");
    printf("\n");

    for(int i = 0; i < total_livros; i++) {
        //printa os dados de cada livro achado
        printf("Livro: %s | ID: %d | ", livros[i].titulo, livros[i].idLivro);
        if(livros[i].disponivel){
            printf("Disponível\n");
        }
        else{
            printf("Indisponível\n");
        }
    }

    printf("\n");

}


#endif