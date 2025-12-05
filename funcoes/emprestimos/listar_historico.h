#ifndef LISTAR_HISTORICO_H
#define LISTAR_HISTORICO_H


//importa a struct emprestimo
#include "../../registros/biblioteca.h"


#include <stdio.h>


void listar_historico(tBiblioteca *biblioteca) {
    
    /*
    Lista todos os emprestimos já realizados
    e se estão ativos ou não
    */

    printf("====Histórico de emprestimos ====\n");

    for(int i = 0; i < biblioteca->total_emprestimos; i++) {

        //imrpime os dados do emprestimo
        printf("ID do emprestimo: %d | ID do livro: %d | ID do usuario: %d \n",
        biblioteca->emprestimos[i].idEmprestimo, biblioteca->emprestimos[i].idLivro, biblioteca->emprestimos[i].idUsuario);

    }

    printf("\n");

}


#endif