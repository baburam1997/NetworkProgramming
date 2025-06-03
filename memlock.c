#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main() {
    printf("=== mlock/munlock Example ===\n");

    char *mem = malloc(4096);
    if (mlock(mem, 4096) == 0)
        printf("Memory locked.\n");
    else
        perror("mlock");

    if (munlock(mem, 4096) == 0)
        printf("Memory unlocked.\n");
    else
        perror("munlock");

    free(mem);
    return 0;
}

