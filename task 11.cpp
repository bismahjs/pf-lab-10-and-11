#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20] = {"apple", "banana", "mango", "grape", "peach"};
    char search[20];
    int found = 0;

    printf("Enter word to search: ");
    scanf("%19s", search);

    for (int i = 0; i < 5; i++) {
        if (strcmp(words[i], search) == 0) {
            found = 1;
            break;
        }
    }

    if (found) printf("Found\n");
    else printf("Not Found\n");

    return 0;
}

