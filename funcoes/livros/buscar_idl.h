#ifndef BUSCAR_IDL_H
#define BUSCAR_IDL_H


#include <stdio.h>


//importa a struct livro
#include "../../registros/livro.h"


int buscar_idl (livro *livros, int id, int total_livros) {
    /*
    Varre o vetor de livros em busca de um ID igual
    */


    int v = 0;

    for(int i = 0; i < total_livros; i++) {
        
        printf("%s : %d\n", livros[total_livros].autor, id);
        if(livros[i].idLivro == id) {
            //retorna a posição do livro desejado
            return i;
            v = 1;

        }

    }

    printf("Livro não encontrado!\n");
    return 0;


}


#endif
