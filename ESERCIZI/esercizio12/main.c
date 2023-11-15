#include <stdio.h>
int main() {
    int k;
    printf("inserisci dimensione della sequenza: ");
    scanf("%d", &k);
    int sequenza[k];
    int crescente =1;
    int decrescente =1;
    for(int i = 0; i < k; i++){
        int x;
        printf("numero:%d\n ",i+1);
        scanf("%d",&x);
        sequenza[i] = x;
        if(i>0){
            if(sequenza[i]>sequenza[i-1]){
                decrescente = 0;
            }else if(sequenza[i]<sequenza[i-1]){
                crescente = 0;
            }
        }
    }
    int positivi = 0;
    int negativi = 0;
    int nulli = 0;
    for(int i = 0; i < k; i++){
        if(sequenza[i]== 0){
            nulli++;
        }else if(sequenza[i]<0){
            negativi++;
        }else if(sequenza[i]>0){
            positivi++;
        }
    }
    int pari = 0;
    int dispari = 0;
    for(int i = 0; i < k; i++){
        if(sequenza[i]%2 == 0){

            pari++;
        }else{
            dispari++;
        }
    }
    if(crescente && decrescente){
        printf("la sequenza non e ne crescente ne decrescente\n");
    }else if(crescente){
        printf("la sequenza e crescente\n");
    }else if(decrescente){
        printf("la sequenza e decrescente\n");
    }else{
        printf("la sequenza non e ne decrescente ne decrescente\n");
    }
    printf("numeri pari: %d\n", pari);
    printf("numeri dispari: %d\n",dispari);
    printf("numeri positivi: %d\n",positivi);
    printf("numeri negativi: %d\n",negativi);
    return 0;
}