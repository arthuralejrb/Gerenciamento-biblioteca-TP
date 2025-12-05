#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H


#include <stdlib.h>


typedef struct {

    int idLivro;
    char titulo[100];
    char autor[100];
    int publicacao;
    int disponivel; //1 = disponivel 0 = indisponivel

} tLivro;


typedef struct {

    int idUsuario;
    char nome[100];
    char email[100];
    int ativo; //1 = ativo 0 = inativo

} tUsuario;


typedef struct{

    int idEmprestimo;
    int idUsuario;
    int idLivro;
    char dataEmprestimo[11]; //dd/mm/aaaa
    char dataDevolucao[11]; //dd/mm/aaaa
    int ativo; //1 = ativo 0 = concluido

} tEmprestimo;


typedef struct {

    tLivro *livros;
    int total_livros;

    tUsuario *usuarios;
    int total_usuarios;

    tEmprestimo *emprestimos;
    int total_emprestimos;

}tBiblioteca;


#endif