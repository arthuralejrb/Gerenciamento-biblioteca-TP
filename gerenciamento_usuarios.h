//importa a struct usuario
#include "./registros/usuario.h"

//importa todas funções para gerenciamento dos usuarios
#include "./funcoes/usuarios/cadastrar_usuario.h"
#include "./funcoes/usuarios/buscar_usuario.h"
#include "./funcoes/usuarios/listar_usuarios.h"
#include "./funcoes/usuarios/inativar_usuario.h"
#include "./funcoes/menu.h"


#include <stdlib.h>
#include <stdio.h>


int gerenciamento_usuarios(usuario *usuarios, int total_usuarios) {

    int opcao;

    while(scanf("%d", &opcao)){ 

        //variavels para a busca de um usuario
        char busca[100];
        int idr;

        switch (opcao) {

            case 1:
                /*Adiciona um usuário no vetor*/

                //adiciona um novo usuario ao vetor de usuarios
                cadastrar_usuario(usuarios, total_usuarios);
                
                //incrementa o total de usuarios e aumenta o espaço alocado para o vetor de usuarios
                total_usuarios++; 
                usuarios = (usuario *)realloc(usuarios, (total_usuarios + 1)*sizeof(usuario));

            break;

            case 2:
                /*Busca um usuário no vetor*/    

                //lê a string busca com o nome do usuario
                printf("Digite o nome do usuario: \n");
                scanf("%s", busca);

                //busca o usuario no vetor de usuarios
                buscar_usuario(usuarios, total_usuarios, busca);

            break;
            
            case 3:
                /*listar todos os usuarios*/

                //lista todos usuarios no vetor
                listar_usuarios(usuarios, total_usuarios);
            
            break;

            case 4:
                /*Inativa um usuário*/   
                
               //lê o ID do usuario 
               printf("Digite o ID do usuário a ser inativado: \n");
               scanf("%d", &idr);
               
               //inativa o usuário
               inativar_usuario(usuarios,total_usuarios, idr);

            break;

            case 0:
                /*Retorna para o menu principal*/

                //limpa o terminal antes de retornar ao menu principal
                limpar_tela();

                //Retorna o novo total de usuarios para o main.c
                return total_usuarios;

            break;

        }

        //printa o menu de usuarios após cada iteração
        menu_de_usuarios();

    }
}