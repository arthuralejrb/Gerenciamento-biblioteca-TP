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


        //define a data do emprestimo
        time_t agora;
        struct tm *info;

        time(&agora);
        info = localtime(&agora);

        strftime(biblioteca->emprestimos[biblioteca->total_emprestimos].dataEmprestimo, 11 , "%d/%m/%Y", info);
        
        //define os dados do emprestimo
        if(biblioteca->total_emprestimos == 0) {
            
                biblioteca->emprestimos[biblioteca->total_emprestimos].idEmprestimo = 1;
                
        }else{
                
                biblioteca->emprestimos[biblioteca->total_emprestimos].idEmprestimo = biblioteca->emprestimos[biblioteca->total_emprestimos - 1].idEmprestimo + 1; 
                
        }

        //define os IDs no emprestimo 
        biblioteca->emprestimos[biblioteca->total_emprestimos].idLivro = id_livro;
        biblioteca->emprestimos[biblioteca->total_emprestimos].idUsuario = id_usuario;
        
        // emprestimos[emprestimo_atual].dataEmprestimo = data_emprestimo;
        biblioteca->emprestimos[biblioteca->total_emprestimos].ativo = 1;
        
        limpar_tela();
        printf("====Emprestimo realizado!====");
        printf("ID: %d\n", biblioteca->emprestimos[biblioteca->total_emprestimos].idEmprestimo);
        printf("ID do livro: %d\n", biblioteca->emprestimos[biblioteca->total_emprestimos].idLivro);
        printf("ID do usuário: %d\n", biblioteca->emprestimos[biblioteca->total_emprestimos].idUsuario);
        printf("Data do empréstimo: %s\n", biblioteca->emprestimos[biblioteca->total_emprestimos].dataEmprestimo);
}       


#endif