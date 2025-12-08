#ifndef REGISTRAR_DEVOLUCAO_H
#define REGISTRAR_DEVOLUCAO_H


//importa a struct emprestimo
#include "../../registros/biblioteca.h"


//importa função para encontrar o livro
#include "../livros/buscar_idl.h"
#include "../menu.h"


#include <stdio.h>


int registrar_devolucao(tBiblioteca *biblioteca, int id_emprestimo) {
    /*
    Registra a devolução de um emprestimo
    */

    limpar_tela();
    for(int i = 0; i < biblioteca->total_emprestimos; i++){
        if(biblioteca->emprestimos[i].idEmprestimo == id_emprestimo){
            
            //define o estado do emprestimo como inativo
            biblioteca->emprestimos[i].ativo = 0;
            printf("Livro retornado com sucesso! \n");

            //definir o estado do livro como disponível:
            int posicao_livro = buscar_idl(biblioteca, biblioteca->emprestimos[i].idLivro);
            biblioteca->livros[posicao_livro].disponivel = 1;
            
            return 0;
            
        }

    }

    //emprestimo não foi encontrado
    printf("Emprestimo não encontrado! \n");
    return 1;

}


#endif