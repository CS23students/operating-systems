#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileNode {
    char name[20];
    int isDir;
    struct FileNode* child[10];
    int childCount;
};

struct FileNode* createNode(char name[], int isDir) {
    struct FileNode* node = (struct FileNode*)malloc(sizeof(struct FileNode));
    strcpy(node->name, name);
    node->isDir = isDir;
    node->childCount = 0;
    return node;
}

void add(struct FileNode* parent, struct FileNode* node) {
    parent->child[parent->childCount++] = node;
    printf("%s added under %s\n", node->name, parent->name);
}

void display(struct FileNode* node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("|-- %s\n", node->name);
    for (int i = 0; i < node->childCount; i++)
        display(node->child[i], depth + 1);
}

int main() {
    struct FileNode* root = createNode("root", 1);
    struct FileNode* shared = createNode("shared.txt", 0);

    struct FileNode* proj1 = createNode("project1", 1);
    struct FileNode* proj2 = createNode("project2", 1);

    add(root, proj1);
    add(root, proj2);

    add(proj1, shared);  // shared file in project1
    add(proj2, shared);  // same file in project2 (link)

    printf("\nAcyclic Graph Directory:\n");
    display(root, 0);

    return 0;
}



// SAMPLE :
// project1 added under root
// project2 added under root
// shared.txt added under project1
// shared.txt added under project2

// Acyclic Graph Directory:
// |-- root
//   |-- project1
//     |-- shared.txt
//   |-- project2
//     |-- shared.txt


// ⚠️ Note: This is just a simulation — in real systems, links are managed differently using file inodes or symbolic references, but this is good enough for demonstrating acyclic graphs.
