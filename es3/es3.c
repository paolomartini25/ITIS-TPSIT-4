#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define DIM 50
#define CARATTERE ","

typedef struct record {
    int numero; //numero della canzone
    char nome[DIM], autore[DIM]; //nome e autore della canzone
    struct record * next;
    bool riprodotte; //canzone già riprodotta o no
}Tiporecord;

void push(Tiporecord* head, char* stringa, int cont);

int lettura(FILE *fp, Tiporecord *head);

void stampa(Tiporecord *head, int ncanzoni);

int main(){
    FILE* puntatore=fopen("sputifi.csv", "r");

    if (puntatore == NULL){
        printf ("Errore \n");
        return -1;
    }
    
    puntatore = fopen("sputifi.csv", "r");

    Tiporecord* prima_canzone = (Tiporecord*)malloc(sizeof (Tiporecord));

    printf("Inizio la lettura.\n");

    int numcanzoni = lettura(puntatore, prima_canzone);

    stampa(prima_canzone, numcanzoni);

    fclose (puntatore);
    return 0;
}

void push(Tiporecord* head, char* stringa, int cont){
    //aggiunge i dati della canzone in fondo alla lista

    char *field; //inizializzo una strigna d'appoggio di dimensione non specificata.

    if(cont == 0){
        //0,nomecanzone,autore

        field = strtok(stringa, CARATTERE); // salvo in field la prima parte di stringa separata dalla virgola: "0" (lo zero è un carattere non un numero intero)
        head->numero = atoi(field); // salvo il numero della canzone trasformato in intero

        field = strtok(NULL, CARATTERE); // salvo in field la seconda parte di stringa separata dalle virgole: "nomecanzone"
        strcpy(head->nome, field); // salvo il nome della canzone

        field = strtok(NULL, CARATTERE); // salvo in field la terza parte di stringa separata dalle virgole: "autore"
        strcpy(head->autore, field); // salvo il nome dell'autore che ha prodotto la canzone

        head->riprodotte = false; //setto la canzone come non riprodotta

        head -> next = NULL; // setto la testa come ultimo elemento della lista
    }
    else{
        Tiporecord* puntatore_appoggio = head;

        while(puntatore_appoggio->next != NULL){

            puntatore_appoggio = puntatore_appoggio->next;
        
        }//scorro la lista fino a quando non arrivo all'ultimo elemento


        puntatore_appoggio->next = (Tiporecord*)malloc(sizeof(Tiporecord));

        //1,nomecanzone,autore

        field = strtok(stringa, CARATTERE); // salvo in field la prima parte di stringa separata dalla virgola: "1" (l'uno è un carattere non un numero intero)
        puntatore_appoggio->next->numero = atoi(field); //puntatore_appoggio->next ha la valenza dell'ultimo nome; salvo il numero della canzone trasformato in intero
        
        field = strtok(NULL, CARATTERE); // salvo in field la seconda parte di stringa separata dalle virgole: "nomecanzone"
        strcpy(puntatore_appoggio->next->nome, field); // salvo il nome della canzone

        field = strtok(NULL, CARATTERE); // salvo in field la terza parte di stringa separata dalle virgole: "autore"
        strcpy(puntatore_appoggio->next->autore, field);// salvo il nome dell'autore che ha prodotto la canzone

        puntatore_appoggio->next->riprodotte = false; //setto la canzone come non riprodotta
        puntatore_appoggio->next->next=NULL; //setto la linea successiva come l'ultima
    }
} 

int lettura(FILE *fp, Tiporecord *head){
//la funzione legge il file e carica nella lista le varie canzoni
    
    int cont=0; //numero di canzoni
    char stringa[DIM];
    
    while(fgets(stringa,DIM,fp)){//in ogni ciclo viene salvata una riga del file, partendo dalla seconda, in striga. quando termina il file la finzione fgets ritorna NULL 

        push(head, stringa, cont); // viene passata in push la prima canzone, ovvero la testa della lista, e la stringa da salvare a fine lista

        cont++;
    }
    cont--;

    printf("\nlettura terminata!\n");

    return cont;// ritorno nel main il numero 
}

void stampa(Tiporecord *head, int ncanzoni){
    //riproduce le canzoni in modo casuale

    printf("\ninizio reiproduzione delle canzoni, numero di canzoni: %d\n\n", ncanzoni);

    Tiporecord* puntatore_appoggio;
    int rm; //variabile che contiene il numero randomico

    for (int j = 0; j < ncanzoni; j++){
        do{
            puntatore_appoggio = head; //puntatore_appggio punta alla prima canzone
            rm = rand() % ncanzoni; //genero un numero randomico

            for (int i=0; i < rm; i++){ //cerco la canzone numero rm
                puntatore_appoggio = puntatore_appoggio -> next;
            }

        }while(puntatore_appoggio->next->riprodotte); //guardo se la canzone rm è già stata riprodotta

        puntatore_appoggio->next->riprodotte = true; //setto la canzone come già riprodotta

        printf("sto riproducendo:\n%s\n%s\t\n\n", puntatore_appoggio->next->nome, puntatore_appoggio->next->autore); //riproduco la canzone
    }
}