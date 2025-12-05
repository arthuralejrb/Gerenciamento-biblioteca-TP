#ifndef ADICIONAR_LIVRO_H
#define ADICIONAR_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/biblioteca.h"


void adicionar_livro(tBiblioteca *biblioteca) {

    /*
    Adiciona um livro ao vetor de livros
    usa a contadora de livros pra acessar a ultima posição do vetor
    */

    printf("\n");

    //lê o título do novo livro
    printf("Informe o título do livro: \n");
    
    //fgets
    scanf("%s", biblioteca->livros[biblioteca->total_livros].titulo);

    //lê o autor do novo livro
    printf("Informe o nome do Autor: \n");
    scanf("%s", biblioteca->livros[biblioteca->total_livros].autor);

    //lê o ano de publicação do novo livro
    printf("Informe o ano de publicação: \n");
    scanf("%d", &biblioteca->livros[biblioteca->total_livros].publicacao);

    //define o estado do novo livro como disponível
    biblioteca->livros[biblioteca->total_livros].disponivel = 1;

    //define o id do i-ésimo livro como o id do livro anterior + 1
    if(biblioteca->total_livros == 0) {
    
        biblioteca->livros[biblioteca->total_livros].idLivro = 1;
    
    }else{

        biblioteca->livros[biblioteca->total_livros].idLivro = biblioteca->livros[biblioteca->total_livros - 1].idLivro + 1;

    }
        printf("\nID do novo livro é: %d\n",biblioteca->livros[biblioteca->total_livros].idLivro);

}

#endif