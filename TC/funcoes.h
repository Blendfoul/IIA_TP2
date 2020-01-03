#ifndef FUNC_H
#define FUNC_H
#include "../utils.h"

typedef struct{
    int origem;
    int destino;
}Grafo;

void Random();
Grafo * InicializaArrayGrafos(char *nomeFicheiro, int *vertices, int  *arestas, int *nLinhas);
Grafo * CriaArrayVazio(const int *nLinhas);
void CopiaArray(Grafo *destino, const Grafo *origem, const int *nLinhas);
int CriaFicheiroCSV(const char *nomeficheiro, Grafo * pointer, const int *nLinhas, const int * nIteracoes, const int *resultadoAlvo, const time_t * time);
int ExportaResultadoLinhaCSV(const char * fileName, Grafo * pointer, const int * nLinhas, const int *vertice, const int melhorResultado, const time_t * time);
int ErroCSV(const char * fileName, const char * error);
int VerificaFitness(const Grafo *grafo, const int *nLinhas);

#endif