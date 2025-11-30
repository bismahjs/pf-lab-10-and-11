#include <stdio.h>
#include <ctype.h>

int countVowels(char *s, int i) {
    if (s[i] == '\0') return 0;
    char c = tolower(s[i]);
    return ((c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ? 1 : 0)
           + countVowels(s, i+1);
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    printf("%d", countVowels(s, 0));
}

