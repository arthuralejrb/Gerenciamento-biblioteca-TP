#ifndef REMOVER_LIVRO_H
#define REMOVER_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/biblioteca.h"


void remover_livro(tBiblioteca *biblioteca, int posicao) {

    /*
    Remove um livro do vetor de livros
    utiliza o inteiro posicao para acessar o livro a ser removido e
    move todos os livros seguintes para trás.
    */

   //Verifica se o vetor é nulo
    if(biblioteca->livros == NULL || biblioteca->total_livros <= 0) {
        
        printf("Erro: vetor vazio\n");
    
    }
    else{
        if(posicao != biblioteca->total_livros - 1){
            //varre o vetor livro e move os livros para trás
            for(int i = posicao; i < biblioteca->total_livros - 1; i++) {
            biblioteca->livros[i] = biblioteca->livros[i + 1];
        }
     }
    }

    printf("Livro removido com sucesso! \n");

}


#endif