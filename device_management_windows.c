#ifdef _WIN32
#include <windows.h>
#include <stdio.h>

int main() {
    printf("=== Device Management (Windows) ===\n");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    WriteConsole(hConsole, "Hello from Console\n", 20, &written, NULL);
    return 0;
}
#else
int main() {
    printf("This program is only for Windows.\n");
    return 0;
}
#endif

