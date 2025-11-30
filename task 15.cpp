#include <stdio.h>
#include <stdlib.h>

int main() {
    char file1[260], file2[260], outname[260];
    FILE *f1 = NULL, *f2 = NULL, *out = NULL;
    unsigned char buffer[4096];
    size_t n;

    printf("Enter first file name: ");
    if (scanf("%259s", file1) != 1) return 1;
    printf("Enter second file name: ");
    if (scanf("%259s", file2) != 1) return 1;
    printf("Enter output file name: ");
    if (scanf("%259s", outname) != 1) return 1;

    f1 = fopen(file1, "rb");
    if (!f1) {
        printf("Cannot open %s\n", file1);
        return 1;
    }

    f2 = fopen(file2, "rb");
    if (!f2) {
        printf("Cannot open %s\n", file2);
        fclose(f1);
        return 1;
    }

    out = fopen(outname, "wb");
    if (!out) {
        printf("Cannot create %s\n", outname);
        fclose(f1);
        fclose(f2);
        return 1;
    }

    while ((n = fread(buffer, 1, sizeof(buffer), f1)) > 0) {
        if (fwrite(buffer, 1, n, out) != n) {
            printf("Write error\n");
            fclose(f1); fclose(f2); fclose(out);
            return 1;
        }
    }

    while ((n = fread(buffer, 1, sizeof(buffer), f2)) > 0) {
        if (fwrite(buffer, 1, n, out) != n) {
            printf("Write error\n");
            fclose(f1); fclose(f2); fclose(out);
            return 1;
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(out);

    printf("Files merged into %s successfully.\n", outname);
    return 0;
}

