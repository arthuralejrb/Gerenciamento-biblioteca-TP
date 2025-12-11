#ifndef REMOVER_LINHA_H
#define REMOVER_LINHA_H


#include <string.h>


void remover_linha(char *buffer) {

    buffer[strcspn(buffer, "\n\r")] = '\0';
    
}


#endif