
#ifndef BUSCAR_USUARIO_H
#define BUSCAR_USUARIO_H

#include <stdio.h>

#include "../../registros/usuario.h"


void buscar_usuario(usuario *u, int total_usuarios, char busca[]) {
    /*
    Busca um nome no vetor u
    passa por todos os nomes, até achar um que possua o nome do condizente
    */

    int v = 0;

    for(int i = 0; i < total_usuarios; i++) {
      if(strcmp(u[i].nome, busca) == 0){
    //Imprime os dados do usuário encontrado
    printf("Nome: %s | ", u[i].nome);
    printf("ID: %d | ", u[i].idUsuario);
    printf("Email %s | ", u[i].email);
    
    if(u[i].ativo) {
      
      printf("Ativo\n");
      
    }
    
    else {
      
      printf("Inativo\n");
      
    }
    v = 1;
    }
  }
    

    if(!v) {
      //já acessou todos os usuários do vetor e não encontrou
      printf("Usuario não encontrado!\n");
    }
    
}


#endif