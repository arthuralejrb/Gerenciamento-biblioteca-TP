#ifndef BUSCAR_IDL_H
#define BUSCAR_IDL_H


#include <stdio.h>


//importa a struct livro
#include "../../registros/biblioteca.h"


int buscar_idl (tBiblioteca *biblioteca, int id) {
    /*
    Varre o vetor de livros em busca de um ID igual
    */


    int v = 0;

    for(int i = 0; i < biblioteca->total_livros; i++) {
        
        if(biblioteca->livros[i].idLivro == id) {
            //retorna a posição do livro desejado
            
            return i;
            v = 1;

        }

    }

    printf("Livro não encontrado!\n");
    return 0;

}


#endif
