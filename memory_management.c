#include <stdio.h>
#include <unistd.h>

int main() {
    printf("=== Memory Management Calls ===\n");

    void *init_brk = sbrk(0);
    printf("Initial break: %p\n", init_brk);

    void *new_brk = sbrk(4096);
    if (new_brk == (void *)-1) {
        perror("sbrk");
        return 1;
    }

    printf("After sbrk(4096), break is now: %p\n", sbrk(0));
    return 0;
}

