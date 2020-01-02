#include "../utils.h"

int main(int argc, char const *argv[])
{

    int nIter;
    char nomeFich[40];

    if (argc == 1)
    {
        nIter DEFALT_ITERS;
        if (strlen(argv[0] >= 40))
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
    }
    else if (argc == 2)
    {
        if(argv[0] <= 0){
            nIter DEFALT_ITERS;
            printf("Numero invalido a correr com iteracoes predefinidas.")
        }
        else
            nIter = argv[1];
        if (strlen(argv[0] >= 40))
        {
            printf("Nome do ficheiro demasiado grande!");
            return 1;
        }
        else
            strcpy(nomeFich, argv[1]);
    }
}
else
{
    printf("Sintaxe: .\tc.exe <experiencia>");
    printf("Sintaxe: .\tc.exe <experiencia> <iteracoes>");
    return 1;
}

FILE *file;
file = fopen(argv[0], "r+");

fclose(file);

return 0;
}
