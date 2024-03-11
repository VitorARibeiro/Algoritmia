#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){

	// raw ip is argv[1]


	int primeiro = atoi(strtok(argv[1],"."));
	int segundo = atoi(strtok(NULL,"."));
	int terceiro = atoi(strtok(NULL,"."));
	int quarto = atoi(strtok(NULL,"."));



	char* primeiroBin = (char*)malloc(sizeof(char) * 8); // cada ip so pode ter 8 bits.
	char* segundoBin = (char*)malloc(sizeof(char) * 8);
	char* terceiroBin = (char*)malloc(sizeof(char) * 8);
	char* quartoBin = (char*)malloc(sizeof(char) * 8);

	for(int i = 7 ; i >= 0; i--){
		primeiroBin[i] = primeiro%2 + 48;
		primeiro /= 2;

		segundoBin[i] = segundo%2 + 48;
		segundo /= 2;

		terceiroBin[i] = terceiro%2 +48;
		terceiro /= 2;

		quartoBin[i] = quarto%2 +48;
		quarto /= 2 ;

	}

	// converter de int* para string
	printf("%s.%s.%s.%s\n",primeiroBin,segundoBin,terceiroBin,quartoBin);
	


	return 0;
}