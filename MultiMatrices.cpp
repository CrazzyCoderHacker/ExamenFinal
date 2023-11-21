#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define p 30

void llenarMatriz(int A[p][p]) 
{
    for (int i = 0; i < p; ++i) 
    {
        for (int j = 0; j < p; ++j) 
        {
            A[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int A[p][p]) 
{
    for (int i = 0; i < p; ++i) 
    {
        for (int j = 0; j < p; ++j) 
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int A[p][p], int B[p][p], int resultado[p][p]) 
{
    for (int i = 0; i < p; ++i) 
    {
        for (int j = 0; j < p; ++j) 
        {
            resultado[i][j] = 0;
            for (int k = 0; k < p; ++k) 
            {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() 
{
    clock_t inicio = clock();
    srand(time(NULL));

    int A[p][p];
    int B[p][p];
    int resultado[p][p];

    llenarMatriz(A);
    llenarMatriz(B);

    printf("Matriz A:\n");
    printf("-------------------------------------------------------------\n");
    imprimirMatriz(A);
     printf("------------------------------------------------------------\n");
    printf("\nMatriz B:\n");
      printf("-------------------------------------------------------------\n");
   
    imprimirMatriz(B);
      printf("-------------------------------------------------------------\n");

    multiplicarMatrices(A, B, resultado);

  

    printf("\nFinal\n");
      printf("-------------------------------------------------------------------------------------\n");
    imprimirMatriz(resultado);
    
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC * 1000.0;
    printf("\nTiempo de ejecución: %.2f milisegundos\n", tiempo);
    return 0;
}



