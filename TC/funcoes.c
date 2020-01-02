#include "funcoes.h"

Grafo * InicializaArrayGrafos(char *nomeFicheiro, int *vertices, int *arestas, int *nLinhas){
    Grafo *grafoTemp = NULL;
    FILE *file;
	char comentario[100];

    file = fopen(nomeFicheiro, "r+");

    if (!file) {
		perror("Erro ao abrir o ficheiro:");
		return grafoTemp;
	}
    fscanf(file, "%[^\n]s", comentario);
	printf("%s\n", comentario);
	fscanf(file, "%d %d %d\n", vertices, arestas, nLinhas);

	grafoTemp = malloc(sizeof(Grafo) * (*nLinhas));
	if (!grafoTemp) {
		perror("Erro na alocacao de memoria (InicializaArrayGrafos):");
		return NULL;
	}

	for (int i = 0; i < (*nLinhas); i++) {
		grafoTemp[i].origem = 0;
		fscanf(file, "%d %d\n", &grafoTemp[i].origem, &grafoTemp[i].destino);
	}

    fclose(file);

    return grafoTemp;
}