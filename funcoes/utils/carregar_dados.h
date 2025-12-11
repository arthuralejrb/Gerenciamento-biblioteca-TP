#ifndef CARREGAR_DADOS_H
#define CARREGAR_DADOS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../../registros/biblioteca.h"


void carregar_dados(char *filename, tBiblioteca *biblioteca){

    FILE *arquivo = fopen(filename, "r");


    if(arquivo != NULL) {
        
        while(!feof(arquivo)) {

            if(strcmp(filename, "livros.csv") == 0){
                tLivro livro;
                fscanf(arquivo, "%s;%s;%d;%d;%d;", 
                        livro.titulo, livro.autor, &livro.publicacao, &livro.disponivel, &livro.idLivro);
            
                        biblioteca->total_livros++;
                        biblioteca->livros = (tLivro *)realloc(biblioteca->livros, (biblioteca->total_livros + 1) * sizeof(tLivro));
                        biblioteca->livros[biblioteca->total_livros] = livro;

            }
            
            if(strcmp(filename, "usuarios.csv") == 0){
                tUsuario usuario;
                fscanf(arquivo, "%s%s%d\n%d\n", 
                    usuario.nome, usuario.email, &usuario.ativo, &usuario.idUsuario);
            
                biblioteca->usuarios[biblioteca->total_usuarios] = usuario;
                biblioteca->total_usuarios++;
                biblioteca->usuarios = (tUsuario *)realloc(biblioteca->usuarios, (biblioteca->total_usuarios + 1) * sizeof(tUsuario));

            }

             if(strcmp(filename, "emprestimos.csv") == 0){
                tEmprestimo emprestimo;
                fscanf(arquivo, "%d\n%d\n%d\n%s\n%s%d\n", 
                    &emprestimo.idEmprestimo, &emprestimo.idLivro, &emprestimo.idUsuario, emprestimo.dataEmprestimo, emprestimo.dataDevolucao, &emprestimo.ativo);
            
                biblioteca->emprestimos[biblioteca->total_emprestimos] = emprestimo;
                biblioteca->total_emprestimos++;
                biblioteca->emprestimos = (tEmprestimo *)realloc(biblioteca->emprestimos, (biblioteca->total_emprestimos + 1) * sizeof(tEmprestimo));

            }


        }

    }else {

        arquivo = fopen(filename, "w");
        return;
    
    }

}



#endif