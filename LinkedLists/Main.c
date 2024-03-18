#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"

int main(){


	NODE* Lista = NewList();

	AddLast(&Lista,5); //adiciona no fim mas a lista esta vazia
	AddFirst(&Lista,3); //adiciona 3 no inicio
	AddFirst(&Lista,7); //adiciona 7 no inicio
	AddLast(&Lista,1); // adiciona 1 no fim

	Insert(&Lista,0,2); // adiciona 2 no index 0 (inicio)
	Insert(&Lista,3,4); // adiciona 4 no index 3
	
	RemoveFirst(&Lista);
	RemoveLast(&Lista);


	

	PrintList(Lista);
	return 0;
}