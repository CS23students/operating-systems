#include <stdio.h>
#include <string.h>

struct File {
    char name[20];
};

struct User {
    char uname[20];
    struct File files[10];
    int fileCount;
};

int main() {
    struct User users[5];
    int userCount = 0;
    int choice, i, j;
    char uname[20], fname[20];

    while (1) {
        printf("\n1. Create User\n2. Create File\n3. Display User Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", uname);
                strcpy(users[userCount].uname, uname);
                users[userCount].fileCount = 0;
                userCount++;
                printf("User created.\n");
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", uname);
                for (i = 0; i < userCount; i++) {
                    if (strcmp(users[i].uname, uname) == 0) {
                        printf("Enter file name: ");
                        scanf("%s", fname);
                        strcpy(users[i].files[users[i].fileCount].name, fname);
                        users[i].fileCount++;
                        printf("File created for %s.\n", uname);
                        break;
                    }
                }
                if (i == userCount)
                    printf("User not found.\n");
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", uname);
                for (i = 0; i < userCount; i++) {
                    if (strcmp(users[i].uname, uname) == 0) {
                        printf("Files of %s:\n", uname);
                        for (j = 0; j < users[i].fileCount; j++)
                            printf("%s\n", users[i].files[j].name);
                        break;
                    }
                }
                if (i == userCount)
                    printf("User not found.\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}


// 1. Create User
// 2. Create File
// 3. Display User Files
// 4. Exit
// Enter choice: 1
// Enter username: alice
// User created.

// Enter choice: 2
// Enter username: alice
// Enter file name: notes.txt
// File created for alice.

// Enter choice: 3
// Enter username: alice
// Files of alice:
// notes.txt
