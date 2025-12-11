#ifndef ESCREVER_H
#define ESCREVER_H


#include <stdlib.h>
#include <stdio.h>
#include "../../registros/biblioteca.h"


int escrever_livros(char *nomeArquivo, tBiblioteca *biblioteca){

    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if(arquivo) {
        fprintf(arquivo, "titulo;autor;publicacao;disponivel;id\n");

        for(int i = 0; i < biblioteca->total_livros; i++){
           
            fprintf(arquivo, "%s;%s;%d;%d;%d\n",
            biblioteca->livros[i].titulo,
            biblioteca->livros[i].autor,
            biblioteca->livros[i].publicacao,
            biblioteca->livros[i].disponivel,
            biblioteca->livros[i].idLivro);
        
        }

    }else{

        printf("Erro ao criar arquivo\n");
        return 1;
    
    }

    fclose(arquivo);
    return 0;

}


int escrever_usuarios(char *nomeArquivo, tBiblioteca *biblioteca){

    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if(arquivo) {
        fprintf(arquivo, "nome;email;ativo;id\n");

        for(int i = 0; i < biblioteca->total_usuarios; i++){
           
            fprintf(arquivo, "%s;%s;%d;%d\n",
            biblioteca->usuarios[i].nome,
            biblioteca->usuarios[i].email,
            biblioteca->usuarios[i].ativo,
            biblioteca->usuarios[i].idUsuario);
        
        }

    }else{

        printf("Erro ao criar arquivo\n");
        return 1;
    
    }

    fclose(arquivo);
    return 0;

}


int escrever_emprestimos(char *nomeArquivo, tBiblioteca *biblioteca){

    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if(arquivo) {
        fprintf(arquivo, "idEmprestimo;idUsuario;idLivro;dataEmprestimo;dataDevolucao;ativo\n");

        for(int i = 0; i < biblioteca->total_usuarios; i++){
           
            fprintf(arquivo, "%d;%d;%d;%s;%s;%d\n",
            biblioteca->emprestimos[i].idEmprestimo,
            biblioteca->emprestimos[i].idUsuario,
            biblioteca->emprestimos[i].idLivro,
            biblioteca->emprestimos[i].dataEmprestimo,
            biblioteca->emprestimos[i].dataDevolucao,
            biblioteca->emprestimos[i].ativo);
        
        }

    }else{

        printf("Erro ao criar arquivo\n");
        return 1;
    
    }

    fclose(arquivo);
    return 0;

}


#endif