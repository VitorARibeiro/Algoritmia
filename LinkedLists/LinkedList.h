#include <stdlib.h>
#include <stdio.h>


typedef struct _Node{

	int Data;
	void* Next;

}NODE;

//-----Gerar Lista-----
NODE* NewList(); //Utilizada para criar uma nova lista, retorna apontador NULL

//-----Adicionar Elemetos-----
int AddFirst(NODE** Head,int Number); // Utilizada para adicionar um numero no inicio da lista complexidade O(1)
int AddLast(NODE** Head, int Number); // Utilizada para adicionar um numero no fim da lista complexidade O(n)
int Insert(NODE** Head , int Index, int Number); // Utilizada para inserir numero na lista Complexidade O(INDEX)

//-----Remover elementos-----
int RemoveFirst(NODE** Head); // Utilizada para remover o primeiro item da lista Complexidade O(1)
int RemoveLast(NODE** Head); // Utilizada para remover o ultimo item da lista Complexidade O(n)
int RemoveIndex(NODE** Head,int Index); // Utilizada para remover item da lista num certo index Complexidade O(n)
int RemoveNumber(NODE** Head, int Number); // Utilizada para remover a primeira apariçao de um certo numero Complexidade O(n);
int EmptyList(NODE** Head); //Utilizada para Remover todos os valores da lista O(n);

//-----Funcao de logica da lista-----

int ListSize(NODE* Head); // Retorna o tamanho da lista Complexidade O(n)
float SumList(NODE* Head); // Retorna a soma dos valores da lista Complexidade O(n)
float MulList(NODE* Head); // Retorna o valor da multiplicacao dos valores da lista Complexidade O(n)

//-----Mostrar elementos-----
void PrintList(NODE* Head); //Imprime valores da lista complexidade O(n)


