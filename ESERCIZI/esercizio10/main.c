#include <stdio.h>
int main() {
    float numero = 0;
    int somma = 0;
    int conteggio = 0;
    while(1){
        printf("inserisci un numero (0 per terminare):\n");
        scanf("%f", &numero);
        if(numero == 0){
            break;
        }
        somma += numero;
        conteggio++;
    }
    if(conteggio>0){
        float media = (float)somma/conteggio;
        printf("media: %.2f\n", media);
    }else{
        printf("nessun numero inserito, impossibile calcolare la media.\n");
    }
    return 0;
}
