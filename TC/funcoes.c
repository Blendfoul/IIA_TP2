#include "funcoes.h"

Grafo *InicializaArrayGrafos(char *nomeFicheiro, int *vertices, int *arestas, int *nLinhas)
{
	Grafo *grafoTemp = NULL;
	FILE *file;
	char comentario[100];
	file = fopen(nomeFicheiro, "r+");

	if (!file)
	{
		perror("Erro ao abrir o ficheiro:");
		return grafoTemp;
	}
	fscanf(file, "%%%%%[^\n]s\n", comentario);
	printf("%s\n", comentario);
	fscanf(file, "%d %d %d\n", vertices, arestas, nLinhas);
	printf("Vertices: %d\tArestas: %d\tnLinhas: %d\n", *vertices, *arestas, *nLinhas);

	grafoTemp = malloc(sizeof(Grafo) * (*nLinhas));
	if (!grafoTemp)
	{
		perror("Erro na alocacao de memoria (InicializaArrayGrafos):");
		return NULL;
	}

	for (int i = 0; i < (*nLinhas); i++)
	{
		grafoTemp[i].origem = 0;
		fscanf(file, "%d %d\n", &grafoTemp[i].origem, &grafoTemp[i].destino);
	}

	fclose(file);

	return grafoTemp;
}

Grafo *CriaArrayVazio(const int *nLinhas)
{
	Grafo *grafo = NULL;

	grafo = malloc(sizeof(Grafo) * (*nLinhas));
	if (!grafo)
	{
		perror("Erro ao alocar memória (CriaArrayVazio):");
		return NULL;
	}

	for (int i = 0; i < (*nLinhas); i++)
	{
		grafo[i].origem = grafo[i].destino = 0;
	}

	return grafo;
}

void CopiaArray(Grafo *destino, const Grafo *origem, const int *nLinhas)
{
	for (int i = 0; i < (*nLinhas); nLinhas++)
	{
		destino[i].origem = origem[i].origem;
		destino[i].destino = origem[i].destino;
	}
}

int CriaFicheiroCSV(const char *nomeficheiro, Grafo *pointer, const int *nLinhas, const int *nIteracoes, const int *resultadoAlvo, const time_t *time)
{
	FILE *temp = fopen(nomeficheiro, "a");

	if (!temp)
	{
		perror("Erro abrir o ficheiro (CriaFicheiroCSV):");
		return 1;
	}

	fprintf(temp, "%sTrepa Colinas;;Tentativas;%d;;" /*Falta aqui parametros*/, asctime(localtime(time)), (*nIteracoes));
	for (int i = 0; i < (*nLinhas); i++)
	{
		fprintf(temp, ";%d", pointer[i].origem);
	}
	fprintf(temp, ";Fitness\n");

	fclose(temp);
	return EXIT_SUCCESS;
}

int ExportaResultadoLinhaCSV(const char *fileName, Grafo *pointer, const int *nLinhas, const int *vertice, const int melhorResultado, const time_t *time, const int *debug)
{
	FILE *temp = fopen(fileName, "a");
	struct tm *timeInfo;

	if (!temp)
	{
		perror("Erro abrir o ficheiro (exportCSVRowResult):");
		return EXIT_FAILURE;
	}
	if (melhorResultado)
	{
		fprintf(temp, "\nMelhor Resultado\n");
	}
	fprintf(temp, "#%d", (*vertice) + 1);
	for (int i = 0; i < (*nLinhas); i++)
	{
		fprintf(temp, ";%d", pointer[i].origem);
	}

	fprintf(temp, ";%d\n", VerificaFitness(pointer, nLinhas, vertice, debug));
	if (melhorResultado)
	{
		timeInfo = localtime(time);
		fprintf(temp, "Tempo decorrido:;%d:%d:%d\n\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
	}
	fclose(temp);
	return EXIT_SUCCESS;
}

int ErroCSV(const char *fileName, const char *error)
{
	FILE *temp = fopen(fileName, "a");

	if (!temp)
	{
		perror("Erro abrir o ficheiro (errorCSV):");
		return EXIT_FAILURE;
	}

	fprintf(temp, error);
	fclose(temp);
	return EXIT_SUCCESS;
}

void Random()
{
	srand((unsigned)time(NULL));
}

int VerificaFitness(const Grafo *grafo, const int *nLinhas, const int *vertice, const int *debug)
{
	int maximo = -1, maximoTemp;
	for (int i = 0; i < (*nLinhas); i++)
	{
		if (grafo[i].origem == (*vertice))
			for (int j = 0; j < (*nLinhas); j++)
			{
				if (grafo[j].origem == (*vertice))
				{
					maximoTemp = Modulo(&grafo[j].origem, &grafo[j].destino, debug);
					if (maximo == -1)
					{
						if(*debug)
							printf("Origem: %d\tDestino: %d\nMaximo temp: %d\n", grafo[j].origem, grafo[j].destino, maximoTemp);
						maximo = maximoTemp;
					}
					else
					{
						if(*debug)
							printf("Origem: %d\tDestino: %d\nMaximo temp: %d\n", grafo[j].origem, grafo[j].destino, maximoTemp);
						maximo = (((maximoTemp) > (maximo)) ? (maximoTemp) : (maximo));
					}
				}
			}
	}

	return maximo;
}

int Modulo(const int *origem, const int *destino, const int *debug)
{
	int resultado = (*origem) - (*destino);
	if(*debug)
		printf("Resultado de %d - %d: %d\n", *origem, *destino, resultado);
	if (resultado < 0)
		return (resultado * (-1));
	else
		return resultado;
}
