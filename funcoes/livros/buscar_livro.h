#ifndef BUSCAR_LIVRO_H
#define BUSCAR_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/biblioteca.h"


void buscar_livro(tBiblioteca *biblioteca, char busca[]) {
    /*
    Busca um livro no vetor de livros
    passa por todos os livros, até achar um que possua o nome ou titulo condizente
    */

    int v = 0;

        for(int i = 0; i < biblioteca->total_livros; i++) {
            
            if(strcmp(biblioteca->livros[i].titulo, busca) == 0 || strcmp(biblioteca->livros[i].autor, busca) == 0) {
                //printa os dados de cada livro achado

                printf("====Livro encontrado!====\n");
                printf("Título: %s\n",biblioteca->livros[i].titulo);
                printf("Autor: %s\n",biblioteca->livros[i].autor);
                printf("Publicação: %d\n",biblioteca->livros[i].publicacao);
                printf("ID: %d\n",biblioteca->livros[i].idLivro);
                
                if(biblioteca->livros[i].disponivel) {

                    printf("Disponível\n");
                }
                else {

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