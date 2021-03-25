
//struttura autoreferenziata

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int val;
    struct nodo * next;
}Nodo;

void push(Nodo* head, int valore){
    //aggiunge un elemento in fondo alla lista contenente un valore

    Nodo* puntatore_appoggio = head;
    while(puntatore_appoggio->next != NULL){
        puntatore_appoggio = puntatore_appoggio->next;
    }
    //Qui siamo arrivati all'ultimo elemento della lista

    puntatore_appoggio->next = (Nodo*)malloc(sizeof(Nodo));
    puntatore_appoggio->next->val = valore; //puntatore_appoggio->next ha la valenza dell'ultimo nome

} 

int main (){
    Nodo * primo_elemento;
    /*
    Nodo * secondo_elemento;
    Nodo * terzo_elemento;
    */

    primo_elemento = (Nodo*)malloc(sizeof(Nodo));
    
    /*
    secondo_elemento = (Nodo*)malloc(sizeof(Nodo));
    terzo_elemento = (Nodo*)malloc(sizeof(Nodo));
    */

    primo_elemento -> val = 1;
    primo_elemento -> next = NULL;

    push(primo_elemento, 2);
    push(primo_elemento, 3);

    /*
    secondo_elemento -> val = 2;
    secondo_elemento -> next = terzo_elemento;
    terzo_elemento -> val = 3;
    terzo_elemento -> next = NULL;
    */

    Nodo * puntatore_appoggio;
    puntatore_appoggio = primo_elemento;
    while(puntatore_appoggio != NULL){
        printf("il valore è %d.\n", puntatore_appoggio -> val);
        puntatore_appoggio = puntatore_appoggio -> next;
    }

}