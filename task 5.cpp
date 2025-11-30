#include <stdio.h>
#include <string.h>

struct Player {
    char name[50];
    int age;
    char position[50];
};

struct Team {
    char name[50];
    char sport[50];
    struct Player players[50];
    int count;
};

void addPlayer(struct Team *t) {
    int i = t->count;
    printf("Player name: ");
    fgets(t->players[i].name, 50, stdin);
    t->players[i].name[strcspn(t->players[i].name, "\n")] = 0;

    printf("Age: ");
    scanf("%d", &t->players[i].age);
    getchar();

    printf("Position: ");
    fgets(t->players[i].position, 50, stdin);
    t->players[i].position[strcspn(t->players[i].position, "\n")] = 0;

    t->count++;
}

void searchPosition(struct Team t, char pos[]) {
    for (int i = 0; i < t.count; i++) {
        if (strcmp(t.players[i].position, pos) == 0) {
            printf("%s (%d)\n", t.players[i].name, t.players[i].age);
        }
    }
}

void displayTeam(struct Team t) {
    printf("Team: %s\nSport: %s\n", t.name, t.sport);
    for (int i = 0; i < t.count; i++) {
        printf("%s - %d - %s\n", t.players[i].name, t.players[i].age, t.players[i].position);
    }
}

int main() {
    struct Team t = {"Warriors", "Football", {}, 0};
    int choice;
    char pos[50];

    while (1) {
        printf("\n1 Add Player\n2 Search by position\n3 Display Team\n4 Exit\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) addPlayer(&t);
        else if (choice == 2) {
            printf("Enter position: ");
            fgets(pos, 50, stdin);
            pos[strcspn(pos, "\n")] = 0;
            searchPosition(t, pos);
        }
        else if (choice == 3) displayTeam(t);
        else break;
    }
}

