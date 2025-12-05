//importa a struct usuario
#include "./registros/biblioteca.h"

//importa todas funções para gerenciamento dos usuarios
#include "./funcoes/usuarios/cadastrar_usuario.h"
#include "./funcoes/usuarios/buscar_usuario.h"
#include "./funcoes/usuarios/listar_usuarios.h"
#include "./funcoes/usuarios/inativar_usuario.h"
#include "./funcoes/menu.h"


#include <stdlib.h>
#include <stdio.h>


void gerenciamento_usuarios(tBiblioteca *biblioteca) {

    char opcao;

    while(scanf(" %c", &opcao)){ 

        //variavels para a busca de um usuario
        char busca[100];
        int idr;

        switch (opcao) {

            case '1':
                /*Adiciona um usuário no vetor*/
                

                //limpa a tela e adiciona um novo usuario ao vetor de usuarios
                limpar_tela();
                cadastrar_usuario(biblioteca);
                
                //incrementa o total de usuarios e aumenta o espaço alocado para o vetor de usuarios
                biblioteca->total_usuarios++; 
                biblioteca->usuarios = (tUsuario *)realloc(biblioteca->usuarios, (biblioteca->total_usuarios + 1)*sizeof(tUsuario));

            break;

            case '2':
                /*Busca um usuário no vetor*/    
                

                //limpa a tela e lê a string busca com o nome do usuario
                limpar_tela();

                printf("Digite o nome do usuario: \n");
                scanf("%s", busca);

                //busca o usuario no vetor de usuarios
                buscar_usuario(biblioteca, busca);

            break;
            
            case '3':
                /*listar todos os usuarios*/
                

                //limpa a tela e lista todos usuarios cadastrados na biblioteca
                limpar_tela();
                listar_usuarios(biblioteca);
            
            break;

            case '4':
                /*Inativa um usuário*/   
                
                //limpa a tela e lê o ID do usuario 
                limpar_tela();
               printf("Digite o ID do usuário a ser inativado: \n");
               scanf("%d", &idr);
               
               //inativa o usuário
               inativar_usuario(biblioteca, idr);

            break;

            case '0':
                /*Retorna para o menu principal*/

                
                //limpa o terminal antes e retorna ao menu principal
                limpar_tela();
                return;

            break;

        }

        //printa o menu de usuarios após cada iteração
        menu_de_usuarios();

    }
}