#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOMEFILE "rna.txt"
#define DIM 100

int main(){
    FILE* puntatore=fopen(NOMEFILE, "r");

    if (puntatore == NULL){
        printf ("Errore \n");
        return -1;
    }
        
    char stringa[DIM];
    char carattere, t, c, g, a;

    while(fgets(stringa,DIM,puntatore)){

            int cont = 0;

            while(stringa[cont] != '\0')
            
            switch(stringa[cont]){

                case 't':
                t++;
                break;

                case 'c':
                c++;
                break;

                case 'g':
                g++;
                break;

                case 'a':
                a++;
                break;

            }
            cont++;
    }

    printf("Il numero di guanina è:%d\n", g);
    printf("Il numero di citosina è:%d\n", c);
    printf("Il numero di timina è:%d\n", t);
    printf("Il numero di adenina è:%d\n", a);

    fclose (puntatore);
    return 0;
}
