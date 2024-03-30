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

for(int i = 1 ; i < length ; i++){

int j = i - 1 ; 
int key = array[i];

while(j >= 0 && array[j] > key){

    
    array[j+1] = array[j];
    array[j] = key;
    printarray(array,length);
    key = array[j];
    j--;
}


}

printf("--Fim--\n");
printarray(array,length);

    return 0;
}