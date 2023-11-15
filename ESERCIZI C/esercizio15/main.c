#include <stdio.h>4
int main() {
    int n;
    printf("Inserisci il numero di righe per il triangolo di Floyd: ");
    scanf("%d", &n);
    int numero = 1;
    int riga, colonna;
    printf("Triangolo di Floyd:\n");
    for (riga = 1; riga <= n; riga++) {
        for (colonna = 1; colonna <= riga; colonna++) {
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }
    return 0;
}
