#include <stdio.h>
#include <string.h>
struct Salary {
    float basic;
    float bonus;
    float deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary sal;
};

float netSalary(struct Employee e) {
    return e.sal.basic + e.sal.bonus - e.sal.deduction;
}

void display(struct Employee e) {
    printf("ID: %d\nName: %s\nNet Salary: %.2f\n",
           e.id, e.name, netSalary(e));
}

int main() {
    struct Employee e;
    printf("ID: ");
    scanf("%d", &e.id);
    getchar();
    printf("Name: ");
    fgets(e.name, 50, stdin);
    e.name[strcspn(e.name, "\n")] = 0;
    printf("Basic salary: ");
    scanf("%f", &e.sal.basic);
    printf("Bonus: ");
    scanf("%f", &e.sal.bonus);
    printf("Deduction: ");
    scanf("%f", &e.sal.deduction);

    display(e);
}

