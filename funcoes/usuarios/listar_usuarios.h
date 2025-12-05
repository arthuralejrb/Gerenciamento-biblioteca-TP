#ifndef LISTAR_USUARIO_H
#define LISTAR_USUARIO_H


#include<stdio.h>


//importa a struct usuario
#include "../../registros/biblioteca.h"


void listar_usuarios(tBiblioteca *biblioteca) {

  /*
  Lista todos os usuários cadastrados
  */

  printf("\n");

  for(int i = 0; i < biblioteca->total_usuarios; i++) {
    
    //imprime os dados de cada usuário no vetor
    printf("Nome: %s | ID: %d | Email: %s | ", biblioteca->usuarios[i].nome, biblioteca->usuarios[i].idUsuario, biblioteca->usuarios[i].email);
      
    if(biblioteca->usuarios[i].ativo){

      printf("Ativo\n");
    
    }
    else{
    
      printf("Inativo\n");
    
    }

  }

  printf("\n");

}


#endif