#include <stdio.h>
#include <string.h>

int main() {
    printf("inserire dimensione prima stringa:\n");
    int x;
    scanf("%d", &x); // NOLINT(*-err34-c)
    char s[x];
    printf("inserire stringa\n");
    scanf("%s", s);
    printf("inserire dimensione seconda stringa:\n");
    int t;
    scanf("%d", &t); // NOLINT(*-err34-c)
    char r[t];
    printf("inserire stringa\n");
    scanf("%s", r);

    if (strstr(s, r) != NULL) {
        printf("La seconda stringa è una sottostringa della prima.\n");
    } else if (strstr(s, r) != NULL) {
        printf("La prima stringa è una sottostringa della seconda.\n");
    } else {
        printf("Nessuna delle stringhe è una sottostringa dell'altra.\n");
    }

    return 0;
}
