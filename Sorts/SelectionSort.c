// o(n²)

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv ){

	// Obter Input

	int* array = (int*)malloc(sizeof(int)* (argc -1));

	for (int i = 1; i < argc; ++i)
	{
		array[i-1] = atoi(argv[i]);
	}

	//Selection Sort

	

	for(int j = 0;j<argc-1;j++){

		int indexTracker,temp;
		int min = array[j];

		for (int i = j; i < argc -1; ++i)
		{
			if(array[i]<= min){
				indexTracker = i;
				min = array[i];
			}
	
		}
		//encontrou minimo, swap
		temp = array[j];
		array[j] = min;
		array[indexTracker] = temp;
		
	}

	//Mostrar resultado
	
	for (int i = 0; i < argc-1; ++i)
	{
		printf("%d ",array[i]);
	}

	printf("\n");

	return 0;
}