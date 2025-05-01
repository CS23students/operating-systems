#include <stdio.h>

struct Record {
    int id;
    char name[20];
};

int main() {
    struct Record r;
    FILE *fp = fopen("sequential.txt", "w");

    int n;
    printf("Enter number of records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter ID and Name: ");
        scanf("%d %s", &r.id, r.name);
        fwrite(&r, sizeof(r), 1, fp);
    }

    fclose(fp);

    // Read and display
    fp = fopen("sequential.txt", "r");
    printf("\nStored Records:\n");
    while (fread(&r, sizeof(r), 1, fp))
        printf("ID: %d, Name: %s\n", r.id, r.name);

    fclose(fp);
    return 0;
}

// Enter number of records: 2
// Enter ID and Name: 101 Alice
// Enter ID and Name: 102 Bob

// Stored Records:
// ID: 101, Name: Alice
// ID: 102, Name: Bob


