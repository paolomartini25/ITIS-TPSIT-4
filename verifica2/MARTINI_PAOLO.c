/*
Un mazzo di carte da gioco è costituito da 52 carte: 13 carte per ogni seme. Realizzare un programma in linguaggio C in cui ogni seme è rappresentato da un char :
‘C’: cuori
‘P’: picche
‘D’: quadri
‘F’: fiori
mentre ogni carta di un seme è rappresentata da un numero intero compreso tra 1 e 13.

All’interno del programma:

Realizzate una struttura auto-referenziata opportuna che permetta di memorizzare l’intero mazzo di carte sotto forma di coda FIFO. 

All’interno del main(), riempire il mazzo di carte, utilizzando l’opportuno metodo delle code. (BONUS: riempire il mazzo con le carte in ordine casuale)

Successivamente all’interno del main() realizzate il seguente procedimento:
Ad ogni turno viene estratta la carta in fondo al mazzo
Se la carta estratta è nera (fiori o picche) viene scartata, altrimenti se la carta estratta è rossa (cuori o quadri) essa viene collocata in cima al mazzo
I turni finiscono quando il mazzo è composto soltanto di carte rosse
Stampate tutte le carte del mazzo dopo l’intero procedimento
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char seme;
    int valore;
    struct node* next;
}Nodo;

void enqueue (struct node **head, struct node **tail, struct node *element);
struct node *dequeue(struct node **head, struct node **tail);
int is_empty(struct node *head);

void riempimazzo(struct node **head, struct node **tail);
void estraicarta(struct node **head, struct node **tail);
void stampacarte(struct node **head, struct node **tail);

int main(){
    struct node* head; 
    struct node*tail; 
    
    

    //alloco inamicamente testa e coda
    head = (struct node*)malloc(sizeof (struct node));
    tail = (struct node*)malloc(sizeof (struct node));

    //setto la testa e la coda come vuote
    head = NULL;
    tail = NULL;

    riempimazzo(&head, &tail);
    estraicarta(&head, &tail);
    stampacarte(&head, &tail);
}

void riempimazzo(struct node **head, struct node **tail){
    //riempi mazzo serve per riempire il mazzo con 52 carte di 4 semi diversi, ogni seme ha 13 carte
    int nsemi = 4;//numero di semi nel mazzo
    int ncarte = 13;//numero di carte per seme
    char cseme;
    
    for (int j = 0; j<nsemi; j++){ //questo for gira per il numero di semi
         printf("prova 10");
        switch(j){ //imposto il seme
            case 0: //se l'indice del for è uguale a 0
                cseme = 'C'; //il seme sarà cuori
                break;
            
            case 1: //se l'indice del for è uguale a 1
                cseme = 'P'; //il seme sarà picche
                break;

            case 2: //se l'indice del for è uguale a 2
                cseme = 'D'; //il seme sarà quadri
                break;

            case 3: //se l'indice del for è uguale a 3
                cseme = 'F'; //il seme sarà fiori
                break;
            
        }
        
        for(int i=0; i<ncarte; i++){ //questo for gira per il numero di carte per seme
            printf("prova 20");
            struct node* elemento;
            elemento = (struct node*)malloc(sizeof (struct node)); //alloco l'elemento
            
            //salvo nell'elemento il seme ed il valoredella carta
            elemento->seme = cseme; 
            elemento->valore = i;
            enqueue(head, tail, elemento); // salvo l'elemento nella coda
            free(elemento);//dealloco l'elemento
        }
    }
}

void estraicarta(struct node **head, struct node **tail){
    //estraicarte serve per estrarre le carte dal fondo del mazzo e se sono cuori o quadri le rimette in cima
    printf("prova3");
    int ncartetot = 52; //numro totale di carte
    for(int a=0; a<ncartetot; a++){ //questo for gira per il numero totale di carte
        
        struct node* out;
        out = (struct node*)malloc(sizeof (struct node)); //alloco l'elemento  
        out = dequeue(head, tail); //salvo in out l'elemento estratto dalla coda
        
        if (out->seme == 'C' || out->seme == 'D'){ //se il seme è cuori o quadri la carta viene messa in cima al mazzo
            printf("prova5");
            enqueue(head, tail, out);
        }
        free(out); //dealloco out
    }
}

void stampacarte(struct node **head, struct node **tail){
    //stampacarte serve per stampare l'intera coda

    printf("prova1");

    while (tail != NULL){
        printf("prova2");
        struct node* out;
        out = (struct node*)malloc(sizeof (struct node)); //alloco l'elemento  
        out = dequeue(head, tail); //salvo in out l'elemento estratto dalla coda
        switch (out->seme)
        {
        case 'C': //se il seme è cuori
            printf("\nSeme: Cuori, Numero: %d\n", out->valore);
            break;

        case 'P': //se il seme è picche
            printf("\nSeme: Picche, Numero: %d\n", out->valore);
            break;
        
        case 'D': //se il seme è quadri
            printf("\nSeme: Quadri, Numero: %d\n", out->valore);
            break;

        case 'F': //se il seme è fiori
            printf("\nSeme: Fiori, Numero: %d\n", out->valore);
            break;
        }
        free(out); //dealloco out
    }
}

void enqueue (struct node **head, struct node **tail, struct node *element){
    if (is_empty(*head)) {
        *head = element;
    }
    else{
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

struct node *dequeue(struct node **head, struct node **tail){
    struct node *ret = *head;
    if (is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

int is_empty(struct node *head){
    if(head == NULL) return 1;
    else return 0; //lista piena
}
