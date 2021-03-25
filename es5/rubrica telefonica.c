//Esercizio : Rubrica telefonica
//Paolo Martini 4BROB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct contatto
{
    int id;
    char nome[64];
    char numero[16];
}Tipocontatto;

typedef struct rubrica
{
    int num_inseriti;
    Tipocontatto db[MAX];
}Tiporubrica;

int inserisci(Tiporubrica *r, char *nome, char *numero);
char *torna_numero_da_nome(Tiporubrica *r, char *nome);
void stampa_rubrica (Tiporubrica *r);

int main()
{
    Tiporubrica *r;
    char *nome;
    char *numero;
    r = (Tiporubrica*)malloc(sizeof (Tiporubrica));
    r = NULL;
    int scelta;

    do{
        printf("inserisci:\n1. inserire un numero nella rubrica\n2. per cercare il numero con un nome\n3. stampa contatto\n 0. per uscire dal programma\n");   
        scanf("%d", &scelta);
    }while(scelta<0 || scelta>3);

    switch (scelta)
    {
    case 1:
        fflush(stdin);
        printf("Inserisci il nome del numero che vuoi inserire\n");   
        gets(nome);
        fflush(stdin);
        printf("Inserisci il numero del numero che vuoi inserire\n");   
        gets(numero);
        inserisci(r, nome, numero);

    case 2:
        /* code */
        fflush(stdin);
        printf("Inserisci il nome del numero che vuoi inserire\n");   
        gets(nome);
        printf("%s", torna_numero_da_nome(r, nome));

    case 3:
        /* code */
        printf("bru");
        stampa_rubrica(r); 
        break;

    case 0:
        /* code */
        printf("Grazie per aver usato il programma rubrica telefonica\n");
        break;
    
    default:
        printf("Errore!");
        break;
    }

    return 0;
}

int inserisci(Tiporubrica *r, char *nome, char *numero)
{
    Tipocontatto *p;
    if (r-> num_inseriti == MAX)
    {
            printf("rubrica piena");
            return -1;
    }
    p = &r->db[r->num_inseriti];

    strcpy(p->nome, nome);
    strcpy(p->numero, numero);
    p->id = r->num_inseriti;
    r->num_inseriti;

    return 0;
}

char *torna_numero_da_nome(Tiporubrica *r, char *nome)
{
    int i;
    Tipocontatto *p;

    for (i=0;i<MAX; i++){
        if (i==r->num_inseriti)
            break;
        p=&r->db[i];

        if (strcmp(p->nome, nome)==0)
            return p->numero;
    }
    return NULL;
}

void stampa_rubrica (Tiporubrica *r)
{
    printf("bru");
    int i;
    Tipocontatto *p;

    printf("\nStampa rubrica: %d contatti\n", r->num_inseriti);

    for (i=0; i<MAX; i++)
    {
        if (i == r->num_inseriti)
            break;
        p = &r->db[i];

        printf ("%s, %s\n", p->nome, p->numero);
    }
}

