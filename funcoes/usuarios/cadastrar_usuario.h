#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR USUARIO_H


#include<stdio.h>


//inclui as structs para o gerenciamento da biblitoeca
#include "../../registros/biblioteca.h"
#include "../utils/menu.h"
#include "../utils/limpar_buffer.h"
#include "../utils/remover_linha.h"


void cadastrar_usuario(tBiblioteca *biblioteca){
    
    /*
    Adiciona um usuário ao vetor de usuarios
    usa a contadora de usuarios para acessar a ultima posição do vetor
    */

    tUsuario usuario;

   //Lê o nome do usuario
   limpar_buffer();
   printf("Informe o nome do usuario: \n");
   fgets(usuario.nome, 100, stdin);
    remover_linha(usuario.nome);

    //Lê o email do usuário
    printf("Digite o email do usuario: \n");
    fgets(usuario.email, 100, stdin);
    remover_linha(usuario.email);

    
    //define o estado de ativo do usuário como verdadeiro
    usuario.ativo = 1;

    //define o id do i-ésimo livro como o id do livro anterior + 1  

    if(biblioteca->total_usuarios == 0) {
        
        usuario.idUsuario = 1;
        
    }else{
        
        usuario.idUsuario = biblioteca->usuarios[biblioteca->total_usuarios - 1].idUsuario + 1;
        
    }

    limpar_tela();
    printf("====Usuário adicionado!====\n");
    printf("Nome: %s\n",usuario.nome);
    printf("Email: %s\n",usuario.email);
    printf("ID: %d\n",usuario.idUsuario);

    
    biblioteca->usuarios = (tUsuario *)realloc(biblioteca->usuarios, (biblioteca->total_usuarios + 1)*sizeof(tUsuario));
    biblioteca->usuarios[biblioteca->total_usuarios] = usuario;
    biblioteca->total_usuarios++; 

}


#endif