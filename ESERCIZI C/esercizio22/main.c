#include <stdio.h>

int main() {
    printf("inserire dimensione stringa:\n");
    int x;
    scanf("%d", &x); // NOLINT(*-err34-c)
    char s[x];
    printf("inserire stringa\n");
    scanf("%s", s);
    for(int i = 0; i < x;i++){
        if(s[i]!=s[x-i-1]){
            printf("stringa non palindroma\n");
            return 0;
        }
    }
    printf("stringa palindroma\n");
    return 0;
}
