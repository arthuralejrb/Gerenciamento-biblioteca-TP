#ifndef LISTAR_LIVROS_H
#define LISTAR_LIVROS_H


#include <stdio.h>


//importa a struct livro
#include "../../registros/biblioteca.h"


void listar_livros(tBiblioteca *biblioteca) {
    /*
        Lista todos os livros armazenados
    */
   
    printf("\n");
    printf("\n");

    for(int i = 0; i < biblioteca->total_livros; i++) {
        //printa os dados de cada livro achado
        printf("Livro: %s | ID: %d | ", biblioteca->livros[i].titulo, biblioteca->livros[i].idLivro);
        if(biblioteca->livros[i].disponivel){
            printf("Disponível\n");
        }
        else{
            printf("Indisponível\n");
        }
    }

    printf("\n");

}


#endif