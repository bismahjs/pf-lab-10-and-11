#include <stdio.h>
#include <time.h>

int main() {
    FILE *f = fopen("log.txt", "a");
    if (!f) return 0;

    time_t now = time(NULL);
    fprintf(f, "Program ran at: %s", ctime(&now));

    fclose(f);
    return 0;
}

