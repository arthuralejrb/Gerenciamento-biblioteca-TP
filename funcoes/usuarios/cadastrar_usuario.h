#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR USUARIO_H


#include<stdio.h>


//inclui as structs para o gerenciamento da biblitoeca
#include "../../registros/biblioteca.h"
#include "../menu.h"
#include "../limpar_buffer.h"


void cadastrar_usuario(tBiblioteca *biblioteca){
    
    /*
    Adiciona um usuário ao vetor de usuarios
    usa a contadora de usuarios para acessar a ultima posição do vetor
    */


   //Lê o nome do usuario
   limpar_buffer();
   printf("Informe o nome do usuario: \n");
   fgets(biblioteca->usuarios[biblioteca->total_usuarios].nome, 100, stdin);

    //Lê o email do usuário
    printf("Digite o email do usuario: \n");
    fgets(biblioteca->usuarios[biblioteca->total_usuarios].email, 100, stdin);

    
    //define o estado de ativo do usuário como verdadeiro
    biblioteca->usuarios[biblioteca->total_usuarios].ativo = 1;

    //define o id do i-ésimo livro como o id do livro anterior + 1  

    if(biblioteca->total_usuarios == 0) {
        
        biblioteca->usuarios[biblioteca->total_usuarios].idUsuario = 1;
        
    }else{
        
        biblioteca->usuarios[biblioteca->total_usuarios].idUsuario = biblioteca->usuarios[biblioteca->total_usuarios - 1].idUsuario + 1;
        
    }

    limpar_tela();
    printf("====Usuário adicionado!====\n");
    printf("Nome: %s\n",biblioteca->usuarios[biblioteca->total_usuarios].nome);
    printf("Email: %s\n",biblioteca->usuarios[biblioteca->total_usuarios].email);
    printf("ID: %d\n",biblioteca->usuarios[biblioteca->total_usuarios].idUsuario);

}


#endif