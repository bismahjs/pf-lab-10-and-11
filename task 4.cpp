#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define STRLEN(s) (sizeof(s)/sizeof(s[0]))

struct Movie {
    char title[100];
    char genre[40];
    char director[60];
    int year;
    float rating;
};

void readLine(char *buf, int size) {
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    size_t len = strlen(buf);
    if (len && buf[len - 1] == '\n') buf[len - 1] = '\0';
}

void toLowerCase(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

int main() {
    struct Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n1. Add Movie\n2. Search by Genre\n3. Display All Movies\n4. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) ;
            continue;
        }
        while (getchar() != '\n') ;

        if (choice == 1) {
            if (count >= MAX_MOVIES) {
                printf("Movie list is full.\n");
                continue;
            }
            printf("Enter title: ");
            readLine(movies[count].title, STRLEN(movies[count].title));
            printf("Enter genre: ");
            readLine(movies[count].genre, STRLEN(movies[count].genre));
            printf("Enter director: ");
            readLine(movies[count].director, STRLEN(movies[count].director));
            printf("Enter release year: ");
            if (scanf("%d", &movies[count].year) != 1) {
                movies[count].year = 0;
            }
            while (getchar() != '\n') ;
            printf("Enter rating (0.0 - 10.0): ");
            if (scanf("%f", &movies[count].rating) != 1) {
                movies[count].rating = 0.0f;
            }
            while (getchar() != '\n') ;
            count++;
            printf("Movie added successfully.\n");
        }

        else if (choice == 2) {
            char g[40];
            int found = 0;
            printf("Enter genre to search: ");
            readLine(g, sizeof(g));
            if (g[0] == '\0') {
                printf("No genre entered.\n");
                continue;
            }
            char search[40];
            strncpy(search, g, sizeof(search) - 1);
            search[sizeof(search) - 1] = '\0';
            toLowerCase(search);

            for (int i = 0; i < count; i++) {
                char movieGenre[40];
                strncpy(movieGenre, movies[i].genre, sizeof(movieGenre) - 1);
                movieGenre[sizeof(movieGenre) - 1] = '\0';
                toLowerCase(movieGenre);
                if (strcmp(movieGenre, search) == 0) {
                    printf("\nTitle: %s\n", movies[i].title);
                    printf("Genre: %s\n", movies[i].genre);
                    printf("Director: %s\n", movies[i].director);
                    printf("Year: %d\n", movies[i].year);
                    printf("Rating: %.1f\n", movies[i].rating);
                    found = 1;
                }
            }
            if (!found) printf("No movies found in genre '%s'.\n", g);
        }

        else if (choice == 3) {
            if (count == 0) {
                printf("No movies to display.\n");
                continue;
            }
            for (int i = 0; i < count; i++) {
                printf("\nMovie %d\n", i + 1);
                printf("Title: %s\n", movies[i].title);
                printf("Genre: %s\n", movies[i].genre);
                printf("Director: %s\n", movies[i].director);
                printf("Year: %d\n", movies[i].year);
                printf("Rating: %.1f\n", movies[i].rating);
            }
        }

        else if (choice == 4) {
            break;
        }

        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


