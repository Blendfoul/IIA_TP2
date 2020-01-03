#include "../utils.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int nIterMax, debug = 0;
    char nomeFich[100], ficheiroCsv[100];

    argc = 4;

    if(InicializaParametrosGlobais(argc, argv, &debug, &nIterMax, ficheiroCsv, nomeFich)){
        return 1;
    }
    
    Grafo *dadosGrafo = NULL, *grafoAlvo = NULL;
    int nVertices, nArestas, nLinhas, flagPrimeiraTentativa = 0, nIter, nIterAlvo;
    //double resultadoAlvo = 0, valorAtual, valorMinimo, valorMaximo;
    int custo, custovizinho; 
    time_t sTime, fTime;
    Random();

    dadosGrafo = InicializaArrayGrafos(nomeFich, &nVertices, &nArestas, &nLinhas);

    if (dadosGrafo != NULL)
    {
        sTime = time(NULL);

        grafoAlvo = CriaArrayVazio(&nLinhas);
        if (grafoAlvo == NULL)
            return 1;

        if (CriaFicheiroCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIterMax, 0, &sTime))
        {
            free(dadosGrafo);
            free(grafoAlvo);
            return 1;
        }

        if(debug){
            for (int i = 0; i < nLinhas; i++)
                printf("Origem: %d\tDestino: %d\n", dadosGrafo[i].origem, dadosGrafo[i].destino);

            printf("Custo: %d\n", VerificaFitness(dadosGrafo, &nLinhas, &dadosGrafo[74].origem, &debug));
        }

        
        /*for (nIter = 0; nIter < nIterMax; nIter++)
        {
            if(ExportaResultadoLinhaCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIter, 0, NULL)){
                free(dadosGrafo);
                free(grafoAlvo);
                return 1;
            }
        }*/

        fTime = time(NULL);
	    fTime -= sTime;

        if(ExportaResultadoLinhaCSV(ficheiroCsv, grafoAlvo, &nLinhas, &nIterAlvo, 0, &fTime, &debug)){
                free(dadosGrafo);
                free(grafoAlvo);
                return 1;
            }

        printf("Mellor Combinacao encontrada -> ");
    }
    else
    {
        perror("Valor de dadosGrafo invalido: ");
        return 1;
    }

    free(grafoAlvo);
    free(dadosGrafo);
    return 0;
}
