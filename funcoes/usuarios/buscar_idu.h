#ifndef BUSCAR_IDU_H
#define BUSCAR_IDU_H


#include "../../registros/biblioteca.h"


#include <stdio.h>


int buscar_idu(tBiblioteca *biblioteca, int id){
    
    /*
    Busca a posição de um usuario no vetor de usuarios utilizando seu ID
    */
    
    int i;

    for(i = 0; i < biblioteca->total_usuarios && biblioteca->usuarios[i].idUsuario != id; i++);

    return biblioteca->usuarios[i].ativo;


}


#endif