#include <stdio.h>

#define MAX 50      // max students we can store
#define SUB 3       // number of subjects

// one student record
struct Student {
    int roll;
    char name[30];       // use one-word names like Raj, Neha
    float marks[SUB];    // 3 marks
    float total;
    float avg;
};

int main() {
    struct Student s[MAX];   // array to store students
    int n = 0;               // how many students stored
    int choice;

    while (1) {
        printf("\n=== Student Database ===\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n >= MAX) {
                printf("Database full.\n");
                continue;
            }

            // take input
            printf("Roll: ");
            scanf("%d", &s[n].roll);

            printf("Name (one word): ");
            scanf("%29s", s[n].name);

            s[n].total = 0;
            for (int i = 0; i < SUB; i++) {
                printf("Marks %d: ", i + 1);
                scanf("%f", &s[n].marks[i]);
                s[n].total += s[n].marks[i];
            }
            s[n].avg = s[n].total / SUB;

            n++; // one student added
            printf("Saved.\n");
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("No students yet.\n");
            } else {
                printf("\n-- All Students --\n");
                for (int i = 0; i < n; i++) {
                    printf("Roll: %d | Name: %s | Marks: %.0f %.0f %.0f | Total: %.0f | Avg: %.2f\n",
                           s[i].roll, s[i].name,
                           s[i].marks[0], s[i].marks[1], s[i].marks[2],
                           s[i].total, s[i].avg);
                }
            }
        }

        else if (choice == 0) {
            printf("Bye!\n");
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
