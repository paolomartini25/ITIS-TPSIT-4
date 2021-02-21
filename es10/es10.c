#include "List.h"

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

    int cont = 1;
    while (tail != NULL){
        printf("\nelemento: %d, valore: %d\n", cont++, dequeue(&head, &tail)->valore);
    }
    //stampa(&head, &tail);

    free(head);
    free(tail);
}