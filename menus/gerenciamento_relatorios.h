#ifndef GERENCIAMENTO_RELATORIOS_H
#define GERENCIAMENTO_RELATORIOS_H


//importa todas structs para o gerenciamento de relatorios
#include "../registros/biblioteca.h"


//importa todas as funções para o gerenciamento de relatorios
#include "../funcoes/relatorios/contar_livros.h"
#include "../funcoes/relatorios/emprestimos_usuario.h"
#include "../funcoes/relatorios/emprestimos_livro.h"
#include "../funcoes/utils/menu.h"


#include <stdlib.h>


int gerenciamento_relatorios(tBiblioteca *biblioteca) {

    char opcao;

    while(scanf(" %c", &opcao)) {

        switch(opcao) {

            case '1':
                /*Quantidade total de livros cadastrados*/
                limpar_tela();
               
                //printa o total de livros existentes
                printf("Total de livros cadastrados: %d \n", biblioteca->total_livros);
            
            break;
            
            case '2':
                /*Quantidade de livros disponíveis e emprestados*/
                limpar_tela();

                //printa a quantia de livros disponíveis e indisponíveis
                contar_livros(biblioteca);

            break;
            
            case '3':
                /*Usuário com mais emprestimos ativos*/
                limpar_tela();

                //printa o nome do usuário com mais emprestimos ativos
                emprestimos_usuario(biblioteca);
            break;
            
            case '4':
                /*Livro mais emprestado*/
                limpar_tela();

                emprestimos_livro(biblioteca);

            break;
            
            case '0':
                /*Retorna ao menu principal*/

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();

                return 1;

            break;

            default:

                printf("Opção inválida!\n");
            
            break;

        }

        //printa o menu de relatórios após cada iteração
        

        menu_de_relatorios();

    }

}


#endif