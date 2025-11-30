#include <stdio.h>
#include <string.h>

int isPal(char s[]) {
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main() {
    char words[5][20];
    for (int i = 0; i < 5; i++) {
        fgets(words[i], 20, stdin);
        words[i][strcspn(words[i], "\n")] = 0;
    }

    for (int i = 0; i < 5; i++) {
        if (isPal(words[i])) printf("Palindrome\n");
        else printf("Not Palindrome\n");
    }
}

