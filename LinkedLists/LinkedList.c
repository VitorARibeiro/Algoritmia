#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
//-----Gerar lista-----
NODE* NewList(){
	//Iniciamos uma apontador para o inicio de uma lista NULL
	NODE* Head = NULL;
	return Head;
}

//-----Adicionar Conteudos-----
int AddFirst(NODE** Head,int Number){
	//Nas funcoes que altermos a lista temos de passar duplo apontador porque senao apenas fazemos alteracoes locais
		NODE* New;

		if((New = (NODE*)malloc(sizeof(NODE*))) == NULL){
			printf("Erro ao alocar memoria do NODE \n");
			return 1; //1 codigo de erro;
		}

		if(*Head == NULL){ //Caso a lista esteja vazia
			*Head = New;
			(*Head)->Data = Number;
			(*Head)->Next = NULL;
		}else{

			New->Data = Number;
			New->Next = (*Head);
			(*Head) = New;
		}
	
	return 0;
}

int AddLast(NODE** Head, int Number){

	NODE* New;

	if((New = (NODE*)malloc(sizeof(NODE*))) == NULL){
			printf("Erro ao alocar memoria do NODE \n");
			return 1; //1 codigo de erro;
		}

	if(*Head == NULL){ //Caso a lista esteja vazia
			*Head = New;
			(*Head)->Data = Number;
			(*Head)->Next = NULL;
		}else{
			NODE* TempNode = *Head;

			while(TempNode->Next != NULL){
				TempNode = TempNode->Next;
			}

			New->Data = Number;
			New->Next = NULL;
			TempNode->Next = New;

		}

		return 0;
}

int Insert(NODE** Head , int Index, int Number){

	NODE* New = (NODE*)malloc(sizeof(NODE*));
	int Count = 0;

	if(New == NULL){
		printf("Erro ao alocar memoria do NODE \n");
		return 1;
	}

	if(*Head == NULL && Index == 0){
		//inserir no inico de uma lista vazia
		*Head = New;
		(*Head)->Data = Number;
		(*Head)->Next = NULL;
		return 0;
	}else if(*Head == NULL && Index != 0){
		printf("Nao é possivel inserir no index %i de uma lista vazia \n", Index);
		return 1;
	}

	//Aqui so chegam listas nao vazias 

	if(Index == 0){
		//inserir no inicio caso a lista nao seja vazia
		New->Data = Number;
		New->Next = *Head;
		*Head = New;
		return 0;	
	}

	//copia da lista para percorrer
	NODE* TempNode = *Head;

	while(TempNode->Next != NULL && Count != Index - 1){
		TempNode = TempNode->Next;
		Count++;
	}

	if(TempNode->Next != NULL && Count == Index - 1){
		//para inserir na posicao 2 temos de estar na posicao 1
		void* TempPointer = TempNode->Next;
		New->Data = Number;
		TempNode->Next = New;
		New->Next = TempPointer;
		
	}else if(TempNode->Next == NULL && Count == Index -1){
		//Estamos a inserir no fim 
		New->Data = Number;
		New->Next = NULL;
		TempNode->Next = New;

	}
	else{
		printf("Nao é possivel aceder ao index %i numa lista de tamanho %i\n",Index,Count);
		return 1;
	}



	return 0;
}

//-----Remover Conteudos-----
int RemoveFirst(NODE** Head) {
    if (*Head == NULL) {
        printf("Nao e possivel remover itens de uma lista vazia \n");
        return 1;
    }

    NODE* temp = *Head;
    *Head = (*Head)->Next;
    free(temp);

    return 0;
}

int RemoveLast(NODE** Head){

	if(*Head == NULL){
		printf("Nao e possivel remover itens de uma lista vazia \n");
		return 1;
	}

	NODE* Current = (*Head);
	NODE* Previous = (*Head);

	while(Current->Next != NULL){

		Previous = Current;
		Current = Current -> Next;

	}

	Previous -> Next = NULL;
	free(Current);
}

int RemoveIndex(NODE** Head,int Index){

	if((*Head) == NULL){
		printf("Impossivel apagar item de uma lista vazia");
		return 1;
	}

	NODE* Current = (*Head);
	return 0;
}


//-----Mostrar Conteudos-----
void PrintList(NODE* Head){

	while(Head != NULL){

		printf("%i ", Head->Data);
		Head = Head->Next;
	}
	printf("\n");
}