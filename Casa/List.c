#include <stdlib.h>
#include <stdio.h>


typedef struct _node{
    struct _node *next;
    int data;
}NODE;

NODE *head = NULL;

NODE* listAdd(int _data){

    NODE *new = NULL;

    if(head == NULL){
        new = (NODE*)malloc(sizeof(NODE));
        new->data = _data;
        new->next = NULL;
        head = new;

    }else{
        new = (NODE*)malloc(sizeof(NODE));
        new->data = _data;
        new->next = head;
        head = new;

    }

    return new;
}

void listPrint(void){
    printf("\n----\n");
    NODE* current = head;
    while(current != NULL){

        printf("%d-",current->data);
        current = current->next;
    }
    printf("\n----\n");
}

int listRemove(int _data){
    NODE* current = head;
    NODE* previous = head;
    
    while(current != NULL){

        if(current->data == _data){
            if(current == head){
                head = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            current = NULL;
            return 0;
        }

        previous = current;
        current = current->next;
    }

    return 1;

}

NODE* listInsert(int _index , int _data){
    NODE* new = NULL;
    NODE* current = head;
    NODE* previous = head;
    int index = 0;

    while(current != NULL){
        if(_index == index){
            new = (NODE*)malloc(sizeof(NODE));
            new->data = _data;

            if(index == 0){
                new->next = head;
                head = new;
            }else{
                //new->next = current->next
                //current->next = new;
                previous->next = new;
                new->next = current;

            }
        }
        previous = current;
        current = current->next;
        index ++;
    }

    return current;
}

void printMenu(){

    printf("\t1 -> Mostrar lista\n");
    printf("\t2 -> Adicionar item a lista\n");
    printf("\t3 -> Remover item da lista\n");
    printf("\t4 -> Inserir item a lista\n");
}

int main(int argc , char **argv){


    int opt,add,pos,data;

    while(1){

        printMenu();
        scanf("%d",&opt);

        switch (opt)
        {
        case 1:
            //print lista
            listPrint();
            break;
        case 2:
            //add
            
            printf("Que numero deseja adicionar?: ");
            scanf("%d",&add);
            listAdd(add);
            break;
        case 3:
            
            printf("Indique que numero quer remover: ");
            scanf("%d",&data);
            listRemove(data);
            break;
        case 4:

            printf("indique a posicao e data (p,d):" );
            scanf("%d,%d",&pos,&data);
            listInsert(pos,data);
            break;
        default:
            return 1;
            break;
        }
    }
    return 0;
}