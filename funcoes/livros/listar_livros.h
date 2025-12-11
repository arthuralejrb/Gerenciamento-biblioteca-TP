#ifndef LISTAR_LIVROS_H
#define LISTAR_LIVROS_H


#include <stdio.h>


//importa a struct livro
#include "../../registros/biblioteca.h"


void listar_livros(tBiblioteca *biblioteca) {
    /*
        Lista todos os livros armazenados
    */

    printf("====Livros cadastrados!====\n");

    for(int i = 0; i < biblioteca->total_livros; i++) {
        
        //printa os dados de cada livro achado
        printf("Título do livro: %s\n", biblioteca->livros[i].titulo);
        printf("Autor: %s\n", biblioteca->livros[i].autor);
        printf("Ano de publicação: %d\n", biblioteca->livros[i].publicacao);
        printf("ID: %d\n\n", biblioteca->livros[i].idLivro);
        
    }

    printf("\n");

}


#endif