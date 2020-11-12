#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define DIM 50
#define NCANZONI 11
#define CARATTERE ","


/*
1.0 lettura csv 1.1 caricamento
2.0 rm ordering
*/
typedef struct record {
    int numero;
    char nome[DIM], autore[DIM];
    bool riprodotte;
}Tiporecord;

int contarighe(FILE *fp);

void lettura(FILE *fp, Tiporecord *canzoni);

void stampa_r(FILE *fp, Tiporecord *canzoni);

int main(){
    FILE* puntatore=fopen("sputifi.csv", "r");

    if (puntatore == NULL){
        printf ("Errore \n");
        return -1;
    }
    int n_righe = contarighe(puntatore);
    
    puntatore = fopen("sputifi.csv", "r");

    Tiporecord* carica = (Tiporecord*)malloc(sizeof (Tiporecord)*n_righe);

    lettura(puntatore, carica);

    stampa_r(puntatore, carica);

    fclose (puntatore);
    return 0;
}

void lettura(FILE *fp, Tiporecord *canzoni){
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
        //numero,nome,autore

        field = strtok(NULL, CARATTERE);
        strcpy(canzoni[cont].nome, field);//prende in memoria una stringa e la duplica in un altra variabile
        //nome,autore

        field = strtok(NULL, CARATTERE);    
        strcpy(canzoni[cont].autore, field);
        //autore
        
        cont++;  
                                  
    }
}

void stampa_r(FILE *fp, Tiporecord *canzoni){

    int nriproduzioni;
    int rm;
    printf("Quante volte vuoi riprodurre la playlist? ");
    scanf("%d", &nriproduzioni);
    for (int n = 0; n < NCANZONI; n++){
        canzoni[n].riprodotte = false;                               //se è false la canzone non è stata riprodotta mentre se è true è già stata riprodotta
    }
    for (int i = 0; i < nriproduzioni; i++) {                              //si riproducono tutte le canzoni nriproduzioni volte
        printf("Sto riproducendo per la %d^ volta.\n\n", i+1);

        for (int j = 0; j < NCANZONI; j++)                                //per ogni canzone                                    
            {
                do{
                    rm = rand() % NCANZONI;
                }while (canzoni[rm].riprodotte);                         //ripete finchè la canzone non è stata riprodotta: quindi riprodotte==false
                    
                canzoni[rm].riprodotte = true;                            //esce dal do while solo se tutte la canzoni sono state riprodotte
                printf("sto riproducendo:\n%s\n%s\t\n\n", canzoni[rm].nome, canzoni[rm].autore);         
            }
            for (int k = 0; k < NCANZONI; k++){
                canzoni[k].riprodotte = false;                                   //resetto la playlist
            }
    }

}

int contarighe(FILE *fp){
    int cont = 0;
    char stringa[DIM];
    while (fgets(stringa,DIM,fp)){
        cont++;
    }
    return cont;
}