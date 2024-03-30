#include <stdio.h>
#include <stdlib.h>

void printarray(int array[], int length)
{

    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }

    printf("\n");
}

int swapFunction(int *p1, int *p2)
{

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;


    return 0; // sem erros
}

int partition(int array[], int startIndex, int endIndex)
{

    printf("\nParticao de %i ate %i\n", startIndex, endIndex);
    int pivot = array[endIndex];
    int partitionIndex = startIndex;

    for (int i = startIndex; i < endIndex; i++)
    {
        if (array[i] <= pivot)
        {
            if (array[i] == array[partitionIndex])
                partitionIndex++;
            else
            {
                swapFunction(&array[i], &array[partitionIndex]);
                printarray(array,10); // aqui tem o tamanho da array para prints de debug
                
                partitionIndex++;
            }
        }
    }
    printf("--Swap pivot--\n");
    swapFunction(&array[partitionIndex], &array[endIndex]);
    printarray(array,10); // aqui tem o tamanho da array para prints de debug

    return partitionIndex;
}

int quickSort(int array[], int startIndex, int endIndex)
{

    if (startIndex < endIndex)
    {
        int partitionIndex = partition(array, startIndex, endIndex);
        quickSort(array, partitionIndex + 1, endIndex);
        quickSort(array, startIndex, partitionIndex - 1);
    }

    return 0;
}

int main()
{

    int array[] = {1, -2, 6, 3, 8, -5, 9, 10, -3, 7};
    int length = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, length - 1);


    printf("--Fim--\n");
    printarray(array, length);

    return 0;
}