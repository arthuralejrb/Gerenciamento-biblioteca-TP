#ifndef MENU_H
#define MENU_H


#include <stdio.h>


void menu_principal() {
    printf("\n");
    printf("====MENU DE PRINCIPAL====\n");
    printf("1. Gerenciamento de livros\n");
    printf("2. Gerenciamento de usuários\n");
    printf("3. Gerenciamento de empréstimos\n");
    printf("4. Relatórios\n");
    printf("0. Sair do sistema\n");

}

void menu_de_livros(){
 
    printf("\n");
    printf("====MENU DE GERENCIAMENTO DE LIVROS====\n");
    printf("1. Adicionar livro\n");
    printf("2. Buscar livro\n");
    printf("3. Listar livros\n");
    printf("4. Atualizar dados de um livro\n");
    printf("5. Remover livro\n");
    printf("0. Retornar ao menu principal\n");

}

void menu_de_usuarios(){

    printf("\n");
    printf("====MENU DE GERENCIAMENTO DE USUARIOS====\n");
    printf("1. Cadastrar usuário\n");
    printf("2. Buscar usuário\n");
    printf("3. Listar usuários\n");
    printf("4. Inativar usuário\n");
    printf("0. Retornar ao menu principal\n");

}

void menu_de_emprestimos(){

    printf("\n");
    printf("====MENU DE GERENCIAMENTO DE EMPRESTIMOS====\n");
    printf("1. Registrar empréstimo\n");
    printf("2. Registrar devolução\n");
    printf("3. Listar empréstimos\n");
    printf("4. Listar histórico\n");
    printf("5. Listar emprestimos por usuário\n");
    printf("0. Retornar ao menu principal\n");

}

void menu_de_relatorios(){

    printf("\n");
    printf("====MENU DE GERENCIAMENTO DE RELATORIOS====\n");
    printf("1. Quantidade de livros cadastrados\n");
    printf("2. Quantidade de livros disponíveis e emprestados\n");
    printf("3. Usuário com mais empréstimos ativos\n");
    printf("4. Livro mais emprestado\n");
    printf("0. Retornar ao menu principal\n");

}

void menu_atualizacao() {

    printf("\n");
    printf("====INFORME O DADO A SER ATUALIZADO===\n");
    printf("1. Atualizar título\n");
    printf("2. Atualizar autor\n");
    printf("3. Atualizar ano de publicação\n");

}

void limpar_tela() {
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}


#endif