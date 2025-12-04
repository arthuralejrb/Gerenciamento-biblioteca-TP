#ifndef REMOVER_LIVRO_H
#define REMOVER_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/livro.h"


void remover_livro(livro *livros, int posicao, int total_livros) {

    /*
    Remove um livro do vetor de livros
    utiliza o inteiro posicao para acessar o livro a ser removido e
    move todos os livros seguintes para trás.
    */

   //Verifica se o vetor é nulo
    if(livros == NULL || total_livros <= 0) {
        
        printf("Erro: vetor vazio\n");
    
    }
    else{
        if(posicao != total_livros - 1){
            //varre o vetor livro e move os livros para trás
            for(int i = posicao; i < total_livros - 1; i++) {
            livros[i] = livros[i + 1];
        }
     }
    }
    


    printf("Livro removido com sucesso! \n");

}


#endif