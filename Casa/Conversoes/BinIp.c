#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

	int array[8] = {128,64,32,16,8,4,2,1};

	char* primeiroStr = strtok(argv[1],".");
	char* segundoStr = strtok(NULL,".");
	char* terceiroStr = strtok(NULL,".");
	char* quartoStr = strtok(NULL,".");

	int primeiroInt = 0;
	int segundoInt = 0;
	int terceiroInt = 0;
	int quartoInt = 0;

	for (int i = 0; i < 8; ++i)
	{
		primeiroInt += (primeiroStr[i] - 48) * array[i];
		segundoInt += (segundoStr[i] - 48) * array[i];  	
		terceiroInt += (terceiroStr[i] - 48) * array[i];  	
		quartoInt += (quartoStr[i] - 48) * array[i];  	  	
	}	

	printf("%d.%d.%d.%d\n", primeiroInt,segundoInt,terceiroInt,quartoInt);





	return 0;
}