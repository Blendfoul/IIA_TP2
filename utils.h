#ifndef UITL_H
#define UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define DEFALT_ITERS = 250;
int InicializaParametrosGlobais(int argc,const char *argv [], int *debug, int *nIterMax, char *ficheiroCsv, char *nomeFich);

#endif