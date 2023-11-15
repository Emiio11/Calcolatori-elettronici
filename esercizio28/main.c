#include <stdio.h>
void swapChars(char *str, char c1, char c2) {
    while (*str != '\0') {
        if (*str == c1) {
            *str = c2;
        } else if (*str == c2) {
            *str = c1;
        }
        str++;
    }
}
int main() {
    char input_file_name[100];
    char output_file_name[100];
    char char1, char2;
    printf("Inserisci il nome del file di input: ");
    scanf("%s", input_file_name);
    printf("Inserisci il nome del file di output: ");
    scanf("%s", output_file_name);
    printf("Inserisci la stringa di 2 caratteri da scambiare: ");
    scanf(" %c %c", &char1, &char2);
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        perror("Errore nell'apertura del file di input");
        return 1;
    }
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        perror("Errore nell'apertura del file di output");
        fclose(input_file);
        return 2;
    }
    char line[1000];
    while (fgets(line, sizeof(line), input_file) != NULL) {
        swapChars(line, char1, char2);
        fputs(line, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    printf("Sostituzione completata con successo. Il risultato è stato salvato in %s.\n", output_file_name);
    return 0;
}