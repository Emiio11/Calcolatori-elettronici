#include <stdio.h>
#include <string.h>
int main() {
    char inputString[1000];
    char resultString[1000];
    int i, j, k;
    // Input della stringa da tastiera
    printf("Inserisci una stringa: ");
    fgets(inputString, sizeof(inputString), stdin);
    // Rimuovi il carattere newline dalla stringa di input
    size_t len = strlen(inputString);
    if (len > 0 && inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
    }
    // Inizializza la stringa risultante con la stringa di input
    strcpy(resultString, inputString);
    // Rimuovi i caratteri ripetuti dalla stringa risultante
    for (i = 0; i < strlen(resultString); ++i) {
        for (j = i + 1; resultString[j] != '\0'; ++j) {
            if (resultString[i] == resultString[j]) {
                // Rimuovi il carattere ripetuto
                for (k = j; resultString[k] != '\0'; ++k) {
                    resultString[k] = resultString[k + 1];
                }
                --j;  // Controlla di nuovo lo stesso indice dopo la rimozione
            }
        }
    }
    // Stampa la stringa risultante
    printf("Stringa risultante: %s\n", resultString);
    return 0;
}