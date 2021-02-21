#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct nodo {
    char valore;
    struct nodo* next;
} Nodo;


int is_empty(Nodo* head){ //ritorna 1 se la lista è vuota, 0 altrimenti
    if(head == NULL) return 1;
    else return 0;
}

void push(Nodo **head, Nodo* elemento){
    if(is_empty(*head)){
        *head = elemento;
        elemento -> next = NULL;

    }
    else {
        elemento -> next = *head; //l'elemento punta alla testa
        *head = elemento; //la testa diventa l'elemento
        //questo equivale alla push
    }
}

Nodo* pop(Nodo **head){ //pop
    Nodo* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    return ret;
}

int main(){
    
    int ncifre;


    printf("Quante cifre ha il numero che andrai a inserire? \n");
    scanf("%d", &ncifre);
    char numero[ncifre];

    printf("Inserisci un numero intero: \n");
    fscanf(stdin, "%s", numero);

    //ncifre = strlen();

    Nodo* pila = (Nodo*)malloc(sizeof (Nodo));
    
    int cifra;
    int resto;
    int cont = 0;

    for(int i = 0; i < ncifre; i++){
        Nodo* elemento = (Nodo*)malloc(sizeof (Nodo));
        elemento->valore = *(numero+i);
        push(&pila, elemento);
    }

    //printf("\n\n%c\n", pila->valore);

    for(int i = 0; i < ncifre; i++){
        Nodo* out = (Nodo*)malloc(sizeof (Nodo));
        out = pop(&pila);
        printf("\n%c", out->valore);
        free(out);
    }

    return 0;
}