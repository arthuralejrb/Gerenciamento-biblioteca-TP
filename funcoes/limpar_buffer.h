#ifndef LIMPAR_BUFFER_H
#define LIMPAR_BUFFER_H


#include <stdio.h>


void limpar_buffer() {

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

}

#endif