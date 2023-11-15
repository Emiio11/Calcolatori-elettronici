#include<stdio.h>
int calcolaMCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// Funzione per calcolare il minimo comune multiplo (LCM)
int calcolaLCM(int a, int b) {
    int mcd = calcolaMCD(a, b);
    return (a * b) / mcd;
}
int main() {
    int num1, num2;
    printf("Inserisci il primo numero intero positivo: ");
    scanf("%d", &num1);
    if (num1 < 1) {
        printf("Inserisci un numero intero positivo valido.\n");
        return 1;  // Termina il programma con un codice di errore
    }
    printf("Inserisci il secondo numero intero positivo: ");
    scanf("%d", &num2);
    if (num2 < 1) {
        printf("Inserisci un numero intero positivo valido.\n");
        return 1;  // Termina il programma con un codice di errore
    }
    int lcm = calcolaLCM(num1, num2);
    printf("Il LCM di %d e %d e: %d\n", num1, num2, lcm);
    return 0;
}