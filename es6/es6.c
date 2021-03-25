#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define DIM 10000
#define CARATTERE ","

typedef struct record {
    char *data;
    char *stato;
    int codice_regione;
    char *denominazione_regione;
    float lat;
    float longi;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi; 
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
}Tiporecord;

int contarighe(FILE *fp);

void lettura(FILE *fp, Tiporecord *dati);

void top(int n_righe, Tiporecord dati->ricoverati_con_sintomi);

int main(){

    FILE* puntatore=fopen("data.csv", "r");

    if (puntatore == NULL){
        printf ("Errore \n");
        return -1;
    }
    int n_righe = contarighe(puntatore);
    
    puntatore = fopen("data.csv", "r");

    Tiporecord* carica = (Tiporecord*)malloc(sizeof (Tiporecord)*n_righe);

    lettura(puntatore, carica);

    int top(n_righe, carica)


    free(carica);//

    fclose (puntatore);
    return 0;
}

void lettura(FILE *fp, Tiporecord *dati){
//la funzione legge il file e carica nell'array di strutture le varie componenti
    int cont = 0;
    char stringa[DIM];

    printf("\nCaricamento dati...\n");
    fgets(stringa,DIM,fp);
    
    while(fgets(stringa,DIM,fp)){

        strcpy((dati+cont)->data, strtok(stringa, CARATTERE));
  
        strcpy((dati+cont)->stato, strtok(NULL, CARATTERE));

        (dati+cont)->codice_regione = atoi(strtok(NULL, CARATTERE)); 
        printf("\n%d\n", (dati+cont)->codice_regione);

        strcpy((dati+cont)->denominazione_regione, strtok(NULL, CARATTERE));

        (dati+cont)->lat = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->longi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->ricoverati_con_sintomi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->terapia_intensiva = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->totale_ospedalizzati = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->isolamento_domiciliare = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->totale_positivi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->variazione_totale_positivi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->nuovi_positivi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->dimessi_guariti = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->deceduti= atoi(strtok(NULL, CARATTERE));

        (dati+cont)->casi_da_sospetto_diagnostico; = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->casi_da_screening = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->totale_casi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->tamponi = atoi(strtok(NULL, CARATTERE));

        (dati+cont)->casi_testati= atoi(strtok(NULL, CARATTERE));

        cont++;
                          
    }
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


void top(int n_righe, Tiporecord *dati, int *uno, int *due, int *tre){
    // top 3 delle regioni per numero di ricoveri in terapia intensiva

    int nuno = 0;
    char *runo;
    int ndue = 0;
    char *rdue;
    int ntre = 0;
    char *rtre;

    for (int j = 0; j < n_righe; j++){
        
        if (uno <(dati+j)->ricoverati_con_sintomi){
            nuno = (dati+j)->ricoverati_con_sintomi;
            (dati+j)->denominazione_regione
        }else if(due <(dati+j)->ricoverati_con_sintomi){
            ndue = (dati+j)->ricoverati_con_sintomi;
        }else if(tre <(dati+j)->ricoverati_con_sintomi){
            ntre = (dati+j)->ricoverati_con_sintomi;
        }
    }

    printf("le top  3 regini per numero di ricovera")

}