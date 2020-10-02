//Paolo Martini 4^B ROB

#include <stdio.h>
#include <stdlib.h>

float R, N;
int giorni;

void questions();
int calculations();

int main()
{

    questions();
    int tg = calculations();
    printf("\nCi vogliono %d giorni per contagiare tutti! \n",tg);

    return 0;
}

void questions(){

    printf("Quante persone contagia una persona in media? (suggerimento 1.4)\n");
    scanf("%f", &R);
    printf("Quanti compagni di classe hai? (esempio 21)\n");
    scanf("%f", &N);
    printf("Qual'e' il limite di giorni massimo? \n");
    scanf("%d", &giorni);

}

int calculations(){
    float vettore[giorni];

    vettore[0]=1;

    for (int i=1; i<=giorni; ++i){

        int a=vettore[i-1];
        vettore[i]=a*R;
        printf("Giorno: %d\tcontagiati: %.2f\n", i, vettore[i]);

        if (vettore[i]>=N){
            return i;
        }
    }
}




