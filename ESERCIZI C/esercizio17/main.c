#include <stdio.h>

int main() {
    int N;
    printf("Inserisci il numero di bit (N): ");
    scanf("%d", &N);
    int a[N], b[N], sum[N + 1]; // Un bit in più per gestire l'overflow
    printf("Inserisci il primo numero binario (bit per bit, partendo dal LSB):\n");
    for (int i = 0; i < N; i++) {
        scanf("%1d", &a[i]);
    }
    printf("Inserisci il secondo numero binario (bit per bit, partendo dal LSB):\n");
    for (int i = 0; i < N; i++) {
        scanf("%1d", &b[i]);
    }
    int carry = 0; // Inizializziamo il carry a 0
    int overflow = 0; // Inizializziamo la variabile di overflow a 0
    for (int i = 0; i < N; i++) {
        sum[i] = a[i] ^ b[i] ^ carry; // XOR tra i bit e il carry
        carry = (a[i] & b[i]) | (carry & (a[i] ^ b[i])); // Calcoliamo il carry
        if (i == N - 1 && carry == 1) {
            overflow = 1; // Se l'ultimo bit causa un carry, c'è overflow
        }
    }
    if (overflow) {
        printf("\nOverflow!");
    } else {
        printf("\nNessun overflow.");
    }
    printf("\nRisultato della somma binaria: ");
    for (int i = N - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }
    printf("\nrisultato della somma in decimale: ");
    int decimalSum = 0;
    int base = 1;
    // Calcola il risultato decimale
    for (int i = N - 1; i >= 0; i--) {
        decimalSum += sum[i] * base;
        base *= 2;
    }
    printf("%d", decimalSum);
    return 0;
}