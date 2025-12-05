#ifndef BUSCAR_IDE_H
#define BUSCAR_IDE_H


//importa as structs emprestimo e registro
#include "../../registros/biblioteca.h"


int buscar_ide(tBiblioteca *biblioteca, int id_emprestimo){
   
   /*
      Busca um livro e retorna se ele está disponível ou não
   */


   int i, j;
   
   //For de varredura para encontrar um emprestimo
   for(i = 0; i < biblioteca->total_emprestimos && biblioteca->emprestimos[i].idEmprestimo != id_emprestimo; i++);
   
   //Armazena o ID do livro emprestado
   int id_livro = biblioteca->emprestimos[i].idLivro;
   
   //For de varredura para encontrar um livro
   for(j = 0; j < biblioteca->total_livros && biblioteca->livros[i].idLivro != id_livro; j++);
   
   //retorna o estado do livro
   return biblioteca->livros[j].disponivel;
   
}


#endif