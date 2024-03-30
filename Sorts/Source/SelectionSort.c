#include <stdio.h>
#include <stdbool.h>
void printarray(int* array,int length){

for(int i = 0; i< length; i++){
    printf("%i ",array[i]);
}
printf("\n");
}


int main(){

int array[10] = {1,-2,6,3,8,-5,9,10,-3,7};
int length = sizeof(array)/sizeof(array[0]);

//selecionar o menor item e trocar

for (int i = 0; i < length -1; i++)
{
    int menor = array[i];
    int posicao = 0;
    for (int j = i+1; j < length; j++)
    {
        //procurar menor
        if(menor > array[j]){
            menor = array[j];
            posicao = j;
        }
        
    }

    if (menor < array[i]){
        //swap menor com i
        array[posicao] = array[i]; 
        array[i] = menor;
        printarray(array,length);
    }

    
}


printf("--Fim--\n");
printarray(array,length);

    return 0;
}