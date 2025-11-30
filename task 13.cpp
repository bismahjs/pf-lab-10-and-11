#include <stdio.h>

int main() {
    FILE *f = fopen("data.txt", "w");
    if (!f) return 0;
    fclose(f);

    f = fopen("data.txt", "r");
    int ch = fgetc(f);
    fclose(f);

    if (ch == EOF) printf("File is empty\n");
    else printf("File not empty\n");

    return 0;
}

