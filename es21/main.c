#include <stdio.h>

int main() {
    int n,t,c;
    printf("inserire dimensione primo vettore:\n");
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("inserire dimensione secondo vettore:\n");
    scanf("%d",&t);
    int b[t];
    for(int i = 0; i < t; i++) {
        scanf("%d", &b[i]);
    }

    if(n>=t){
        c=n;
    }
    else{
        c=t;
    }
    int s[c];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < t; j++) {
            if(a[i] == b[j]) {
                s[i]=a[i];
            }
        }
    }
    for(int i = 0; i < c; i++) {
        if(s[i] == s[i+1]) {
            printf("%d\n", s[i]);
            i++;
        }
    }
    return 0;
}
