#include "../utils.h"
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int nIterMax, debug = 1;
    char nomeFich[100], ficheiroCsv[100];

    if(debug == 1)
        printf("argc -> %d\nargv[0]-> %s\n", argc, argv[0]);


    if (argc == 2)
    {
        strcpy(ficheiroCsv, "Teste.csv");
        nIterMax DEFALT_ITERS;
        if (strlen(argv[1]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!\n");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
    }
    else if (argc == 3)
    {
        if (atoi(argv[2]) <= 0)
        {
            nIterMax DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.\n");
        }
        else
            nIterMax = atoi(argv[1]);
        if (strlen(argv[1]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!\n");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
        strcpy(ficheiroCsv, "Teste.csv");
    }
    else if (argc == 4)
    {
        if (atoi(argv[2]) <= 0)
        {
            nIterMax DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.\n");
        }
        else
            nIterMax = atoi(argv[2]);
        if (strlen(argv[1]) >= 100)
        {
            printf("Nome do ficheiro demasiado grande!\n");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
        if (strlen(argv[3]) >= 100)
        {
            printf("Nome do ficheiro csv demasiado grande!\n");
            return 1;
        }
        else
            strcpy(ficheiroCsv, argv[3]);
    }
    else
    {
        printf("Sintaxe: .\\main.exe <experiencia>\n");
        printf("Sintaxe: .\\main.exe <experiencia> <iteracoes>\n");
        printf("Sintaxe: .\\main.exe <experiencia> <iteracoes> <csv>");
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
