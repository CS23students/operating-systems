#include <stdio.h>
#include <stdlib.h>

struct Record {
    int id;
    char name[20];
};

int main() {
    struct Record r;
    FILE *data = fopen("data.txt", "w");
    FILE *indexFile = fopen("index.txt", "w");

    int n;
    printf("Enter number of records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter ID and Name: ");
        scanf("%d %s", &r.id, r.name);
        fprintf(indexFile, "%d %ld\n", r.id, ftell(data));
        fwrite(&r, sizeof(r), 1, data);
    }

    fclose(data);
    fclose(indexFile);

    printf("Records and index created successfully.\n");
    return 0;
}


// Enter number of records: 2
// Enter ID and Name: 201 Alice
// Enter ID and Name: 202 Bob

// Records and index created successfully.

// 📁 index.txt Content (Example):
// Copy
// Edit
// 201 0
// 202 28
// 📁 data.txt Content (Binary):
// Contains raw binary data of records written in sequence.
