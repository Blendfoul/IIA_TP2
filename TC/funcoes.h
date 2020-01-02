#ifndef FUNC_H
#define FUNC_H
#include "../utils.h"

typedef struct{
    int origem;
    int destino;
}Grafo;
Grafo * InicializaArrayGrafos(char *nomeFicheiro, int *vertices, int  *arestas, int *nLinhas);

#endif