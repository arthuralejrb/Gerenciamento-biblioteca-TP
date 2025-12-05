#ifndef TODOS_EMPRESTIMOS_H
#define TODOS_EMPRESTIMOSH


//importa a struct emprestimo
#include "../../registros/biblioteca.h"


#include <stdio.h>


void todos_emprestimos(tBiblioteca *biblioteca, int id_usuario, int posicao_usuario) {
    
    /*
    Lista todos os emprestimos ativos
    */

    printf("====Emprestimos do usuário: %s====\n", biblioteca->usuarios[posicao_usuario].nome);

    for(int i = 0; i < biblioteca->total_emprestimos; i++) {
        
        if(biblioteca->emprestimos[i].idUsuario == id_usuario) {

            printf("ID do emprestimo: %d | ID do livro: %d \n", biblioteca->emprestimos[i].idEmprestimo, biblioteca->emprestimos[i].idLivro);

        }
    }
    

    printf("\n");

}


#endif