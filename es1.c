//Paolo Martini 4^B ROB
//calcola i giorni in cui vengono contagiati un certo numero di persone

#include <stdio.h>
#include <stdlib.h>

void richiesta_dati(float *R, int *N);

int calcolo_contagiati(int *contagiati, int N, int R);

int main()
{
	float R = 0; //percentuale contagio
	int N = 0; //numero di alunni

	int* contagiati = (int*)malloc(sizeof(int)); //vettore che contiene il numero di contagiati
	
	richiesta_dati(&R, &N);
	
    int n_giorni = calcolo_contagiati(contagiati, N, R);
	
	printf("Giorno %d:\nSono stati contagiati tutti!\n\n", n_giorni);
    
	return 0;
}

void richiesta_dati(float *R, int *N){
    //richiesta dei dati in input
    printf("inserire il valore di contagio\n");
	scanf("%f", R); //richiedo la percentuale di contagio

	printf("Quanti alunni ci sono sella tua\n");
	scanf("%d", N); //richiedo il numero di alunni
}

int calcolo_contagiati(int *contagiati, int N, int R){
    //calcolo il numero di giorni necessari per contagiati tutti
    int n_giorni = 0;
    int i = 0;
    *(contagiati+i) = 1; //i contagiati nel giorno 0 sono 1

	for (i = 0; N > contagiati[i]; i++) //il ciclo ripete finchè tutti gli alunni non sono stati contagiati
	{
		contagiati = realloc(contagiati, ((i+2)*sizeof(int)));//aumento la dimensione dell'array per poter inserire nuovamente il numero di contagiati
		
		contagiati[i + 1] = contagiati[i] + (contagiati[i] * R); //calcolo il numero di contagiati

		n_giorni = i + 1;
		
		printf("Giorno %d:\nContagiati:%d\n\n", n_giorni, contagiati[i]);
	}
    return ++n_giorni;
}