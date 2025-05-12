#include <stdio.h>
#include <string.h>

struct File {
    char name[20];
};

int main() {
    struct File dir[10];
    int n = 0, i;
    char fname[20];
    int choice, found;

    while (1) {
        printf("\n1. Create File\n2. Delete File\n3. Display Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fname);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(dir[i].name, fname) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (found)
                    printf("File already exists!\n");
                else {
                    strcpy(dir[n].name, fname);
                    n++;
                    printf("File created successfully.\n");
                }
                break;

            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", fname);
                found = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(dir[i].name, fname) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("File not found!\n");
                else {
                    for (int j = i; j < n - 1; j++) {
                        strcpy(dir[j].name, dir[j + 1].name);
                    }
                    n--;
                    printf("File deleted successfully.\n");
                }
                break;

            case 3:
                if (n == 0)
                    printf("Directory is empty.\n");
                else {
                    printf("Files:\n");
                    for (i = 0; i < n; i++)
                        printf("%s\n", dir[i].name);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}



// 1. Create File
// 2. Delete File
// 3. Display Files
// 4. Exit
// Enter choice: 1
// Enter file name: file1
// File created successfully.

// Enter choice: 1
// Enter file name: file2
// File created successfully.

// Enter choice: 3
// Files:
// file1
// file2

// Enter choice: 2
// Enter file name to delete: file1
// File deleted successfully.

// Enter choice: 3
// Files:
// file2
