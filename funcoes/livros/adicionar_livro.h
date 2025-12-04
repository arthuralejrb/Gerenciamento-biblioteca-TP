#ifndef ADICIONAR_LIVRO_H
#define ADICIONAR_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/livro.h"


void adicionar_livro(livro *livros, int total_livros) {

    /*
    Adiciona um livro ao vetor de livros
    usa a contadora de livros pra acessar a ultima posição do vetor
    */

    //lê o título do novo livro
    printf("Informe o título do livro: \n");
    scanf("%s", livros[total_livros].titulo);

    //lê o autor do novo livro
    printf("Informe o nome do Autor: \n");
    scanf("%s", livros[total_livros].autor);

    //lê o ano de publicação do novo livro
    printf("Informe o ano de publicação: \n");
    scanf("%d", &livros[total_livros].publicacao);

    //define o estado do novo livro como disponível
    livros[total_livros].disponivel = true;

    //define o id do i-ésimo livro como o id do livro anterior + 1
    if(total_livros == 0) {
    
        livros[total_livros].idLivro = 1;
    
    }else{

        livros[total_livros].idLivro = livros[total_livros - 1].idLivro + 1;

    }
        printf("ID do novo livro é: %d\n",livros[total_livros].idLivro);

}

#endif