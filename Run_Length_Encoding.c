#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void Encoding(char* var);  //--> funzione per l'Encoding
void Decoding(char* var);  //--> funzione per il Decoding

int main () {
    short scelta;  //variabile per la scelta tra Encoding e Decoding
    char var[MAX];   //stringa

    printf ("Cosa vuoi fare? \nEncoding\t0\n\t\tDecoding\t1\n");
    scanf ("%d", &scelta);

    //switch che sceglie tra le due funzioni
    switch (scelta)
    {
    case 0:
        Encoding(var);
        break;
    case 1:
        Decoding(var);
        break;
    default: 
        printf ("Errore: reiserisci la scelta");
        printf ("Cosa vuoi fare? \nEncoding\t0\n\t\tDecoding\t1\n");
        scanf ("%d", &scelta);
    }

    return 0;
}

void Encoding(char* var) {
    int length;         //lunghezza della stringa
    int cont = 1;       //conta quante lettere sono uguali, parte da 1 perchè il minimo di lettere è 1
    int a, b;           //inizializzo le variabili che utilizzerò nel for

    printf ("enter the string: ");
    scanf ("%s", var);

    //misura la lungezza della stringa
    for (a = 0; var[a] != '\0'; a++) {
        length = a;
    }

    //guardo ogni cella del vettore
    for (b = 0; b <= length; b++) {

        if (var[b] == var[b+1]) { //se la lettera della posizione precedente è uguale alla lettera nella posizione successiva:
            cont++;     //incremento il contatore delle lettere uguali 
        }
        else { //se la lettera della posizione precedente è diversa alla lettera nella posizione successiva:
            printf("%d%c", cont, var[b]);//stampo il numero di lettere uguaali e la lettara
            cont = 1;
        }
    }
    printf ("Fine encoding.\n");
}

void Decoding(char* var) {
    int length;                         // lunghezza della stringa
    int cont = 0;                       // contatore delle lettere, parte da 0 perchè non si sa se sono presenti tutte le lettere
    int a, b, c, d;                  // inizializzo levaraibili per i for

    printf ("enter the string: ");
    scanf ("%s", var);

    //misura la lungezza della stringa
    for (a = 0; var[a] != '\0'; a++) {
        length = a;
    }

    printf ("\n\tOperazione di Decoding in corso...\n\n");

    //controllo il numero di volte in cui bisogna stampare il carattere
    for (b = 0; b <= length; b++) {

        for (c = 0; c < 9; c++) {

            //individua il carattere numero
            if (var[b] <= '1' && var[b] >= '9') {
                cont = var[b] - '0';      //salvo il carattere numero in cont
            }
            else {

                //stampo la stringa
                for (d = 0; d < cont; d++) {
                    printf("%c", var[b]);
                }

                cont = 0;
            }
        }
    }

    printf ("\n\n\tProgramma terminato...\n");
}