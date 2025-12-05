#ifndef INATIVAR_USUARIO_H
#define INATIVAR_USUARIO_H


#include <stdio.h>


//importa a struct usuário
#include "../../registros/biblioteca.h"


void inativar_usuario(tBiblioteca *biblioteca, int id){
    
    /*
        Define o estado de ativo de um usuário como 0 (inativo)
    */
    
    int usuario;
    
    for(int i = 0; i < biblioteca->total_usuarios ; i++){
        if(biblioteca->usuarios[i].idUsuario == id){
        
            usuario = i;
            biblioteca->usuarios[usuario].ativo = 0;
            return;
        
        }
    }

     printf("Usuário inativado com sucesso! \n");

}


#endif