#include <stdio.h>
#define N 8
int main() {
    char binario[N + 1];
    char opposto[N + 1];
    printf("Inserisci un numero binario a %d bit (inizia dal bit piu significativo): ", N);
    scanf("%s", binario);
    for (int i = 0; i < N; i++) {
        if (binario[i] != '0' && binario[i] != '1') {
            printf("Il numero binario inserito non e valido.\n");
            return 1;
        }
    }
    int carry = 1;
    for (int i = N - 1; i >= 0; i--) {
        if (binario[i] == '0' && carry == 1) {
            opposto[i] = '1';
            carry = 0;
        } else if (binario[i] == '1' && carry == 1) {
            opposto[i] = '0';
        } else {
            opposto[i] = binario[i];
        }
    }
    opposto[N] = '\0';
    printf("L'opposto del numero binario inserito e: %s\n", opposto);
    return 0;
}