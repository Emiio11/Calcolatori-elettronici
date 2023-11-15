#include <stdio.h>
// Funzione per calcolare il MCD utilizzando l'algoritmo di Euclide
int calcolaMCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    printf("Inserisci il primo numero intero positivo: ");
    scanf("%d", &num1);
    if (num1 < 1) {
        printf("Inserisci un numero intero positivo valido.\n");
        return 1;
    }
    printf("Inserisci il secondo numero intero positivo: ");
    scanf("%d", &num2);
    if (num2 < 1) {
        printf("Inserisci un numero intero positivo valido.\n");
        return 1;
    }
    int mcd = calcolaMCD(num1, num2);
    printf("Il MCD di %d e %d e: %d\n", num1, num2, mcd);
    return 0;
}