#ifndef INATIVAR_USUARIO_H
#define INATIVAR_USUARIO_H


#include <stdio.h>


//importa a struct usuário
#include "../../registros/usuario.h"


void inativar_usuario(usuario *usuarios, int total_usuarios, int id){
    
    /*
        Define o estado de ativo de um usuário como 0 (inativo)
    */
    
    int usuario;
    
    for(int i = 0; i < total_usuarios ; i++){
        if(usuarios[i].idUsuario == id){
        usuario = i;
        usuarios[usuario].ativo = 0;
        return;
        }
    }
     printf("Usuário inativado com sucesso! \n");

}


#endif