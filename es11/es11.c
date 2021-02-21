#include "List.h"

void invertiCoda(struct node* head, struct node* tail);

int main(){
    char continua = 'y';
    int val;

    struct node* head;
    struct node*tail;
    struct node* elemento;

    head = (struct node*)malloc(sizeof (struct node));
    tail = (struct node*)malloc(sizeof (struct node));

    head = NULL;
    tail = NULL;

    do{
        elemento = (struct node*)malloc(sizeof (struct node));
        fflush(stdin);
        printf("\ninserisci un numero: ");
        scanf("%d", &val);

        elemento->valore = val;
        enqueue(&head, &tail, elemento);

        fflush(stdin);
        printf("inserisci y se vuoi continuare\n");
        scanf("%c", &continua);
    }while(continua == 'y');

    invertiCoda(head, tail);
    
    free(head);
    free(tail);
}


void invertiCoda(struct node* head, struct node* tail){

    struct node* pila;
    pila = (struct node*)malloc(sizeof (struct node));
    pila = NULL;

    printf("Stampo la coda nel verso corretto.\n");
    int cont = 1;
    while (tail != NULL){
        struct node* elemento = dequeue(&head, &tail);
        printf("\nelemento: %d, valore: %d\n", cont++, elemento->valore);
        push(&pila, elemento);
    }

    while(!is_empty(pila)){//salvo nella seconda coda la pila
        enqueue(&head, &tail, pop(&pila));
    }
    free(pila);

    printf("\nStampo la coda al contrario.\n");
    
    while (tail != NULL){
        struct node* elemento = dequeue(&head, &tail);
        printf("\nelemento: %d, valore: %d\n", --cont, elemento->valore);
    }
}