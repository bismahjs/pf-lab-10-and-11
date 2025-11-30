#include <stdio.h>

int linear(int a[], int n, int target, int i) {
    if (i == n) return -1;
    if (a[i] == target) return i;
    return linear(a, n, target, i+1);
}

int main() {
    int a[5] = {3, 8, 1, 9, 5};
    int target;
    scanf("%d", &target);
    printf("%d", linear(a, 5, target, 0));
}

