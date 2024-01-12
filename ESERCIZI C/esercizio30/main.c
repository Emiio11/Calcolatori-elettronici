#include <stdio.h>
#include <stdlib.h>
#define TAB 8

void entab(FILE *file, FILE *output){
    int c, spaceCount = 0, tabCount = 0;
    while((c = fgetc(file)) !=EOF){
        if(c == ' '){
            spaceCount++;
        }else{
            while(spaceCount>=TAB){
                tabCount++;
                spaceCount -= TAB;
            }
            while(tabCount>0){
                fputc('\t', output);
                tabCount--;
            }
            while(spaceCount>0){
                fputc(' ',output);
                spaceCount--;
            }
            fputc(c,output);
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2){
        return EXIT_FAILURE;
    }
    FILE *file = fopen(argv[1], "r");
    if(file==NULL){
        return EXIT_FAILURE;
    }
    char outputFile[256];
    FILE *output = fopen(outputFile,"w");
    if(output==NULL){
        return EXIT_FAILURE;
    }
    entab(file,output);
    fclose(file);
    fclose(output);
    printf("conversion completed. Output file: %s\n",outputFile);
    return 0;
}
