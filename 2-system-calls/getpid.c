#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Current Process ID: %d\n", getpid());
    return 0;
}
