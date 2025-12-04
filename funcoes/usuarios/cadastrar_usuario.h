#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR USUARIO_H


#include<stdio.h>


//inclui a struct usuario
#include "../../registros/usuario.h"


void cadastrar_usuario(usuario *u, int total_usuario){
    
    /*
    Adiciona um usuário ao vetor de usuarios
    usa a contadora de usuarios para acessar a ultima posição do vetor
    */
   //Lê o nome do usuario
   printf("Informe o nome do usuario: \n");
   scanf("%s", u[total_usuario].nome);

    //Lê o email do usuário
    printf("Digite o email do usuario: \n");
    scanf("%s", u[total_usuario].email);

    
    //define o estado de ativo do usuário como verdadeiro
    u[total_usuario].ativo = true;

    //define o id do i-ésimo livro como o id do livro anterior + 1  

    if(total_usuario == 0) {
        
        u[total_usuario].idUsuario = 1;
        
    }else{
        
        u[total_usuario].idUsuario = u[total_usuario - 1].idUsuario + 1;
        
    }
    printf("ID do novo usuario é: %d\n",u[total_usuario].idUsuario);


}


#endif