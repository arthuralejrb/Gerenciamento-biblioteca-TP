#ifndef EMPRESTIMOS_LIVRO_H
#define EMPRESTIMOS_LIVRO_H


//importa a struct livro
#include "../../registros/biblioteca.h"


#include <stdio.h> 


void contar_livros(tBiblioteca *biblioteca){

    /*
    Conta quantos livros estão disponíveis e quantos não estão
    */

    int disponiveis = 0;
    int indisponiveis = 0;

    for(int i = 0; i < biblioteca->total_livros; i++) {

        if(biblioteca->livros[i].disponivel == 0){

            indisponiveis++;
        
        }else {
        
            disponiveis++;
        
        }
    }

    //imprime a quantia de livros disponíveis e indisponíveis
    printf("%d Livros disponíveis | %d Livros indisponíveis \n", disponiveis, indisponiveis);

}

#endif