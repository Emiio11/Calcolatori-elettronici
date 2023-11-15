#include <stdio.h>
int main() {
    int N;
    printf("Inserisci il numero di bit: ");
    scanf("%d", &N);
    int decimalNumber;
    printf("Inserisci un numero decimale: ");
    scanf("%d", &decimalNumber);
    // Calcolare il valore massimo rappresentabile con N bit
    int maxRepresentableValue = (1 << N) - 1;
    // Controllare se il numero decimale è fuori dal range rappresentabile
    if (decimalNumber > maxRepresentableValue) {
        printf("Errore: Il numero decimale è troppo grande per essere rappresentato su %d bit.\n", N);
        return 1; // Uscita con errore
    }
    // Allocazione di un array per memorizzare la rappresentazione binaria
    int binary[N];
    // Inizializza l'array binario con zeri
    for (int i = 0; i < N; i++) {
        binary[i] = 0;
    }
    // Convertire il numero decimale in binario
    int index = N - 1; // Inizia dall'ultimo bit (il più significativo)
    while (decimalNumber > 0) {
        binary[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index--;
    }
    // Stampare la rappresentazione binaria
    printf("Rappresentazione binaria su %d bit: ", N);
    for (int i = 0; i < N; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");
    return 0; // Uscita senza errore
}