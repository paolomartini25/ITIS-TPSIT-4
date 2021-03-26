//Paolo Martini 4^Brob 
//il programma deve richiedere all'utente il nome di un mese e poi deve fornire in output il numero di post di quel mese ed il numero totale di like ricevuto durante quel mese.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define DIM 10000
#define CAR_SEP ","


typedef struct dati{

    char *mese;
    int giorno;
    int id_post;
    int like;

}Tipodati;

int contarighe(FILE *fp);

void lettura(FILE *fp, Tipodati *dato);

int main(){
    FILE* punt_f =fopen("instagram.csv", "r");

    if (punt_f== NULL){
        printf ("Errore \n");
        return -1;
    }
    int n_righe = contarighe(punt_f);//conto il numero di righe e lo inserisco in n_righe
    
    punt_f = fopen("instagram.csv", "r");

    printf("a\n");

    Tipodati* carica = (Tipodati*)malloc(sizeof (Tipodati)*n_righe);

    lettura(punt_f, carica);

    free(carica);
    fclose(punt_f);

    return 0;
}

int contarighe(FILE *fp){
//conta le righe del file

    int cont = 0; //contatore delle righe
    char stringa[DIM];
    while (fgets(stringa,DIM,fp)){ //scorro le varie righe del file
        cont++; //aggiungo una riga
    }
    return cont;
}

void lettura(FILE *fp, Tipodati *dato){
//la funzione legge il file e carica nell'array di strutture le varie componenti
    int cont=0;
    char stringa[DIM]; 
    char *field;//è un arrey di char in cui non è definita la lunghezza

    printf("b\n");

    fgets(stringa,DIM,fp);//cancello la prima riga
    
    while(fgets(stringa,DIM,fp)){

        printf("c\n"); //per vedere se funziona 
           
        field = strtok(stringa, CAR_SEP);//inserisce in file la stringa tra la prima , e l'inizio
        strcpy((dato+cont)->mese, field);


        field = strtok(NULL, CAR_SEP);
        (dato+cont)->giorno = atoi(field);

        field = strtok(NULL, CAR_SEP);
        (dato+cont)->id_post = atoi(field);

        field = strtok(NULL, CAR_SEP);
        (dato+cont)->like = atoi(field);

        
        cont++;  
                                  
    }
}
