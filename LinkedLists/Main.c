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
	
	RemoveFirst(&Lista); //Remove o primeiro elemento da lista
	RemoveLast(&Lista); //Remove o ultimo elemento da lista
	RemoveIndex(&Lista,3); // Remove o elemento no index 3
	RemoveNumber(&Lista,7); // Remove o primeiro elemento 7

	EmptyList(&Lista); // Remove todos os elementos da lista
	
	PrintList(Lista); // Mostra a lista

	AddFirst(&Lista, 5);
	AddFirst(&Lista, 2);
	AddFirst(&Lista,3);

	PrintList(Lista);


	printf("A lista tem tamanho : %i\n",ListSize(Lista));
	printf("A soma é: %f\n",SumList(Lista));
	printf("A multiplicaçao é: %f\n",MulList(Lista));




	
	return 0;
}