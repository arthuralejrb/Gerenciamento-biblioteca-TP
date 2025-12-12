#ifndef EMPRESTIMOS_USUARIO_H
#define EMPRESTIMOS_UUARIO_H


//importa a struct emprestimo
#include "../../registros/biblioteca.h"


#include <stdlib.h>
#include <stdio.h>


int emprestimos_livro(tBiblioteca *biblioteca) {

    /*
    Encontra o livro com maior número de emprestios 
    */

    if(biblioteca->total_emprestimos == 0) {

        printf("Não há emprestimos no sistema! \n");
        return 0;

    }

    int valor_maximo = 0;

    for(int i = 0; i < biblioteca->total_emprestimos; i++) {

        if(biblioteca->emprestimos[i].idLivro > valor_maximo){
            
            //encontra o maior ID de usuário com emprestimo ativo
            valor_maximo = biblioteca->emprestimos[i].idLivro;
        
        }

    }

    //vetor dinamico que armazena as frequencias de cada ID no vetor emprestimos
    int *frequencia;
    frequencia = (int *)calloc(valor_maximo + 1 , sizeof(int));

    for(int i = 0; i < biblioteca->total_emprestimos; i++){

        //aumenta a contagem de frequencia de emprestimos de um usuario
        frequencia[biblioteca->emprestimos[i].idLivro]++;

    }

    //variavel para manter contagem da maior frequencia
    int maior_frequencia = 0;
    int livro = 0;

    for(int i = 0; i <= valor_maximo; i++) {

        if(frequencia[i] > maior_frequencia) {

            maior_frequencia = frequencia[i];
            livro = i;

        }

    }

    //libera a memoria alocada pelo vetor frequencia
    free(frequencia);

    printf("ID do livro com mais empréstimos: %d \n", livro);
    return 1;

}


#endif