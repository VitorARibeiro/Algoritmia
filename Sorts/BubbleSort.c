// o(n²)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(int argc, char** argv ){

	// Obter Input

	int* array = (int*)malloc(sizeof(int)* (argc -1));

	for (int i = 1; i < argc; ++i)
	{
		array[i-1] = atoi(argv[i]);
	}

	//Selection Sort

	int temp;
	bool swaped = false;
	do{
		swaped = false;
		for (int i = 0; i < argc - 2; ++i)
		{
			if(array[i] > array[i+1]){

				//Swapping alg
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				swaped = true;
			}

		}	
	
		
	} while (swaped == true);


	

	//Mostrar resultado
	
	for (int i = 0; i < argc-1; ++i)
	{
		printf("%d ",array[i]);
	}

	printf("\n");

	return 0;
}