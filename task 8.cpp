#include <stdio.h>

#define FACTOR 0.001

float convert(float m) {
    static int calls = 0;
    calls++;
    printf("Function called %d times\n", calls);
    return m * FACTOR;
}

int main() {
    float m;
    scanf("%f", &m);
    printf("%.3f\n", convert(m));
    scanf("%f", &m);
    printf("%.3f\n", convert(m));
}

