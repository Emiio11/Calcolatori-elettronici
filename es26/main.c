#include <stdio.h>
#include <string.h>

char* upper(char str1[] ) {
    for( int i=0; i<strlen(str1); i++){
        int m=(int)str1[i]-32;
        str1[i]=(char)m;
    }
    return str1;
}


int main() {
    printf("inserire dimensione stringa:\n");
    int dim=0;
    scanf("%d", &dim);
    char str1[dim];
    scanf("%s", str1);
    printf(upper(str1));
    return 0;
}
