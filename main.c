#ifndef MAIN_C
#define MAIN_C


#include <stdio.h>
#include <stdlib.h>


//importa todas as structs que o programa vai usar
#include "./registros/biblioteca.h"


//importa todas as funções para gerenciamento da biblioteca
#include "gerenciamento_livros.h"
#include "gerenciamento_emprestimos.h"
#include "gerenciamento_usuarios.h"
#include "gerenciamento_relatorios.h"
#include "./funcoes/menu.h"


int main(){

    //incialização dos vetores dinamicos
    tBiblioteca biblioteca;

    biblioteca.livros = (tLivro *)calloc(1,sizeof(tLivro)); 
    biblioteca.usuarios = (tUsuario *)calloc(1,sizeof(tUsuario));
    biblioteca.emprestimos = (tEmprestimo *)calloc(1,sizeof(tEmprestimo));
    
    //inicialização dos contadores
    biblioteca.total_emprestimos = 0;
    biblioteca.total_livros = 0;
    biblioteca.total_usuarios = 0;

    char opcao = 0;
    
    //printa o menu principal pela primeira vez
    menu_principal();
    
    while(scanf(" %c", &opcao)) {
        
        switch (opcao) {

            case '1':
                /*gerenciamento de livros*/

                //limpa a tela e printa o menu de livros
                limpar_tela();
                menu_de_livros();

                //chama a função que vai ler as entradas no menu de livros
                gerenciamento_livros(&biblioteca);
                
            break;
            
            
            case '2':
                /*gerenciamento de usuarios*/

                //limpa a tela e printa o menu de usuarios
                limpar_tela();
                menu_de_usuarios();
            
                //chama a funcao que vai ler as entradas no menu de usuarios
                gerenciamento_usuarios(&biblioteca);

            break;
            
            case '3':
                /*gerenciamento de emprestimos*/

                //limpa a tela e printa o menu de emprestimos
                limpar_tela();
                menu_de_emprestimos();
                
                //chama a funcao que vai ler as entradas no menu de emprestimos
                gerenciamento_emprestimos(&biblioteca);
            
            break;
           
            case '4':
                /*gerenciamento de relatorios*/

                //limpa a tela e printa o menu de relatorios
                limpar_tela();
                menu_de_relatorios();

                //chama a funcao que vai ler as entradas no menu de relatorios
                gerenciamento_relatorios(&biblioteca);

            break; 

            case '0':

                //libera a memória alocada
                free(biblioteca.livros);
                free(biblioteca.usuarios);
                free(biblioteca.emprestimos);

                return 0;

            break;

            default:
                
                //o usuário inseriu uma entrada que não existe 
                printf("Opção não existente\n");

            break;
            
        }
        
        //printa o menu principal após cada iteração
        menu_principal();

    }

}


#endif