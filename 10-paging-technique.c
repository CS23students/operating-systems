#include <stdio.h>

int main() {
    int pageTable[20], nPages, nFrames, pageSize;
    int logicalAddress, pageNumber, offset, frameNumber, physicalAddress;

    // Input
    printf("Enter number of pages: ");
    scanf("%d", &nPages);
    
    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter page table values (Frame numbers):\n");
    for (int i = 0; i < nPages; i++) {
        printf("Page %d → Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Logical Address Input
    printf("\nEnter logical address (page number and offset):\n");
    printf("Page Number (0 to %d): ", nPages - 1);
    scanf("%d", &pageNumber);

    printf("Offset (0 to %d): ", pageSize - 1);
    scanf("%d", &offset);

    if (pageNumber >= nPages || offset >= pageSize) {
        printf("Invalid logical address.\n");
        return 1;
    }

    // Translate to physical address
    frameNumber = pageTable[pageNumber];
    physicalAddress = frameNumber * pageSize + offset;

    // Output
    printf("Physical Address = %d\n", physicalAddress);

    return 0;
}


// Enter number of pages: 4
// Enter page size: 100
// Enter page table values (Frame numbers):
// Page 0 → Frame: 3
// Page 1 → Frame: 5
// Page 2 → Frame: 2
// Page 3 → Frame: 1

// Enter logical address (page number and offset):
// Page Number (0 to 3): 1
// Offset (0 to 99): 20

// Physical Address = 520
