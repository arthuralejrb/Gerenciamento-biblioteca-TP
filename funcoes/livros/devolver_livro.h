#ifndef DEVOLVER_LIVRO_H
#define DEVOLVER_LIVRO_H

#include <stdio.h>
#include <string.h>


//importa a struct livro
#include "../registros/biblioteca.h"

int devolver_livro(livro *livros, int total_livros, char titulo[]) {

    /*
    Retorna um livro ao definir seu estado como indisponível
    */


    int i = 0;

    while(strcmp(livros[i].titulo, titulo) != 0){
        i++;
        
        if(i > total_livros) {
            //Já acessou todos os livros do vetor e não encontrou

            printf("Livro não encontrado\n");
            return 0;

        }
        
    }

    if(livros[i].disponivel == true) {
        //o livro não foi reservado
        
        printf("O livro não foi reservado!\n");
        return 0;
    
    }

    //devolve o livro
    livros[i].disponivel = true;
    printf("Livro %s devolvido!\n", livros[i].titulo);
    
    return 1;

}


#endif