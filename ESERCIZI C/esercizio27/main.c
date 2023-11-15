#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 1000
#define MAX_CODE_LENGTH 10
typedef struct {
    char code[MAX_CODE_LENGTH];
    int in_time;
    int out_time;
} Employee;
int main() {
    char file_name[100]; // Supponiamo un nome di file di massimo 100 caratteri.
    char target_code[MAX_CODE_LENGTH];
    int count_employees = 0;
    Employee employees[MAX_EMPLOYEES];
    printf("Inserisci il nome del file dei passaggi: ");
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }
    printf("Hai specificato un codice dipendente? (Y/N): ");
    char answer[2];
    scanf("%1s", answer);
    if (answer[0] == 'Y' || answer[0] == 'y') {
        printf("Inserisci il codice dipendente: ");
        scanf("%s", target_code);
    }
    while (!feof(file) && count_employees < MAX_EMPLOYEES) {
        char code[MAX_CODE_LENGTH];
        int hour, minute;
        if (fscanf(file, "%d %d %s", &hour, &minute, code) == 3) {
            if (answer[0] == 'N' || (answer[0] == 'Y' && strcmp(code, target_code) == 0)) {
                int i;
                int found = 0;
                for (i = 0; i < count_employees; i++) {
                    if (strcmp(employees[i].code, code) == 0) {
                        employees[i].out_time = hour * 60 + minute;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(employees[count_employees].code, code);
                    employees[count_employees].in_time = hour * 60 + minute;
                    employees[count_employees].out_time = hour * 60 + minute;
                    count_employees++;
                }
            }
        }
    }
    fclose(file);
    if (answer[0] == 'N' || answer[0] == 'n') {
        printf("Ci sono %d dipendenti diversi\n", count_employees);
    } else {
        for (int i = 0; i < count_employees; i++) {
            if (strcmp(employees[i].code, target_code) == 0) {
                int total_minutes = employees[i].out_time - employees[i].in_time;
                printf("Il dipendente %s ha lavorato per %d minuti\n", target_code, total_minutes);
                break;
            }
        }
    }
    return 0;
}