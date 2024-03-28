#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 40 //tive de mudar isto para 40 porque usei como base em alguma funcoes


typedef struct _VACINA{
    char farma[MAX];
    int lote, quantidade;
    float custo;
}VACINA;

typedef struct _LIST_NODE{
    void * data;
    struct _LIST_NODE * next;
}LIST_NODE;


typedef LIST_NODE * LIST;
#define DATA(node) ((node)->data)
#define NEXT(node) ((node)->next)

//deve ler dados do ficheiro dados.txt e colocar na lista, append no inicio
//fgets pega em linhas
int ReadList(LIST* lista){

    FILE* fptr;

    

    if((fptr = fopen("dados.txt","r")) == NULL){
        printf("Erro ao abrir ficheiro dados");
        return 0;
    }

    char* line = (char*)malloc(sizeof(char)*MAX);

    while(fgets(line,MAX,fptr) != NULL){
        // guardar dados da vacina na struct vacina
        VACINA* vacina = (VACINA*)malloc(sizeof(VACINA));
        
        strncpy(vacina->farma , strtok(line,";") , MAX);
        vacina->lote = atoi(strtok(NULL,";"));
        vacina->quantidade = atoi(strtok(NULL,";"));


        char * price_str = strtok(NULL,"\0");
        char *ptr = strchr(price_str, ',');
        if (ptr != NULL) { //caso exista a virgula;
            *ptr = '.';
        }
        vacina->custo = atof(price_str);
        

        //agora adicionar vacina a uma linked list
        //alocar novno node para lista
        LIST_NODE* new = (LIST_NODE*)malloc(sizeof(LIST_NODE));

        if(*lista == NULL){ // lista encontra-se vazia devemos criar head
            new->data = vacina;
            new->next = NULL;
            *lista = new;
        }else{//lista nao esta vazia devemos adicionar item
            new->data = vacina;
            new->next = *lista;
            *lista = new;
        }

    }
    fclose(fptr);
    free(line);

    return 1;

}

void printLista(LIST lista){
    printf("\n");
    while(lista != NULL){
        VACINA* vacina = (VACINA*)(lista->data);
        
        printf(" %s - %i - %i - %.2f \n", vacina->farma,vacina->lote,vacina->quantidade,vacina->custo );

        lista = lista->next;
    }


}

float custoLote(LIST lista, int lote){

  while(lista != NULL){

    VACINA* vacina = (VACINA*)(lista->data);

    if(vacina->lote == lote){
        float custo = vacina->custo*vacina->quantidade;
        return custo;
    }

    lista = lista->next;
  }
        
     printf("Lote nao encontrado\n");

    return 0;
}


int removeFarma(LIST* lista, char* farma){

    LIST Current = *lista;
    LIST Previous =  NULL;
    
    if(Current == NULL){
        printf("Lista Vazia\n");
        return 0;
    }

    while(Current != NULL){
        VACINA* vacina = Current->data;

        if (!strcmp(vacina->farma,farma)) // se forem iguas retorna 0 
        {
            if(Previous == NULL){ //primeiro item
                *lista = Current->next;
            }else{
                Previous->next = Current->next;
            }

            free(vacina);
            free(Current);

            Current = (Previous == NULL) ? *lista : Previous->next;
            //Current = *lista // caso Previous == NULL
            //Current = Previous->next // caso contrario


        }else{
            Previous = Current;
            Current = Current->next;
        }
    }

    
    return 1;

}


int main(){

    LIST lista = NULL;

    if(ReadList(&lista)){
        int lote;
        char farma[MAX];
        printLista(lista);

        printf("Indique o numero de lote: ");
        scanf("%i", &lote);
        printf("custo do lote : %f \n",custoLote(lista,lote));

        printf("Indique o nome de uma farmaceutica: ");
        scanf("%s",farma);
        removeFarma(&lista, farma);

        printLista(lista);
    }

    return 1;
}