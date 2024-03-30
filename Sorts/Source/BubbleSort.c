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
bool sorted = false;
int length = sizeof(array)/sizeof(array[0]);

while(!sorted){
    sorted = true;
    for(int i = 0; i < length - 1; i++){

        if(array[i] > array[i+1]){
            sorted = false;
            int temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            printarray(array,length);
        }
    }
}

printf("--Fim--\n");
printarray(array,length);

    return 0;
}