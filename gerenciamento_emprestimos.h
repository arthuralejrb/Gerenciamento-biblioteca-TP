#ifndef GERENCIAMENTO_EMPRESTIMOS_H
#define GERENCIAMENTO_EMPRESTIMOS_H

//importa as structs de emprestimo, usuario e livro
#include "./registros/emprestimo.h"
#include "./registros/usuario.h"
#include "./registros/livro.h"

//importa as funções para o gerenciamento de emprestimos
#include "./funcoes/emprestimos/listar_historico.h"
#include "./funcoes/emprestimos/listar_registros.h"
#include "./funcoes/emprestimos/registrar_emprestimo.h"
#include "./funcoes/emprestimos/registrar_devolucao.h"
#include "./funcoes/emprestimos/buscar_ide.h"
#include "./funcoes/usuarios/buscar_idu.h"
#include "./funcoes/menu.h"


#include <stdlib.h>


int gerenciamento_emprestimos(emprestimo *emprestimos, usuario *usuarios, 
    livro *livros, int total_emprestimos, int total_livros, int total_usuarios) {

    int opcao;
    
    //Variaveis para a busca nos vetores
    int id_usuario;
    int id_livro;
    int id_emprestimo;

    while(scanf("%d", &opcao)) {

        switch(opcao) {

            case 1:
                /*Registrar novo empréstimo*/

                //Lê o ID do usuário
                printf("Informe o ID do usuário: \n");
                scanf("%d", &id_usuario);

                //Lê o ID do livro
                printf("Informe o ID do livro: \n");
                scanf("%d", &id_livro);

                //busca a posicao do livro e do usuario nos vetores
                int posicao_livro = buscar_idl(livros,id_livro,total_livros);
                int posicao_usuario = buscar_idu(usuarios, id_usuario, total_usuarios);

                if(livros[posicao_livro].disponivel && posicao_usuario){

                    //registra um novo emprestimo
                    registrar_emprestimo(emprestimos, usuarios, livros, id_usuario, id_livro, total_emprestimos);
                    
                    //define o livro como indisponível
                    livros[posicao_livro].disponivel = false;

                    //incrementa a contadora de emprestimos e aumenta o espaço alocado pelo vetor de emprestimos
                    total_emprestimos++;
                    emprestimos = (emprestimo *)realloc(emprestimos, (total_emprestimos = 1) *sizeof(emprestimo));

                }

                else{
                    
                    //emprestimo impossível
                    printf("Emprestimo impossível : usuário inativo ou livro indisponível\n");
                
                }

            break;
            
            case 2:
                /*Registrar devolução de um livro*/
            
                printf("Informe o ID do emprestimo: \n");
                scanf("%d", &id_emprestimo);

                if(buscar_ide(emprestimos,livros,id_emprestimo,total_emprestimos,total_livros)){

                    registrar_devolucao(emprestimos, livros, total_emprestimos,  id_emprestimo, total_livros);

                }

                else{
                
                    printf("Este livro nao foi emprestado\n");
                
                }

            break;
            
            case 3:
                /*Listar todos emprestimos ativos*/

                listar_emprestimos(emprestimos, total_emprestimos);
            
            break;
            
            case 4:
                /*Listar histórico de emprestimos*/

                listar_historico(emprestimos, total_emprestimos);
            
            break;
            
            case 5:
                /*Mostrar todos os livros emprestados por um usuário */

                printf("Informe o ID do usuario: \n");

            break;
            
            case 0:
                /*Retorna para o menu principal*/    

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();

                //Retorna o novo total de emprestimos para o main.c
                return total_emprestimos;
            
            break;

        }

        //imprime o menu de emprestimos após cada iteração
        menu_de_emprestimos();
    }

}


#endif