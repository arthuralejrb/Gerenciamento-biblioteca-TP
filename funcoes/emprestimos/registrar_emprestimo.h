#ifndef REGISTRAR_EMPRESTIMO_H
#define REGISTRAR_EMPRESTIMO_H


//importa as structs emprestimo, usuario e livro
#include "../../registros/biblioteca.h"
#include "../utils/menu.h"

#include <stdio.h>
#include <string.h>
#include <time.h>


void registrar_emprestimo(tBiblioteca *biblioteca, int id_livro, int id_usuario) {
    
        /*
        Adiciona um emprestimo ao vetor de emprestimos
        usa a contadora de emprestimos pra acessar a ultima posição do vetor
        */

        tEmprestimo novo_emprestimo;


        //define a data do emprestimo
        time_t agora;
        struct tm *info;

        time(&agora);
        info = localtime(&agora);

        strftime(novo_emprestimo.dataEmprestimo, 11 , "%d/%m/%Y", info);
        
        //define os dados do emprestimo
        if(biblioteca->total_emprestimos == 0) {
            
                novo_emprestimo.idEmprestimo = 1;
                
        }else{
                
                novo_emprestimo.idEmprestimo = biblioteca->emprestimos[biblioteca->total_emprestimos - 1].idEmprestimo + 1; 
                
        }

        //define os IDs no emprestimo 
        novo_emprestimo.idLivro = id_livro;
        novo_emprestimo.idUsuario = id_usuario;
        
        // emprestimos[emprestimo_atual].dataEmprestimo = data_emprestimo;
        novo_emprestimo.ativo = 1;
        
        limpar_tela();
        printf("====Emprestimo realizado!====\n");
        printf("ID do emprestimo: %d\n", novo_emprestimo.idEmprestimo);
        printf("ID do livro: %d\n", novo_emprestimo.idLivro);
        printf("ID do usuário: %d\n", novo_emprestimo.idUsuario);
        printf("Data do empréstimo: %s\n", novo_emprestimo.dataEmprestimo);

        biblioteca->emprestimos = (tEmprestimo *)realloc(biblioteca->emprestimos, (biblioteca->total_emprestimos + 1) * sizeof(tEmprestimo));
        biblioteca->emprestimos[biblioteca->total_emprestimos] = novo_emprestimo;
        biblioteca->total_emprestimos++;
}       


#endif