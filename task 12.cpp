#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *f = fopen("data.txt", "r");
    if (!f) {
        printf("Cannot open file data.txt\n");
        return 1;
    }

    int ch;
    long chars = 0;
    long words = 0;
    long lines = 0;
    int inWord = 0;
    int last = 0;

    while ((ch = fgetc(f)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace((unsigned char)ch)) inWord = 0;
        else if (!inWord) {
            inWord = 1;
            words++;
        }
        last = ch;
    }

    if (chars > 0 && last != '\n') lines++;

    fclose(f);

    printf("Characters: %ld\nWords: %ld\nLines: %ld\n", chars, words, lines);
    return 0;
}

