#include "../utils.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int nIter;
    char nomeFich[100], ficheiroCsv[100];

    if (argc == 1)
    {
        strcpy(ficheiroCsv, "Teste.csv");
        nIter DEFALT_ITERS;
        if (strlen(argv[0]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
    }
    else if (argc == 2)
    {
        if (atoi(argv[1]) <= 0)
        {
            nIter DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.");
        }
        else
            nIter = atoi(argv[1]);
        if (strlen(argv[0]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
            strcpy(ficheiroCsv, "Teste.csv");

    }
    else if(argc == 3){
        if (atoi(argv[1]) <= 0)
        {
            nIter DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.");
        }
        else
            nIter = atoi(argv[1]);
        if (strlen(argv[0]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
        if (strlen(argv[2]) >= 100)
        {
            printf("Nome do ficheiro csv demasiado grande!");
            return 1;
        }
        else
            strcpy(ficheiroCsv, argv[2]);
    }
    else
    {
        printf("Sintaxe: .\tc.exe <experiencia>");
        printf("Sintaxe: .\tc.exe <experiencia> <iteracoes>");
        printf("Sintaxe: .\tc.exe <experiencia> <iteracoes> <csv>");
        return 1;
    }

    Grafo *dadosGrafo = NULL;
    int nVertices, nArestas, nLinhas;
    time_t sTimes;
	Random();

    dadosGrafo = InicializaArrayGrafos(nomeFich, &nVertices, &nArestas, &nLinhas);

    if(dadosGrafo != NULL){

        CriaFicheiroCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIter, 0, &sTimes);

        for(int i = 0; i < nLinhas; i++)
            printf("Origem: %d\tDestino: %d\n", dadosGrafo[i].origem, dadosGrafo[i].destino);
    }
    else{
        perror("Valor de dadosGrafo invalido: ");
        return 1;
    }


    free(dadosGrafo);
    return 0;
}
