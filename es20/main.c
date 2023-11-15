#include <stdio.h>

int main() {
    int n;
    printf("inserire il numero di valori:\n");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        next:
        if(a[i]== a[i+1]){
            i++;
            goto next;
        }
        printf("%d", a[i]);
        printf(":");
        for (int j = 0; j < n; j++) {
            if(a[i] == a[j]) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
