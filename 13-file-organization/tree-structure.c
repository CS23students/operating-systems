#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileNode {
    char name[20];
    int isDir;
    struct FileNode *child[10];
    int childCount;
};

struct FileNode* createNode(char name[], int isDir) {
    struct FileNode* newNode = (struct FileNode*)malloc(sizeof(struct FileNode));
    strcpy(newNode->name, name);
    newNode->isDir = isDir;
    newNode->childCount = 0;
    return newNode;
}

void addFile(struct FileNode* parent, char name[], int isDir) {
    parent->child[parent->childCount++] = createNode(name, isDir);
    printf("%s added under %s\n", name, parent->name);
}

void display(struct FileNode* root, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("|-- %s\n", root->name);
    for (int i = 0; i < root->childCount; i++) {
        display(root->child[i], depth + 1);
    }
}

int main() {
    struct FileNode* root = createNode("root", 1);

    addFile(root, "bin", 1);
    addFile(root, "file1.txt", 0);

    addFile(root->child[0], "ls", 0);
    addFile(root->child[0], "cat", 0);

    addFile(root, "home", 1);
    addFile(root->child[2], "user", 1);
    addFile(root->child[2]->child[0], "notes.txt", 0);

    printf("\nDirectory Structure:\n");
    display(root, 0);

    return 0;
}



// SAMPLE:
// bin added under root
// file1.txt added under root
// ls added under bin
// cat added under bin
// home added under root
// user added under home
// notes.txt added under user

// Directory Structure:
// |-- root
//   |-- bin
//     |-- ls
//     |-- cat
//   |-- file1.txt
//   |-- home
//     |-- user
//       |-- notes.txt
