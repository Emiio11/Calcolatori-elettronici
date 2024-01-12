#include <stdio.h>
#define LINE_LENGTH 80
void wrapLines(FILE *input, FILE *output, int maxColumn) {
    int c, column = 0;
    while ((c = fgetc(input)) != EOF) {
        if (column >= maxColumn) {
            if (c != ' ' && c != '\t') {
                fputc('\n', output);
                column = 0;
            }
        }
        fputc(c, output);
        if (c == '\n') {
            column = 0;
        } else {
            column++;
        }
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }
    char outputFileName[256];
    snprintf(outputFileName, sizeof(outputFileName), "wrapped_%s", argv[1]);
    FILE *output = fopen(outputFileName, "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }
    wrapLines(input, output, LINE_LENGTH);
    fclose(input);
    fclose(output);
    printf("Line wrapping completed successfully. Output file: %s\n", outputFileName);
    return 0;
}
