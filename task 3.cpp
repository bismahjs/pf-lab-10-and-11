#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int seats;
};

int main() {
    struct Flight f;
    int choice;

    printf("Enter flight number: ");
    scanf("%d", &f.flightNumber);
    printf("Enter departure city: ");
    scanf("%s", f.departure);
    printf("Enter destination city: ");
    scanf("%s", f.destination);
    printf("Enter date: ");
    scanf("%s", f.date);
    printf("Enter available seats: ");
    scanf("%d", &f.seats);

    while (1) {
        printf("\n1. Book a seat\n2. Display flight info\n3. Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (f.seats > 0) {
                f.seats--;
                printf("Seat booked. Seats left: %d\n", f.seats);
            } else {
                printf("No seats available.\n");
            }
        } 
        else if (choice == 2) {
            printf("\nFlight Number: %d\n", f.flightNumber);
            printf("Departure: %s\n", f.departure);
            printf("Destination: %s\n", f.destination);
            printf("Date: %s\n", f.date);
            printf("Available Seats: %d\n", f.seats);
        } 
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}

