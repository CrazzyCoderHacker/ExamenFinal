#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int secuencial(int arr[], int elemento, int num) 
{
    int i;
    for (i = 0; i < num; i++) 
	{
        if (arr[i] == elemento) 
		{
            return (i + 1);
        }
    }
    return -1;
}

int binario(int arr[], int elemento, int num, int primero, int ultimo) 
{
    if (primero <= ultimo) 
	{
        int mitad = (primero + ultimo) / 2;

        if (elemento == arr[mitad]) 
		{
            return (mitad + 1);
        } 
		else if (elemento < arr[mitad]) 
		{
            return binario(arr, elemento, num, primero, mitad - 1);
        } 
		else 
		{
            return binario(arr, elemento, num, mitad + 1, ultimo);
        }
    }
    return -1;
}

float orasprom(float arr[], int n) 
{
    float sum = 0;
    int i;
    for (i = 0; i < n; i++) 
	{
        sum += arr[i];
    }
    return sum / n;
}

int main() 
{
    int arr[50000];
    float oras1[100], oras2[100], cont = 0;
    int i, num, elemento;
    clock_t tic = clock();

    for (i = 0; i < 50000; i++) 
	{
        arr[i] = i;
    }

    for (i = 0; i < 100; i++) 
	{
        elemento = rand() % 50000;

        binario(arr, elemento, 50000, 0, 50000);
        clock_t toc = clock();
        cont = ((double)(toc - tic) / CLOCKS_PER_SEC);
        oras1[i] = cont;

        clock_t ticc = clock();
        secuencial(arr, elemento, 50000);
        clock_t tocc = clock();
        cont = ((double)(tocc - tic) / CLOCKS_PER_SEC);
        oras2[i] = cont;
    }

    printf("Promedio del tiempo de ejecucion de binario: %f\n", orasprom(oras1, 100));
    printf("Promedio del tiempo de ejecucion de secuencial: %f\n", orasprom(oras2, 100));

    return 0;
}


