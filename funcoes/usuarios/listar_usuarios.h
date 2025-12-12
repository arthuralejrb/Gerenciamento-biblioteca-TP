#ifndef LISTAR_USUARIO_H
#define LISTAR_USUARIO_H


#include<stdio.h>


//importa a struct usuario
#include "../../registros/biblioteca.h"
// #include "./menu.h"


void listar_usuarios(tBiblioteca *biblioteca) {

  /*
  Lista todos os usuários cadastrados
  */

//  limpar_tela();
  printf("====Usuários cadastrados====\n");
  for(int i = 0; i < biblioteca->total_usuarios; i++) {
    
    //imprime os dados de cada usuário no vetor
    printf("Nome: %s\n", biblioteca->usuarios[i].nome);
    printf("Email: %s\n", biblioteca->usuarios[i].email);
    printf("ID: %d\n", biblioteca->usuarios[i].idUsuario);

    if(biblioteca->usuarios[i].ativo){

      printf("Ativo\n\n");
    
    }
    else{
    
      printf("Inativo\n\n");
    
    }

  }

}


#endif