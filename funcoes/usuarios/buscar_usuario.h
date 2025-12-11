
#ifndef BUSCAR_USUARIO_H
#define BUSCAR_USUARIO_H

#include <stdio.h>
#include <stdlib.h>

#include "../../registros/biblioteca.h"
#include "../utils/menu.h"


void buscar_usuario(tBiblioteca *biblioteca, char busca[]) {
    /*
    Busca um nome no vetor u
    passa por todos os nomes, até achar um que possua o nome do condizente
    */

    int v = 0;

    for(int i = 0; i < biblioteca->total_usuarios; i++) {
        if(strcmp(biblioteca->usuarios[i].nome, busca) == 0){

        //Imprime os dados do usuário encontrado
        limpar_tela();
        printf("====Usuário encontrado====\n");
        printf("Nome: %s", biblioteca->usuarios[i].nome);
        printf("Email %s", biblioteca->usuarios[i].email);
        printf("ID: %d \n", biblioteca->usuarios[i].idUsuario);
      
        if(biblioteca->usuarios[i].ativo) {
          
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