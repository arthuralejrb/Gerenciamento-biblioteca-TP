#ifndef LISTAR_EMPRESTIMOS_H
#define LISTAR_EMPRESTIMOS_H


//importa a struct emprestimo
#include "../../registros/biblioteca.h"


#include <stdio.h>


void listar_emprestimos(tBiblioteca *biblioteca) {
    
    /*
    Lista todos os emprestimos ativos
    */

    printf("====Emprestimos ativos====\n");

    for(int i = 0; i < biblioteca->total_emprestimos; i++) {

        //imprime somente os dados dos emprestimos ativos
        if(biblioteca->emprestimos[i].ativo == 1){
            
            printf("ID do emprestimo: %d | ID do livro: %d | ID do usuario: %d \n",
            biblioteca->emprestimos[i].idEmprestimo, biblioteca->emprestimos[i].idLivro, biblioteca->emprestimos[i].idUsuario);

        }

    }

    printf("\n");

}


#endif