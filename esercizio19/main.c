#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int *vettore = NULL;  // Puntatore al vettore
    int dimensione = 0;   // Dimensione attuale del vettore
    int valore;
    char input[100];  // Buffer per l'input dell'utente

    // Chiedi all'utente di inserire i numeri positivi nel vettore
    while (true) {
        printf("Inserisci un numero positivo o invia una stringa vuota per terminare: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Errore di input
            printf("Errore di input. Inserire un numero positivo o una stringa vuota.\n");
            continue;
        }
        if (input[0] == '\n') {
            // L'utente ha inserito una stringa vuota, termina l'input.
            break;
        }

        if (sscanf(input, "%d", &valore) == 1 && valore > 0) {
            // Input valido: è un numero positivo
            dimensione++;
            vettore = (int *)realloc(vettore, dimensione * sizeof(int));
            if (vettore == NULL) {
                printf("Errore di allocazione della memoria.\n");
                return 1;
            }
            vettore[dimensione - 1] = valore;
        } else {
            printf("Valore non valido. Inserire un numero positivo.\n");
        }
    }

    // Chiedi all'utente di inserire il valore di riferimento
    printf("Inserisci il valore di riferimento: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Errore di input. Inserire un valore di riferimento valido.\n");
        free(vettore);
        return 1;
    }

    if (sscanf(input, "%d", &valore) == 1) {
        // Input valido: è un numero
        bool trovato = false;
        for (int i = 0; i < dimensione; i++) {
            if (vettore[i] == valore) {
                trovato = true;
                break;
            }
        }
        if (trovato) {
            printf("Il valore %d è contenuto nel vettore.\n", valore);
        } else {
            printf("Il valore %d non è contenuto nel vettore.\n", valore);
        }
    } else {
        printf("Valore di riferimento non valido. Inserire un numero.\n");
    }

    // Libera la memoria allocata per il vettore
    free(vettore);

    return 0;
}
