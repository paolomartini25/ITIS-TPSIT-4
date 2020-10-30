#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DIM 50
#define NOMEFILE "sputifi.csv"
#define CARATTERE ","


/*
1.0 lettura csv 1.1 caricamento
2.0 random ordering

*/
typedef struct record {
    int numero;
    char nome[DIM], autore[DIM];
}tiporecord;

void lettura(FILE *fp, tiporecord *canzoni);

int main(){
    FILE* puntatore=fopen(NOMEFILE, "r");

    if (puntatore == NULL){
        printf ("Errore \n");
        return -1;
    }
    tiporecord carica[DIM];

    lettura(puntatore, carica);

    fclose (puntatore);
    return 0;
}

void lettura(FILE *fp, tiporecord *canzoni){
    int cont=0;
    char stringa[DIM]; 
    char *field;//è un arrey di char in cui non è definita la lunghezza
    
    while(fgets(stringa,DIM,fp)){
        
        /*
		fgets(stringa,DIM,fp);legge le righe del file una riga dopo l'altra (nome della variabile in vui salva la riga che hai letto, dimensione, file)
        fgets da falso quando finisce il file
        printf("%s\n",stringa);
        */
           
        field = strtok(stringa, CARATTERE); //salva in field la prima parte separata da stringa; strtok si tiene in memoria il numero della riga e quindi continua a lavorare sulla stessa riga
        canzoni[cont].numero = atoi(field); //atoi da stringa a numero intero; 
        printf("%d\n",canzoni[cont].numero);//numero,nome,autore

        field = strtok(NULL, CARATTERE);
        strcpy(canzoni[cont].nome, field);//prende in memoria una stringa e la duplica in un altra variabile
        printf("%s\n",canzoni[cont].nome); //nome,autore

        field = strtok(NULL, CARATTERE);    
        strcpy(canzoni[cont].autore, field);
        printf("%s\n",canzoni[cont].autore); //autore
        
        cont++;  
                                  
    }
}


