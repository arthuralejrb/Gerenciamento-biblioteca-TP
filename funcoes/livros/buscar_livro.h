#ifndef BUSCAR_LIVRO_H
#define BUSCAR_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/livro.h"


void buscar_livro(livro *livros, int total_livros, char busca[]) {
    /*
    Busca um livro no vetor de livros
    passa por todos os livros, até achar um que possua o nome ou titulo condizente
    */
int v = 0;

        for(int i = 0; i < total_livros; i++) {
        if(strcmp(livros[i].titulo, busca) == 0 || strcmp(livros[i].autor, busca) == 0) {
        //printa os dados de cada livro achado
        printf("Livro: %s | Autor: %s | ID: %d | ", livros[i].titulo,  livros[i].autor, livros[i].idLivro);
        if(livros[i].disponivel){
            printf("Disponível\n");
        }
        else{
            printf("Indisponível\n");
        }
        v = 1;
    }
    }


    
    if(!v){
        //já acessou todos os livros do vetor e não encontrou
        printf("Livro não encontrado!\n");
    }
}
               



#endif