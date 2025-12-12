#ifndef CARREGAR_DADOS_H
#define CARREGAR_DADOS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../../registros/biblioteca.h"


void carregar_dados(char *filename, tBiblioteca *biblioteca){

    FILE *arquivo = fopen(filename, "r");
    char linha[1024];

    if(arquivo != NULL) {
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            // Se o arquivo existe, mas está vazio, simplesmente fecha e sai
            fclose(arquivo);
            return;
        }
        while(fgets(linha, sizeof(linha), arquivo)) {

            linha[strcspn(linha, "\n")] = 0;

            if(strcmp(filename, "livros.csv") == 0){
                biblioteca->livros = (tLivro *)realloc(biblioteca->livros, (biblioteca->total_livros + 1) * sizeof(tLivro));
                tLivro livro;

                char *token = strtok(linha, ";");
                if(token) strcpy(livro.titulo,token);

                token = strtok(NULL, ";");
                if(token) strcpy(livro.autor, token);

                token = strtok(NULL, ";");
                if(token) livro.publicacao = atoi(token);

                token = strtok(NULL, ";");
                if(token) livro.disponivel = atoi(token);
                
                token = strtok(NULL, ";");
                if(token) livro.idLivro = atoi(token);
                    
                biblioteca->livros[biblioteca->total_livros] = livro;
                biblioteca->total_livros++; 

            }
            
            if(strcmp(filename, "usuarios.csv") == 0){
                biblioteca->usuarios = (tUsuario *)realloc(biblioteca->usuarios, (biblioteca->total_usuarios + 1) * sizeof(tUsuario));
                tUsuario usuario;
                
                char *token = strtok(linha, ";");
                if(token) strcpy(usuario.nome, token);
                
                token = strtok(NULL, ";");
                if(token) strcpy(usuario.email, token);
                
                token = strtok(NULL, ";");
                if(token) usuario.ativo = atoi(token);
                
                token = strtok(NULL, ";");
                if(token) usuario.idUsuario = atoi(token);

                biblioteca->usuarios[biblioteca->total_usuarios] = usuario;
                biblioteca->total_usuarios++;

            }
            
            if(strcmp(filename, "emprestimos.csv") == 0){
                biblioteca->emprestimos = (tEmprestimo *)realloc(biblioteca->emprestimos, (biblioteca->total_emprestimos + 1) * sizeof(tEmprestimo));
                tEmprestimo emprestimo;
                
                char *token = strtok(linha, ";");
                if(token) emprestimo.idEmprestimo = atoi(token);
                
                token = strtok(NULL, ";");
                if(token) emprestimo.idUsuario = atoi(token); // Ordem corrigida conforme escrever.h
                
                token = strtok(NULL, ";");
                if(token) emprestimo.idLivro = atoi(token);
                
                token = strtok(NULL, ";");
                if(token) strcpy(emprestimo.dataEmprestimo, token);
                
                token = strtok(NULL, ";");
                if(token) strcpy(emprestimo.dataDevolucao, token);
                
                token = strtok(NULL, ";");
                if(token) emprestimo.ativo = atoi(token);

                biblioteca->emprestimos[biblioteca->total_emprestimos] = emprestimo;
                biblioteca->total_emprestimos++;

            }


        }
        fclose(arquivo);
    }else {

        arquivo = fopen(filename, "w");
        if (strcmp(filename, "livros.csv") == 0) fprintf(arquivo, "titulo;autor;publicacao;disponivel;id\n");
            else if (strcmp(filename, "usuarios.csv") == 0) fprintf(arquivo, "nome;email;ativo;id\n");
            else if (strcmp(filename, "emprestimos.csv") == 0) fprintf(arquivo, "idEmprestimo;idUsuario;idLivro;dataEmprestimo;dataDevolucao;ativo\n");
            
            fclose(arquivo);
        
        return;
    
    }

}



#endif