#include <stdlib.h>
#include <stdio.h>


typedef struct _Node{

	int Data;
	void* Next;

}NODE;

NODE* NewList(); //Utilizada para criar uma nova lista, retorna apontador NULL
int AddFirst(NODE** Head,int Number); // Utilizada para adicionar um numero no inicio da lista complexidade O(1)
int AddLast(NODE** Head, int Number); // Utilizada para adicionar um numero no fim da lista complexidade O(n)
int Insert(NODE** Head , int Index, int Number); // Utilizada para inserir numero na lista Complexidade O(INDEX)
int RemoveFirst(NODE** Head); // Utilizada para remover o primeiro item da lista Complexidade O(1)

void PrintList(NODE* Head); //Imprime valores da lista complexidade O(n)


