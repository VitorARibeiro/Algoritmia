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

int merge(int array[], int startIndex, int meioIndex, int endIndex)
{
    // criar sub arrays
    int n1 = meioIndex - startIndex + 1;
    int n2 = endIndex - meioIndex;

    int arr1[n1];
    int arr2[n2];

    // preencher arrays
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = array[startIndex + i];
    }

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = array[meioIndex + 1 + i];
    }

    // em seguida preencher array original
    int itN1 = 0;
    int itN2 = 0;
    int it = startIndex;
    while (itN1 < n1 && itN2 < n2)
    {
        if (arr1[itN1] < arr2[itN2])
        {
            array[it] = arr1[itN1];
            itN1++;
        }
        else
        {
            array[it] = arr2[itN2];
            itN2++;
        }

        it++;
    }

    // por n1 ou n2 podem ainda nao estar vazias

    while (itN1 < n1)
    {
        array[it] = arr1[itN1];
        itN1++;
        it++;
    }

    while (itN2 < n2)
    {
        array[it] = arr2[itN2];
        itN2++;
        it++;
    }

    return 0;
}

int mergeSort(int array[], int startIndex, int endIndex)
{

    if (startIndex < endIndex)
    {

        int meioIndex = (endIndex + startIndex) / 2;
        mergeSort(array, startIndex, meioIndex);
        mergeSort(array, meioIndex + 1, endIndex);

        merge(array, startIndex, meioIndex, endIndex);
    }

    return 0;
}

int main()
{

    int array[10] = {1, -2, 6, 3, 8, -5, 9, 10, -3, 7};
    int length = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, length - 1);

    printarray(array, length);

    return 0;
}