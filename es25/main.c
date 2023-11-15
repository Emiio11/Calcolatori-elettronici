#include <stdio.h>
#include <string.h>

int iniziali(char str1[] ,char str2[]){
    int c=0;
    for (int i = 0; i<strlen(str1); i++) {
            if (str1[i] == str2[i]) {
                c++;
        }
    }
    return c;
}


int main() {
    printf("inserire dimensione prima stringa:\n");
    int dim=0;
    int dim2=0;
    scanf("%d", &dim);
    char str1[dim];
    scanf("%s", str1);
    printf("inserire dimensione seconda stringa:\n");
    scanf("%d", &dim2);
    char str2[dim2];
    scanf("%s", str2);
    printf("caratteri iniziali identici:");
    printf("%d\n", iniziali(str1, str2));

    return 0;
}
