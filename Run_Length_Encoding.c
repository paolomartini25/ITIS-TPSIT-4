#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void decoding();
void endecoding();

int main(){

    int coding = 0;
    char carattere = 0;
    int num=0;
    char var[100];
    char dec[100];

    printf("Vuoi fare decoding o endecoding?\nPremi 0 per fare decoding\tPremi 1 perfare endecoding\n");
    scanf("%d", coding);

    switch (coding)
    {
    case 0:
//-----------------------------------------------------------------------------------------------
        
        printf("Inserisci la stringa senza spazi.");
        gets(var);

//-----------------------------------------------------------------------------------------------
        break;
    
    default:
//-----------------------------------------------------------------------------------------------
    
    
        printf("Inserisci la stringa con sole lettere, senza spazi.");
        gets(var);
    int a = -1;
    char b;
    do
    {
        a++;
        b=var[a];
    } while (b!="/0");
    

    for(int i = 0; i>a; i++){
        if (carattere == var[i]){
            for(int j = 0; i>a && carattere!=var[i]; j++){
                num++;
                carattere = var[i];
            }
            dec[i]=num;
        }
        else{
            dec[i]=var[i];
        }
        var[i]=carattere;
    }
    //----------------------------------------------------------------------------------------
        break;
    }
    printf("%s", dec);
}

