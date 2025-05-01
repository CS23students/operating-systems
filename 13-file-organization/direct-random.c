#include <stdio.h>

struct Record {
    int id;
    char name[20];
};

int main() {
    struct Record r = {0, ""};
    FILE *fp = fopen("direct.dat", "w+b");
    for (int i = 0; i < 10; i++)
        fwrite(&r, sizeof(r), 1, fp);

    int n, pos;
    printf("Enter number of records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter ID and Name: ");
        scanf("%d %s", &r.id, r.name);
        pos = r.id % 10;
        fseek(fp, pos * sizeof(r), SEEK_SET);
        fwrite(&r, sizeof(r), 1, fp);
    }

    // Read a record
    printf("\nEnter ID to search: ");
    scanf("%d", &pos);
    fseek(fp, (pos % 10) * sizeof(r), SEEK_SET);
    fread(&r, sizeof(r), 1, fp);
    printf("ID: %d, Name: %s\n", r.id, r.name);

    fclose(fp);
    return 0;
}


// Enter number of records: 2
// Enter ID and Name: 101 Alice
// Enter ID and Name: 105 Bob

// Enter ID to search: 105
// ID: 105, Name: Bob
