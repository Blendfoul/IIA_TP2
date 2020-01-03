#include "utils.h"

int InicializaParametrosGlobais(int argc,const char *argv [], int *debug, int *nIterMax, char *ficheiroCsv, char *nomeFich) {
    if((*debug) == 1)
        printf("argc -> %d\nargv[0]-> %s\n", argc, argv[0]);


    if (argc == 2)
    {
        strcpy(ficheiroCsv, "Teste.csv");
        (*nIterMax) DEFALT_ITERS;
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
            (*nIterMax) DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.\n");
        }
        else
            (*nIterMax) = atoi(argv[1]);
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
            (*nIterMax) DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.\n");
        }
        else
            (*nIterMax) = atoi(argv[2]);
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

    return 0;
}