#include "../utils.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int nIterMax, debug = 1;
    char nomeFich[100], ficheiroCsv[100];

    if(InicializaParametrosGlobais(argc, argv, &debug, &nIterMax, ficheiroCsv, nomeFich)){
        return 1;
    }

    Grafo *dadosGrafo = NULL, *grafoAlvo = NULL;
    int nVertices, nArestas, nLinhas, flagPrimeiraTentativa = 0, nIter, nIterAlvo;
    double resultadoAlvo, valorAtual, valorMinimo, valorMaximo;
    time_t sTime, fTime;
    Random();

    printf("Resultado alvo: ");
    scanf("%lf", &resultadoAlvo);

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

        if(!debug)
            for (nIter = 0; nIter < nIterMax; nIter++)
            {
                do
                {
                    if (valorAtual > resultadoAlvo)
                    {
                        break; //TODO: Remover e implementar lógica
                    }
                    else if (valorAtual < resultadoAlvo)
                    {
                        break; //TODO: Remover e implementar lógica
                    }
                    if(valorAtual < resultadoAlvo )
                        break;
                } while (valorAtual != resultadoAlvo);

                if(ExportaResultadoLinhaCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIter, 0, NULL)){
                    free(dadosGrafo);
                    free(grafoAlvo);
                    return 1;
                }
            }

        fTime = time(NULL);
	    fTime -= sTime;

        if(ExportaResultadoLinhaCSV(ficheiroCsv, grafoAlvo, &nLinhas, &nIterAlvo, 0, &fTime)){
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
