#ifndef CADASTRAR_USUARIO_H
#define CADASTRAR USUARIO_H


#include<stdio.h>


//inclui as structs para o gerenciamento da biblitoeca
#include "../../registros/biblioteca.h"


void cadastrar_usuario(tBiblioteca *biblioteca){
    
    /*
    Adiciona um usuário ao vetor de usuarios
    usa a contadora de usuarios para acessar a ultima posição do vetor
    */
   //Lê o nome do usuario
   printf("Informe o nome do usuario: \n");
   scanf("%s", biblioteca->usuarios[biblioteca->total_usuarios].nome);

    //Lê o email do usuário
    printf("Digite o email do usuario: \n");
    scanf("%s", biblioteca->usuarios[biblioteca->total_usuarios].email);

    
    //define o estado de ativo do usuário como verdadeiro
    biblioteca->usuarios[biblioteca->total_usuarios].ativo = 1;

    //define o id do i-ésimo livro como o id do livro anterior + 1  

    if(biblioteca->total_usuarios == 0) {
        
        biblioteca->usuarios[biblioteca->total_usuarios].idUsuario = 1;
        
    }else{
        
        biblioteca->usuarios[biblioteca->total_usuarios].idUsuario = biblioteca->usuarios[biblioteca->total_usuarios - 1].idUsuario + 1;
        
    }

    printf("ID do novo usuario é: %d\n",biblioteca->usuarios[biblioteca->total_usuarios].idUsuario);

}


#endif