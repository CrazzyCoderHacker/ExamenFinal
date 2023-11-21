#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamano 10000
#define repetir 100

void insertionSort(int array[tamano]) 
{
    clock_t inicio, fin;
    double tiempoPromedio = 0.0;
    double tiempoMinimo = -1.0;
    double tiempoMaximo = -1.0;

    for (int r = 0; r < repetir; ++r) 
	{
        int copiaArray[tamano];
        for (int i = 0; i < tamano; ++i) 
		{
            copiaArray[i] = array[i];
        }

        inicio = clock();

        for (int i = 1; i < tamano; ++i) 
		{
            int key = copiaArray[i];
            int j = i - 1;
            while (j >= 0 && copiaArray[j] > key) 
			{
                copiaArray[j + 1] = copiaArray[j];
                j = j - 1;
            }
            copiaArray[j + 1] = key;
        }

        fin = clock();

        double tiempo = ((double)fin - inicio) / CLOCKS_PER_SEC * 1000.0;
        tiempoPromedio += tiempo;

        if (tiempoMinimo == -1.0 || tiempo < tiempoMinimo) 
		{
            tiempoMinimo = tiempo;
        }

        if (tiempoMaximo == -1.0 || tiempo > tiempoMaximo) 
		{
            tiempoMaximo = tiempo;
        }
    }

    tiempoPromedio /= repetir;

    printf("Insertion Sort\n");
    printf("Tiempo promedio: %.2f ms\n", tiempoPromedio);
    printf("Tiempo minimo: %.2f ms\n", tiempoMinimo);
    printf("Tiempo maximo: %.2f ms\n\n", tiempoMaximo);
}

void bubbleSort(int array[tamano]) 
{
    clock_t inicio, fin;
    double tiempoPromedio = 0.0;
    double tiempoMinimo = -1.0;
    double tiempoMaximo = -1.0;

    for (int r = 0; r < repetir; ++r) 
	{
        int copiaArray[tamano];
        for (int i = 0; i < tamano; ++i) 
		{
            copiaArray[i] = array[i];
        }

        inicio = clock();

        for (int i = 0; i < tamano - 1; ++i) 
		{
            for (int j = 0; j < tamano - i - 1; ++j) 
			{
                if (copiaArray[j] > copiaArray[j + 1]) 
				{
                    int temp = copiaArray[j];
                    copiaArray[j] = copiaArray[j + 1];
                    copiaArray[j + 1] = temp;
                }
            }
        }

        fin = clock();

        double tiempo = ((double)fin - inicio) / CLOCKS_PER_SEC * 1000.0;
        tiempoPromedio += tiempo;

        if (tiempoMinimo == -1.0 || tiempo < tiempoMinimo) 
		{
            tiempoMinimo = tiempo;
        }

        if (tiempoMaximo == -1.0 || tiempo > tiempoMaximo) 
		{
            tiempoMaximo = tiempo;
        }
    }

    tiempoPromedio /= repetir;

    printf("Bubble Sort\n");
    printf("Tiempo promedio: %.2f ms\n", tiempoPromedio);
    printf("Tiempo minimo: %.2f ms\n", tiempoMinimo);
    printf("Tiempo maximo: %.2f ms\n\n", tiempoMaximo);
}

void selectionSort(int array[tamano]) 
{
    clock_t inicio, fin;
    double tiempoPromedio = 0.0;
    double tiempoMinimo = -1.0;
    double tiempoMaximo = -1.0;

    for (int r = 0; r < repetir; ++r) 
	{
        int copiaArray[tamano];
        for (int i = 0; i < tamano; ++i) 
		{
            copiaArray[i] = array[i];
        }

        inicio = clock();

        for (int i = 0; i < tamano; i++) 
		{
            int minIdx = i;
            for (int j = i + 1; j < tamano; j++) 
			{
                if (copiaArray[j] < copiaArray[minIdx]) 
				{
                    minIdx = j;
                }
            }
            int temp = copiaArray[minIdx];
            copiaArray[minIdx] = copiaArray[i];
            copiaArray[i] = temp;
        }

        fin = clock();

        double tiempo = ((double)fin - inicio) / CLOCKS_PER_SEC * 1000.0;
        tiempoPromedio += tiempo;

        if (tiempoMinimo == -1.0 || tiempo < tiempoMinimo) 
		{
            tiempoMinimo = tiempo;
        }

        if (tiempoMaximo == -1.0 || tiempo > tiempoMaximo) 
		{
            tiempoMaximo = tiempo;
        }
    }

    tiempoPromedio /= repetir;

    printf("Selection Sort\n");
    printf("Tiempo promedio: %.2f ms\n", tiempoPromedio);
    printf("Tiempo minimo: %.2f ms\n", tiempoMinimo);
    printf("Tiempo maximo: %.2f ms\n\n", tiempoMaximo);
}

int main() 
{
    int i;
    int array[tamano];
    srand(time(NULL));
    for (i = 0; i < tamano; ++i) 
	{
        array[i] = rand() % 1000;
    }

    printf("Arreglo original:\n");
    for (i = 0; i < tamano; ++i) 
	{
        printf("%d ", array[i]);
    }
    printf("\n\n");

    insertionSort(array);
    bubbleSort(array);
    selectionSort(array);

    return 0;
}


