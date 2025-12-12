#ifndef ADICIONAR_LIVRO_H
#define ADICIONAR_LIVRO_H

#include <stdio.h>
#include <string.h>

//importa a struct livro
#include "../../registros/biblioteca.h"
#include "../utils/menu.h"
#include "../utils/limpar_buffer.h"
#include "../utils/remover_linha.h"


void adicionar_livro(tBiblioteca *biblioteca) {

    /*
    Adiciona um livro ao vetor de livros
    usa a contadora de livros pra acessar a ultima posição do vetor
    */

    printf("\n");
    limpar_buffer(); 

    tLivro novo;

    //lê o título do novo livro
    printf("Informe o título do livro: \n");

    fgets(novo.titulo, 100, stdin);
    remover_linha(novo.titulo);

    //lê o autor do novo livro
    printf("Informe o autor do livro: \n");

    fgets(novo.autor, 100, stdin );
    remover_linha(novo.autor);

    //lê o ano de publicação do novo livro
    printf("Informe o ano de publicação: \n");
    scanf("%d", &novo.publicacao);

    //define o estado do novo livro como disponível
    novo.disponivel = 1;

    //define o id do i-ésimo livro como o id do livro anterior + 1
    if(biblioteca->total_livros == 0) {
    
        novo.idLivro = 1;
    
    }else{

        novo.idLivro = biblioteca->livros[biblioteca->total_livros - 1].idLivro + 1;

    }

    //printa os dados do novo livro
    limpar_tela();
    printf("====Livro adicionado!====\n");
    printf("Título: %s\n",novo.titulo);
    printf("Autor: %s\n",novo.autor);
    printf("Publicação: %d\n",novo.publicacao);
    printf("ID: %d\n",novo.idLivro);

    biblioteca->livros = (tLivro *)realloc(biblioteca->livros, (biblioteca->total_livros + 1) * sizeof(tLivro));
    biblioteca->livros[biblioteca->total_livros] = novo;
    biblioteca->total_livros++;
}

#endif