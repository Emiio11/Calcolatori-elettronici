#include <stdio.h>
int main() {
    int numero;
    int massimo;
    printf("inserisci la dimensione dell'insieme:");
    scanf("%d", &numero);
    int insieme[numero];
    for(int i = 0; i < numero; i++) {
        int x;
        printf("numero %d\n", i + 1);
        scanf("%d", &x);
        insieme[i] = x;
    }
    int minimo;
    for(int i = 0; i < numero; i++) {
        if(minimo > insieme[i]){
            minimo = insieme[i];
        }
    }
    for(int i = 0; i < numero; i++) {
        if(massimo<insieme[i]){
            massimo = insieme[i];
        }
    }
    printf("numero piu piccolo: %d\n",minimo);
    printf("numero piu grande: %d\n",massimo);
    return 0;
}