#include "../utils.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int nIterMax;
    char nomeFich[100], ficheiroCsv[100];

    if (argc == 1)
    {
        strcpy(ficheiroCsv, "Teste.csv");
        nIterMax DEFALT_ITERS;
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
            nIterMax DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.");
        }
        else
            nIterMax = atoi(argv[1]);
        if (strlen(argv[0]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
        strcpy(ficheiroCsv, "Teste.csv");
    }
    else if (argc == 3)
    {
        if (atoi(argv[1]) <= 0)
        {
            nIterMax DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.");
        }
        else
            nIterMax = atoi(argv[1]);
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

    Grafo *dadosGrafo = NULL, *grafoAlvo = NULL;
    int nVertices, nArestas, nLinhas, flagPrimeiraTentativa = 0, nIter, nIterAlvo;
    double resultadoAlvo, valorAtual, valorMinimo, valorMaximo;
    time_t sTime, fTime;
    Random();

    dadosGrafo = InicializaArrayGrafos(nomeFich, &nVertices, &nArestas, &nLinhas);

    if (dadosGrafo != NULL)
    {
        sTime = NULL;

        grafoAlvo = CriaArrayVazio(&nLinhas);
        if (grafoAlvo == NULL)
            return 1;

        if (CriaFicheiroCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIterMax, 0, &sTime))
        {
            free(dadosGrafo);
            free(grafoAlvo);
            return 1;
        }

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
            } while (valorAtual != resultadoAlvo);

            if(ExportaResultadoLinhaCSV(ficheiroCsv, dadosGrafo, &nLinhas, &nIter, 0)){
                free(dadosGrafo);
                free(grafoAlvo);
                return 1;
            }
        }

        fTime = time(NULL);
	    fTime -= sTime;

        if(ExportaResultadoLinhaCSV(ficheiroCsv, grafoAlvo, &nLinhas, &nIterAlvo, 0)){
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
