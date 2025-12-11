#ifndef GERENCIAMENTO_EMPRESTIMOS_H
#define GERENCIAMENTO_EMPRESTIMOS_H

//importa as structs de emprestimo, usuario e livro
#include "../registros/biblioteca.h"

//importa as funções para o gerenciamento de emprestimos
#include "../funcoes/emprestimos/listar_historico.h"
#include "../funcoes/emprestimos/listar_emprestimos.h"
#include "../funcoes/emprestimos/registrar_emprestimo.h"
#include "../funcoes/emprestimos/registrar_devolucao.h"
#include "../funcoes/emprestimos/buscar_ide.h"
#include "../funcoes/emprestimos/todos_emprestimos.h"
#include "../funcoes/usuarios/buscar_idu.h"
#include "../funcoes/utils/menu.h"
#include "../funcoes/utils/escrever.h"


#include <stdlib.h>


void gerenciamento_emprestimos(tBiblioteca *biblioteca) {

    char opcao;
    
    //Variaveis para a busca nos vetores
    int id_usuario;
    int id_livro;
    int id_emprestimo;
    int posicao_usuario;

    while(scanf(" %c", &opcao)) {

        switch(opcao) {

            case '1':
                /*Registrar novo empréstimo*/

                //limpa a tela antes das leituras
                limpar_tela();

                //Lê o ID do usuário
                printf("Informe o ID do usuário: \n");
                scanf("%d", &id_usuario);

                //Lê o ID do livro
                printf("Informe o ID do livro: \n");
                scanf("%d", &id_livro);

                //busca a posicao do livro e do usuario nos vetores
                posicao_usuario = buscar_idu(biblioteca, id_usuario);
                int posicao_livro = buscar_idl(biblioteca, id_livro);

                if(biblioteca->livros[posicao_livro].disponivel && posicao_usuario){

                    //registra um novo emprestimo
                    registrar_emprestimo(biblioteca, id_livro, id_usuario);
                    
                    //define o livro como indisponível
                    biblioteca->livros[posicao_livro].disponivel = 0;

                    //incrementa a contadora de emprestimos e aumenta o espaço alocado pelo vetor de emprestimos
                    biblioteca->total_emprestimos++;
                    biblioteca->emprestimos = (tEmprestimo *)realloc(biblioteca->emprestimos, (biblioteca->total_emprestimos + 1) * sizeof(tEmprestimo));
                    escrever_emprestimos("emprestimos.csv", biblioteca);
                }

                else{
                    
                    //emprestimo impossível
                    printf("Emprestimo impossível : usuário inativo ou livro indisponível\n");
                
                }
                

            break;
            
            case '2':
                /*Registrar devolução de um livro*/
                
                //limpa a tela e lê o ID do emprestimo
                limpar_tela();
            
                printf("Informe o ID do emprestimo: \n");
                scanf("%d", &id_emprestimo);

                if(!buscar_ide(biblioteca,id_emprestimo)){

                    //registra a devolução
                    registrar_devolucao(biblioteca,id_emprestimo);
                    escrever_emprestimos("emprestimos.csv", biblioteca);
                }

                else{
                
                    //o livro não foi emprestado
                    printf("Este livro nao foi emprestado\n");
                
                }

            break;
            
            case '3':
                /*Listar todos emprestimos ativos*/

                //limpa a tela e lista todos emprestimos ativos
                limpar_tela();
                listar_emprestimos(biblioteca);
            
            break;
            
            case '4':
                /*Listar histórico de emprestimos*/

                //limpa a tela e lista todo o histórico de emprestimos
                limpar_tela();
                listar_historico(biblioteca);
            
            break;
            
            case '5':
                /*Mostrar todos os livros emprestados por um usuário */
                
                //limpa a tela e lê o ID do usuário
                limpar_tela();

                printf("Informe o ID do usuario: \n");
                scanf("%d", &id_usuario);

                posicao_usuario = buscar_idu(biblioteca, id_usuario);
                todos_emprestimos(biblioteca, id_usuario, posicao_usuario);

            break;
            
            case '0':
                /*Retorna para o menu principal*/    

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();
                return;
            
            break;

            default:
                
                //o usuário inseriu uma opção que não existe
                printf("Opção inválida!\n");

            break;

        }

        //imprime o menu de emprestimos após cada iteração
        menu_de_emprestimos();
    }

}


#endif